#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    char ch;
    ifstream obj("text.txt");
    ofstream obj1("destination.txt");
    while (obj)    
    {
           ch=obj.get();
           cout<<ch;
           obj1.put(ch);
    }
    obj1.close();
    obj.close();
    
    return 0;
}