#include<iostream>
#include<queue>
using namespace std;

class stack
{
    queue<int>q1;
    queue<int>q2;
    int m;

    public:

    void spush(int d)
    {
        q1.push(d);
        while(!q2.empty())
        {
            q1.push(q2.front());
            q2.pop();
        }
        swap(q1,q2);
    }

    void spop()
    {
       q2.pop();
    }

    void display()
    {
        cout<<"displaying queue : ";
        while(!q2.empty())
        {
            cout<<q2.front()<<" ";
            q2.pop();
        }
    }
};

int main()
{
    stack a;
    a.spush(2);
    a.spush(1);
    a.spush(8);
    a.spush(6);
    a.spush(9);


    a.spop();
    a.spop();

    a.display();

    return 0;
}