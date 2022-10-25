/*   header.h   */

void overloaded(int);
inline void func() 
{
    //burada çağrılan  paremetresi int olan overloaded fonksiyonu
    overloaded('*');  
}

/*  foo.cpp   */
#include "header.h"

void foo()
{
    func();  // çağrılan overloaded => void overloaded(int)
}

/*   bar.cpp   */
void overloaded(char); //başka bir başlık dosyasından gelmiş olabilir

#include "header.h"

void bar()
{
    func(); // çağrılan overloaded işlevi => void overloaded(char)
}


/*
    overloaded ismi farklı çeviri birimlerinde (translation unit)  farklı varlıklara ilişkin olduğundan ODR ihlal edilmiş oluyor.
*/
