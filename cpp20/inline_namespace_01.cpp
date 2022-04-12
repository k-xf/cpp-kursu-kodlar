namespace A::B::inline C    //valid in C++20 invalid in C++17
{ 
    void func();
}

int main()
{
    A::B::func();
}
