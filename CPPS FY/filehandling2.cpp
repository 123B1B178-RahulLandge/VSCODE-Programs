#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    ifstream obj;
    char ch;
    obj.open("text.txt");
    while(obj)
    {
        ch=obj.get();
        cout<<ch;
        cout<<": Position of get pointer"<<obj.tellg()<<endl;
    }
    obj.close();
    return 0;
}