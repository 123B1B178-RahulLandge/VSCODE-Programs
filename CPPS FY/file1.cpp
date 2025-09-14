#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;


int main()
{
    string word,key;
    int count=0;
    cout<<"Enter Word : ";
    getline(cin,key);
    ifstream obj;
    obj.open("text.txt");
    if(!obj.fail())
    {
            while(obj>>word)
            {
                if(word==key)
                {
                    count++;
                }
            }
    }
    else{
        cout<<"Error Occurred";
    }
    if(count>=1)
    {
        cout<<"Word is present "<<count<<" times"<<endl;
    }
    else
    {
        cout<<"Word is not present";
    }
    obj.close();

}