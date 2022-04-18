/*
  global const nesneler varsayılan şekilde iç bağlantıda (internal linkage)
*/

// a.h
#pragma once

const int x = 10;
void foo();

//-------------------------------------------------------------------------

//a.cpp
#include "a.h"
#include <iostream>

void foo()
{
	std::cout << "&x = " << &x << "\n";
}

//-------------------------------------------------------------------------

//main.cpp
#include <iostream>
#include "a.h"

int main()
{
	std::cout << "&x = " << &x << "\n";

	foo();
}
