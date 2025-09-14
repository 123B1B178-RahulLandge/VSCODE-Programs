#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

int main()
{
    string ch;
    int word_count=1,letter_count=0,key=0;
    ifstream obj("text.txt");
    while(obj.get('ch'))
    {
        letter_count++;
        if(ch==" ")
        {
            word_count++;
        }
        if(ch=="Hello")
        {
            cout<<"Word Found";

        }
    }
    
}