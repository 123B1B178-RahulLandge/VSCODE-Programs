#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    string line;
    ifstream obj("text.txt");
    ofstream obj1("destination.txt")    ;
    while(obj && obj1)
    {
        while(getline(obj,line))
        {
            obj1<<line;
            obj1<<'\n';
        }
    }
    obj1.close();
    obj.close();
    return 0;
}