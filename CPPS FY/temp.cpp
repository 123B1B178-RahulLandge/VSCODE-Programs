#include<iostream>
using namespace std;

class A
{
    protected:
    int a,b;
    public:
    virtual void getdata()
    {
        cout<<"Enter a:";
        cin>>a;
        cout<<"Enter b:";
        cin>>b;
    }
};

class B:public A
{
    private:
    string c;
    public:
    void getdata();
};

void B::getdata()
{
    cout<<"Enter name:";
    cin>>c;
    cout<<"Enter a:";
    cin>>a;
    cout<<"Enter b:";
    cin>>b;
}

int main()
{
    A a;
    B b;
    a.getdata();
    b.getdata();
}