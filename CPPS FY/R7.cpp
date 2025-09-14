#include <iostream>
using namespace std;
class Test {
    private:
    int a,b,c;
    public: 
    Test()
    {
        a=0;
        b=0;
        c=0;
    }
    friend istream operator >>(istream &input,Test &t);
    friend ostream operator <<(ostream &output,Test &t);
};
istream operator >>(istream &input,Test &t)
{
    cout<<"Enter values";
    input>>t.a;
    input>>t.b;
    input>>t.c;
}
ostream operator << (ostream &output,Test &t)
{
    output<<t.a;
    output<<t.b;
    output<<t.c;
}
main()
{
Test t1;
cin >> t1;
cout << t1;
return 0;
}