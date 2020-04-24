# 3DHisteq_homework

A PictureCache osztály tartalmazza a feladatkiírásban szereplő függvényeket.
A HashMap osztály segítségével tárolom el a képeket: a kulcs egy PIC struct.
Amikor betelt a cache, de hozzá kell adni újabb elemet, FIFO alapján kitörlök egy elemet a hozzáadás előtt.
Ebben segít a Queue osztály, melnek van egy array változója, amely a HashMap kulcsait tartalmazza. 
A 3DHisteq_homework.cpp-ben van a main(). A file alján találhatóak a felhasznált források.
