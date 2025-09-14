#include<iostream>
using namespace std;

template<class T>
class A
{
    private:
    T x,y;
    public:
    A(T a,T b)
{
    x=a;
    y=b;

}
void show()
{
    cout<<x+y<<"\n";
}
};

int main()
{
    A<double>s(5.8,8.2);
    A<int>s2(6,2);
    s.show();
    s2.show();
    return 0;
}