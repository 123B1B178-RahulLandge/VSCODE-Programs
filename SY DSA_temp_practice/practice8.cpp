#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    node *prev;
    public:
    node() 
    {
        data=0;
        next = NULL;
        prev = NULL;
    }
    node(int d)
    {
        data=d;
        next = NULL;
        prev = NULL;
    }
};

class dLL
{
    private:
    node *head;

    public:

    dLL()
    {
        head=0;
    }

    void insert_end(int d)
    {
        node *nn =new node(d);
        if(head==NULL)
        {
            head = nn;
            return;
        }
        else{
            node *temp = new node();
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = nn;
            nn->prev = temp;
        }
    }
    void print()
    {
        cout<<"Displaying LL:"<<endl;
        node *temp=new node();
        temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
};

int main()
{
    dLL l;
    l.insert_end(5);
    cout<<"hello";
    l.print();
    l.insert_end(7);
    l.print();
    l.insert_end(8);
    l.print();
    return 0;
}