#include "PictureCache.h"


void PictureCache::Init(double MaxCacheSizeInBytes)
{
	this->MaxSize = MaxCacheSizeInBytes;
	this->Map = HashMap(MaxCacheSizeInBytes);
}

void PictureCache::AddPicture(long SlideID, long XCoord, long YCoord, long DataSize, void* Picture)
{
	PIC current(SlideID, XCoord, YCoord, DataSize);
	this->Map.InsertElement(current, Picture);
}

void PictureCache::GetPicture(long SlideID, long XCoord, long YCoord, void** Picture)
{
	PIC current(SlideID, XCoord, YCoord);
	auto val = this->Map.GetValForKey(current);
	Picture = &val;
}

void PictureCache::DeletePicture(long SlideID, long XCoord, long YCoord)
{
	PIC current(SlideID, XCoord, YCoord);
	this->Map.RemoveElement(current);
}

void PictureCache::DeleteAllBySlideID(long SlideID)
{

}

void PictureCache::DeleteAll()
{
	this->Map.RemoveAll();
}

PictureCache::~PictureCache()
{
	this->Map.RemoveAll();
}


