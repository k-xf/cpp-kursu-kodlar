//pack expansion as template argument lists

#include <tuple>

template<class A, class B, class... TS> 
void func(A arg1, B arg2, TS ...pack)
{
    std::tuple<A, B, TS...> t1;  // std::tuple<A, B, E1, E2, E3> 
    std::tuple<TS..., A, B> t2;  // std::tuple<E1,E2,E3,A,B> 
    std::tuple<A, TS..., B> t3;  // std::tuple<A,E1,E2,E3,B> 
    //...
}
