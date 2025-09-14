#include<iostream>
#include<stack>
using namespace std;

class queue
{
    stack <int> s1;
    stack <int> s2;
    int m;
    public:
    void enqueue(int d)
    {
        s1.push(d);
    }
    
    void  dequeue()
    {
        while(!s1.empty())
        {
            m=s1.top();
            s1.pop();
            s2.push(m);
        }

       s2.pop();

        while(!s2.empty())
        {
            m=s2.top();
            s2.pop();
            s1.push(m);
        }
    }
    
    void display()
    {
         while (!s1.empty()) {
            cout << s1.top() <<" ";
            s1.pop();
        }
    }
};

int main()
{
    queue a;

    a.enqueue(3);
    a.enqueue(1);
    a.enqueue(4);
    a.enqueue(8);
    a.enqueue(2);
    a.enqueue(12);

    a.dequeue();
    a.dequeue();
    a.dequeue();

    a.display();

    return 0;
}