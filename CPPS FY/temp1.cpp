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
    A operator +(A x)
    {
        A temp;
        temp.a=this->a+x.a;
        return temp;
    }
    void display()
    {
        cout<<"Value of a is:"<<a;
    }
};

int main()
{
    A p,q,sum;
    p.getdata();
    q.getdata();
    sum=p+q;
    sum.display();
    return 0;
}