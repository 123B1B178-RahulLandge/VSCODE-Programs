#include<iostream>
using namespace std;

class A
{
    private:
    int a;
    public:
    A()
    {
        a=0;
    }
    void getdata()
    {
        cout<<"Enter the value of a:";
        cin>>a;
    }
    friend A operator *(A m,A n);
    void display()
    {
        cout<<"The value of is"<<a;
    }
};
A operator *(A m,A n)
    {
        A temp;
        temp.a=n.a*m.a;
        return temp;
    }
int main()
{
    A x,y,sum;
    x.getdata();
    y.getdata();
    sum=x*y;
    sum.display();
    return 0;
}