#include<iostream>
using namespace std;

template<class T>
T sum(T a,T b)
{
    T temp;
    temp=a+b;
    return temp;
}
int main()
{
    int a=5,b=6;
    cout<<sum(5,6)<<endl;
    float x=6.7,y=9.8;
    cout<<sum(x,y);
    return 0;
}