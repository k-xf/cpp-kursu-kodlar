enum MyInt : char { }; 
MyInt i1{ 42 }; // C++17'de gecerli (daha once gecersizdi) 
//MyInt i2 = 42; // gecersiz
//MyInt i3(42); // gecersiz
//MyInt i4 = { 42 }; // gecersiz

enum class Weekday { mon, tue, wed, thu, fri, sat, sun }; 
Weekday s1{0}; // C++17'de gecerli (daha once gecersizdi) 
//Weekday s2 = 0; // gecersiz
//Weekday s3(0); // gecersiz
//Weekday s4 = {0}; // gecersiz

enum class Weekday : char { mon, tue, wed, thu, fri, sat, sun };
Weekday s1{0}; // C++17'de gecerli (daha once gecersizdi) 
//Weekday s2 = 0; // gecersiz
// Weekday s4 = {0}; // gecersiz

enum Flag { bit1 = 1, bit2 = 2, bit3 = 4 };
//Flag f1{ 0 }; // halen gecersiz (underlying type beli degil=

enum MyInt : char { }; 
//MyInt i5{ 42.2 }; //gecersiz (daraltici donusum)
