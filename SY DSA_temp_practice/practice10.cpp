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
    public:
    int top=-1;
    node *head;
    LL()
    {
        head = 0;
    }

    void push(int d)
    {
        top++;
        node *nn=new node(d);
        if(head == NULL)
        {
            head = nn;
            return;
        }
        else
        {
            node *temp=new node();
            temp=head;
            while(temp->next !=NULL)
            {
                temp=temp->next;
            }
            temp->next=nn;
        }
    }

    void pop()
    {
        if(head == NULL)
        {
            cout<<"Stack Underflow"<<endl;
        }
        else
        {
            node *temp=new node();
            node *temp1=new node();
            temp=head;
            while(temp->next !=NULL)
            {
                temp1=temp;
                temp=temp->next;
            }
            cout<<"Deleted Element: "<<temp->data<<endl;
            temp1->next = NULL;
        }
    }

    void display()
    {
        if(head==NULL)
        {
            cout<<"Stack Underflow"<<endl;
        }
        else
        {
            cout<<"Stack Content: ";
            node *temp=new node();
            temp=head;
            while(temp->next !=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<temp->data;
        }
        cout<<'\n';
    }

    void display_reverse()
    {
        int arr[top],i=0;
        if(head==NULL)
        {
            cout<<"Stack Underflow"<<endl;
        }
        else
        {
            cout<<"Reversed Stack Content: ";
            node *temp=new node();
            temp=head;
            while(temp->next !=NULL && i<=top)
            {
                arr[i]=temp->data;
                temp=temp->next;
                i++;
            }
            arr[i]=temp->data;
            for(int j=i;j>=0;j--)
            {
                cout<<arr[j]<<" ";
            }
        }
        cout<<'\n';
    }

    void search(int n)
    {
        int count =0;
        if(head==NULL)
        {
            cout<<"Stack Underflow"<<endl;
        }
        else
        {
            node *temp = new node();
            temp=head;
            while(temp != NULL)
           {
             if(temp->data == n)
             {
                cout<<"Element Found."<<endl;
                count++;
             }
             temp=temp->next;
            }
            if(count==0)
            {
                cout<<"Element not found."<<endl;
            }
        }
        
    }
};

int main()
{
    LL l;
   int m,x;
    string ch;
    do
    {
        cout<<"\n1.To add element \n2.To delete element \n3.To display stack \n4.To search element \n5.To display reverse."<<endl;
        cout<<"Enter respective no. to proceed: ";
        cin>>m;
        switch(m)
        {
            case 1:cout<<"Enter element to add: ";
                    cin>>x;
                    l.push(x);
                    cout<<"Element Added.";
                    break;
            case 2: l.pop();
                    break;
            case 3: l.display();
                    break;
            case 4: cout<<"Enter element to search: ";
                    cin>>x;
                    l.search(x);
                    break;
            case 5: l.display_reverse();
                    break;
            default: cout<<"To continue enter y: ";
                    cin>>ch;
        }
        cout<<"To continue enter y: ";
        cin>>ch;
    } while (ch=="y" || ch=="y");
    return 0;
}