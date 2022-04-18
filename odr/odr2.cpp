/* a.h    */

#pragma once
#include <iostream>
void func() 
{
    std::cout << "func"; 
}

void foo();


/*   a.cpp   */
#include "a.h"
void foo() 
{
    std::cout << "foo";
}

/* main.cpp */

#include "a.h"
int main() 
{
    func();
    foo();
}

/* func işlevinin tanımı iki translation unit içinde de yer alıyor. ODR ihlal ediliyor. */
