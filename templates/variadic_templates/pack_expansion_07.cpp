template<typename... Types, int... N> 
void func(Types(&...args)[N]) 
{
    //...
}

int main()
{
    int a[5]{};
    int b[10]{};
    int c[20]{};
    double d[30]{};

    func(a, b, c, d);
}
