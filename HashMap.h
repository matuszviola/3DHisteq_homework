#pragma once

struct PIC
{
	unsigned int ID;
	long XCoord;
	long YCoord;
	long SizeInBytes;
	bool operator== (const PIC& Other) const;

	PIC();
	PIC(unsigned int _ID, long _X, long _Y);
	PIC(unsigned int _ID, long _X, long _Y, long _SizeInBytes);
};


// Ha betelik a cache map, ennek segítségével határozom meg, melyik elemét töröljem, hogy legyen hely.
// Elemei megegyeznek a map kulcsaival.
class Queue
{
public:
	int Front;
	int Rear;
	int MaxLength;
	int CurrentLength;
	PIC* FIFO;

	Queue();
	Queue(int _maxSize);
	~Queue();
	void PushToRear(PIC p);
	void PopFromFront();
};


class HashNode
{
private:
	PIC Key;
	void* Value;

public:
	HashNode(PIC _key, void* _value);
	PIC GetKey();
	void* GetValue();
};

class HashMap
{
private:
	HashNode **Table;
	long TableLength;
	long SizeInBytes;
	long MaxSizeInBytes;
	Queue FifoQueue;

	int CalcHash(PIC currentKey);
	void CreateTable();

public:
	void* GetValForKey(PIC key);
	void InsertElement(PIC key, void* value);
	void RemoveElement(PIC key);
	void RemoveAll();
	HashMap();
	HashMap(long _maxSizeInBytes);
	HashMap(int _size, long _maxSizeInBytes);
	~HashMap();
};

