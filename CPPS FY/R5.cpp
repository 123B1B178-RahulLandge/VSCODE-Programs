#include<iostream>
#include<fstream>
using namespace std;

class A
{
    private:
    string name;
    int age;
    float salary;
    public:
    void getdata()
    {
        cout<<"Name:"<<name<<endl;
        cout<<"Age:"<<age<<endl;
        cout<<"salary:"<<salary<<endl;
    }
    void putdata()
    {
        cout<<"Enter name:";
        cin>>name;
        cout<<"Enter age:";
        cin>>age;
        cout<<"Enter salary:";
        cin>>salary;
    }
};

int main()
{
    A obj1;
    ofstream fout("text.txt");
    obj1.putdata();
    fout.write((char *) &obj1,sizeof(obj1));
    fout.close();
    A obj2;
    ifstream fin("text.txt");
    fin.read((char *) &obj2,sizeof(obj2));
    obj2.getdata();
    fin.close();
    return 0;
}