//constructor with T* param is explicit

#include <memory>
#include "triple.h"

std::unique_ptr<Triple> foo()
{
	return new Triple; //gecersiz
}
