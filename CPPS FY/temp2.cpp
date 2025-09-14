#include<iostream>
using namespace std;

class A
{
    private:
    float a;
    public:
    A()
    {
        a=0;
    }
    void getdata()
    {
        cout<<"Enter value of a:";
        cin>>a;
    }
    friend A operator +(A x,A y);
    void display()
    {
        cout<<"Value of a is:"<<a;
    }
};
A operator +(A x,A y)
    {
        A temp;
        temp.a=x.a + y.a;
        return temp;
    }
int main()
{
    A p,q,sum;
    p.getdata();
    q.getdata();
    sum=p+q;
    sum.display();
    return 0;
}