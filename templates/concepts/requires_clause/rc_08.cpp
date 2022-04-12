template <typename T>
requires requires(T x)		//valid syntax
{
    x + x;
}
