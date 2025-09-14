//Checkout System for superMarket.

#include<iostream>
using namespace std;

class node
{
    public:
    int token;
    node *next;

    node()
    {
        token=0;
        next = NULL;
    }

    node(int d)
    {
        token = d;
        next = NULL;
    }
};

class LL
{
    public:
    node *f;
    node * r;

    LL()
    {
        f=0;
        r=0;
    }

    void insert(int k)
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
            while(temp!=r)
            {
                temp=temp->next;
            }
            temp->next=nn;
            nn->next = f;
            r=nn;
        }
    }

    void del()
    {
        if(f==NULL)
        {
            cout<<"No customer to checkout"<<endl;
        }
        else if(f==r)
        {
            int a=f->token;
            cout<<"Checked-out Person: "<<a<<endl;
            f=NULL;
            r=NULL;
        }
        else
        {
            int a=f->token;
            cout<<"Checkout Person: "<<a<<endl;
            f=f->next;
        }
    }

    void display()
    {
        if( f == NULL)
        {
            cout<<"No customer."<<endl;
        }
        else
        {
            cout<<"Customers: "<<endl;
            node *temp = new node();
            temp=f;
            while(temp!= r)
            {
                cout<<temp->token<<endl;
                temp=temp->next;
            }
            cout<<temp->token<<endl;            
        }
    }

    void close_counter()
    {
        if(f==NULL)
        {
            cout<<"Close the counter."<<endl;
        }
        else
        {
            cout<<"Don't close the counter (Custemer's present).";
        }
    }
};

int main()
{
    LL l;
    int k,x;

    while(1)
    {
        cout<<"1.Customer Arrival\n2.Customer checkout\n3.Display Customers\n4.Close checkout counter\n5.Exit\n";
        cout<<"Enter Choice: ";
        cin>>k;
        switch (k)
        {
        case 1:cout<<"Enter token of customer: ";
                cin>>x;
                l.insert(x);
            break;
        case 2:l.del();
            break;
        case 3:l.display();
            break;
        case 4:l.close_counter();
            break;
        case 5:return 0;
            break;
        default:
            break;
        }
    }

    return 0;
}