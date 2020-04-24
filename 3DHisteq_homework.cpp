// 3DHisteq_homework.cpp by KMV
//

#include <iostream>
#include "PictureCache.h"


int main()
{
    PictureCache myPicCache;
    void* pic1;
    void* pic2;
    void* pic3;

    myPicCache.Init(1048);

    myPicCache.AddPicture(1, 200, 300, 32, pic1);
    myPicCache.AddPicture(2, 200, 300, 128, pic2);
    myPicCache.AddPicture(3, 200, 300, 256, pic3);

    myPicCache.GetPicture(2, 200, 300, &pic2);

    myPicCache.DeletePicture(1, 200, 300);
}


/// Felhasznált források:
//https://bhrigu.me/blog/2017/01/22/lru-cache-c-plus-plus-implementation/
//https://www.algolist.net/Data_structures/Hash_table/Simple_example
//https://medium.com/@aozturk/simple-hash-map-hash-table-implementation-in-c-931965904250
//https://stackoverflow.com/questions/21289851/fifo-map-in-c
//https://www.techiedelight.com/queue-implementation-cpp/
