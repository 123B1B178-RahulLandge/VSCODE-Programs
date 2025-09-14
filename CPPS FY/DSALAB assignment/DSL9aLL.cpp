//Waiting list using queue as Linked List.

#include<iostream>
using namespace std;

class node
{
    public:
    string name;
    node *next;

    node()
    {
        name="none";
        next = NULL;
    }

    node(string n)
    {
        name = n;
        next = NULL;
    }
};

class LL
{
    public:
    node *f;
    node *r;

    LL()
    {
        f=0;
        r=0;
    }

    void insert(string k)
    {
        node *nn=new node(k);
        if(f==NULL && r==NULL)
        {
            f=r=nn;
        }
        else
        {
            node *temp = new node();
            temp=f;
            while(temp->next!=NULL)
            {
                temp=temp->next;
            }
            temp->next=nn;
            r=nn;
        }
    }

    void display()
    {
        if( f == NULL)
        {
            cout<<"No Waitings."<<endl;
        }
        else
        {
            cout<<"Waiting List: "<<endl;
            node *temp=new node();
            temp=f;
            while(temp!= r)
            {
                cout<<temp->name<<endl;
                temp=temp->next;
            }
            cout<<temp->name<<endl;            
        }
    }

    void del()
    {
        if(f==NULL)
        {
            cout<<"No Waiting."<<endl;
        }
        else if(f==r)
        {
            string a=f->name;
            cout<<"Seated Person: "<<a<<endl;
            f=NULL;
            r=NULL;
        }
        else
        {
            string a=f->name;
            cout<<"Seated Person: "<<a<<endl;
            f=f->next;
        }
    }
};


int main()
{
    LL l;
    int k;
    string x;

    while(1)
    {
        cout<<"1.Add to waiting List\n2.Seat/remove a person\n3.Waiting List\n4.Exit\n";
        cout<<"Enter Choice: ";
        cin>>k;
        switch (k)
        {
        case 1:cout<<"Enter Name: ";
                cin>>x;
                l.insert(x);
            break;
        case 2:l.del();
            break;
        case 3:l.display();
            break;
        case 4:return 0;
            break;
        default:
            break;
        }
    }

    return 0;
}