#include "HashMap.h"

bool PIC::operator==(const PIC& other) const
{
	if ((this->ID == other.ID) && (this->XCoord == other.XCoord) && (this->YCoord == other.YCoord))
	{
		return true;
	}
	return false;
}

PIC::PIC()
{
	this->ID = -1;
	this->XCoord = -1;
	this->YCoord = -1;
	this->SizeInBytes = 0;
}

PIC::PIC(unsigned int _ID, long _X, long _Y)
{
	this->ID = _ID;
	this->XCoord = _X;
	this->YCoord = _Y;
	this->SizeInBytes = 0;
}

PIC::PIC(unsigned int _ID, long _X, long _Y, long _SizeInBytes)
{
	this->ID = _ID;
	this->XCoord = _X;
	this->YCoord = _Y;
	this->SizeInBytes = _SizeInBytes;
}




HashNode::HashNode(PIC _key, void* _value)
{
	this->Key = _key;
	this->Value = _value;
}

PIC HashNode::GetKey()
{
	return this->Key;
}

void* HashNode::GetValue()
{
	return this->Value;
}




int HashMap::CalcHash(PIC currentKey)
{
	int hashVal = (currentKey.ID + currentKey.XCoord + currentKey.YCoord) % this->TableLength;
	return hashVal;
}

void HashMap::CreateTable()
{
	this->Table = new HashNode * [this->TableLength];
	for (int i = 0;i < this->TableLength;i++)
	{
		this->Table[i] = 0;
	}
}

void* HashMap::GetValForKey(PIC key)
{
	int hash = this->CalcHash(key);
	if (this->Table[hash] == 0)
	{
		return nullptr;
	}
	else
	{
		return this->Table[hash]->GetValue();
	}
}

void HashMap::InsertElement(PIC key, void* value)
{
	if ((this->SizeInBytes + key.SizeInBytes) > this->MaxSizeInBytes)
	{
		PIC toBeDeletedFromMap = this->FifoQueue.FIFO[this->FifoQueue.Front];
		this->RemoveElement(toBeDeletedFromMap);
		this->SizeInBytes -= toBeDeletedFromMap.SizeInBytes;
		this->FifoQueue.PopFromFront();
	}

	int hash = this->CalcHash(key);
	if (this->Table[hash] != 0)
	{
		delete this->Table[hash];
	}
	this->Table[hash] = new HashNode(key, value);
	this->SizeInBytes += key.SizeInBytes;
	this->FifoQueue.PushToRear(key);
}

void HashMap::RemoveElement(PIC key)
{
	int hash = this->CalcHash(key);
	if (this->Table[hash] != 0)
	{
		this->SizeInBytes -= key.SizeInBytes;
		delete this->Table[hash];

		for (int i = this->FifoQueue.Rear;i < this->FifoQueue.Front;i++)
		{
			if (this->FifoQueue.FIFO[i] == key)
			{
				this->FifoQueue.FIFO[i] = PIC();
			}
		}
	}
}

void HashMap::RemoveAll()
{
	for (int i = 0;i < this->TableLength;i++)
	{
		this->Table[i] = 0;
	}
	//delete[] this->Table;

	delete this->FifoQueue.FIFO;
}

HashMap::HashMap()
{
	this->TableLength = 256;
	this->MaxSizeInBytes = 1048;
	this->CreateTable();
}

HashMap::HashMap(long _maxSizeInBytes)
{
	this->TableLength = 256;
	this->MaxSizeInBytes = _maxSizeInBytes;
	this->FifoQueue = Queue(this->TableLength);
	this->CreateTable();
}

HashMap::HashMap(int _size, long _maxSizeInBytes)
{
	this->TableLength = _size;
	this->MaxSizeInBytes = _maxSizeInBytes;
	this->CreateTable();
}

HashMap::~HashMap()
{
	for (int i = 0;i < this->TableLength;i++)
	{
		this->Table[i] = 0;
	}
	delete[] this->Table;
}





Queue::Queue()
{
	this->Front = 0;
	this->Rear = -1;
	this->MaxLength = 10;
	this->CurrentLength = 0;
	this->FIFO = new PIC[10];
}

Queue::Queue(int _maxSize)
{
	this->Front = 0;
	this->Rear = -1;
	this->MaxLength = _maxSize;
	this->CurrentLength = 0;
	this->FIFO = new PIC[_maxSize];
}

Queue::~Queue()
{
	delete this->FIFO;
}

void Queue::PushToRear(PIC p)
{
	if (this->CurrentLength < this->MaxLength)
	{
		this->Rear = (this->Rear + 1) % this->MaxLength;
		this->FIFO[this->Rear] = p;
		this->CurrentLength++;
	}
}

void Queue::PopFromFront()
{
	if (this->CurrentLength > 0)
	{
		this->Front = (this->Front + 1) % this->MaxLength;
		this->CurrentLength--;
	}
}
