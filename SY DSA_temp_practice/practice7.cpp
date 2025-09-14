#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;
    public:
    node() 
    {
        data=0;
        next=NULL;
    }
    node(int d)
    {
        data=d;
        next=NULL;
    }
};

class LL
{
    private:
    node *head;

    public:
    void create(int d)
    {
        node *nn=new node(d);
        head=nn;
    }

    LL()
    {
        head=0;
    }
    void insert_start(int d)
    {
        node *nn=new node(d);
        if(head==NULL)
        {
            cout<<"List is empty.";
            head=nn;
            return;
        }
        else
        {
            nn->next=head;
            head=nn;
        }
    }

    void insert_end(int d)
    {
        node *t = new node();
        t=head;
        while(t->next != NULL)
        {
            t=t->next;
        }
        node *nn= new node(d);
        t->next=nn;
    }

    void insert_mid(int d,int key)
    {
        node *nn=new node(d);
        node *temp=new node();
        temp=head;
        if(temp->next ==NULL)
        {
            cout<<"LL has no member ahead.";
        }
        else
        {
            while(temp->data != key)
            {
                temp=temp->next;
            }
            nn->next=temp->next;
            temp->next= nn;
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
   int n,m,key;
   string ch;
   LL l;
   do
   {
       cout<<"\n1.To Create LL \n2.Insert data at start \n3.Insert data at the end \n4.To print LL \n5.To add data in between\n";
        cin>>n;
        switch(n)
        {
            case 1:cout<<"Enter data : ";
                    cin>>m;
                    l.create(m);
                    break;
            case 2:cout<<"Enter data : ";
                    cin>>m;
                    l.insert_start(m);
                    break;
            case 3:cout<<"Enter data : ";
                    cin>>m;
                    l.insert_end(m);
                    break;
            case 4:l.print();
                    break;
            case 5:cout<<"Enter the value to add node after";
                    cin>>key;
                    cout<<"Enter data : ";
                    cin>>m;
                    l.insert_mid(m,key);
                    break;
            default : break;
        }
        cout<<"\nEnter y to continue : ";
        cin>>ch;
   }while(ch == "y"||ch == "Y");

   return 0;
    
}