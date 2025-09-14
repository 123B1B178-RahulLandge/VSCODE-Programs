#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    string ch="MY nAJJNC DNKDIWD";
    ofstream obj;
    obj.open("text.txt",ios::app);
    obj<<ch;
    return 0;
}