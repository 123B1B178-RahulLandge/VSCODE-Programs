#include<iostream>
#include<fstream>
using namespace std;

int main()
{
    string word,key;
    int count=0;
    ifstream obj("text.txt",ios::in);
    cout<<"Enter A word to search in file:";
    cin>>key;
    while(obj)
    {
       while(obj>>word)
        {
            if(word==key)
            {
                count++;
            }
        } 
    }
    if(count>0)
    {
        cout<<"The word found"<<endl;
        cout<<"No of times words present:"<<count;
    }
    else{
        cout<<"The word not found";
    }
    obj.close();
    return 0;
}