#pragma once
#include "HashMap.h"

class PictureCache
{
private:
	HashMap Map;
	double MaxSize;

public:
	void Init(double MaxCacheSizeInBytes);
	void Done();
	void AddPicture(long SlideID, long XCoord, long YCoord, long DataSize, void* Picture);
	void GetPicture(long SlideID, long XCoord, long YCoord, void** Picture);
	void DeletePicture(long SlideID, long XCoord, long YCoord);
	void DeleteAllBySlideID(long SlideID);
	void DeleteAll();

	~PictureCache();
};