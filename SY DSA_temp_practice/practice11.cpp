#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;

    node()
    {
        data=0;
        next = NULL;
    }

    node(int d)
    {
        data=d;
        next= NULL;
    }
};

class LL
{
    public:
    node *head;

    LL()
    {
        head=0;
    }

    void push(int d)
    {
        node *nn=new node(d);
        if(head == NULL)
        {
            head = nn;
            return;
        }
        else
        {
            nn->next = head;
            head = nn;
        } 
    }
        void show()
        {
            node *temp=new node();
            temp = head;
            while(temp->next != NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<temp->data;
            cout<<"\n";
        }
        
        void pop()
        {
            if(head == NULL)
            {
                node();
            }
            else
            {
                node *temp = new node();
                temp = head;
                head=head->next;
                delete temp;
            }
        }
};

int main()
{
    LL l;
    l.push(5);
    l.push(7);
    l.push(8);
    l.show();
    l.pop();
    l.show();
    l.pop();
    l.show();
    l.pop();
    l.show();
    cout<<"Hello";
    l.push(9);
    l.show();
    return 0;
}