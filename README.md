# 3DHisteq_homework

A PictureCache osztály tartalmazza a feladatkiírásban szereplő függvényeket.
A HashMap osztály segítségével tárolom el a képeket: a kulcs egy PIC struct.
Amikor betelt a cache, de hozzá kell adni újabb elemet, FIFO alapján kitörtök egy elemet a hozzáadás előtt.
Ebben segít a Queue osztály, melnek van egy array változója, amely a HashMap kulcsait tartalmazza. 
