#include<iostream>
using namespace std;

class node
{
    public:
    string job;
    int pri;
    node *next;
    node *prev;

    node()
    {
        job="none";
        pri=0;
        next=NULL;
        prev = NULL;
    }

    node(string j,int p)
    {
        job=j;
        pri=p;
        next=NULL;
        prev = NULL;
    }

};

class DQ
{
    public:
    node *f,*r;

    DQ()
    {
        f=0;
        r=0;
    }

    void insert_rear(string j,int p)
    {
        node* nn = new node(j,p);
        if (f==NULL) {
            f=nn;
            r=nn;
        } 
        else if(f->pri < p)
        {
            nn->next = f;
            f = nn;
        }
        else
        {
            node* temp = f;
            node* temp1 =f;
            while (temp->next !=NULL && temp->next->pri >= p) 
            {
                temp = temp->next;
            }
            nn->next = temp->next;
            temp->next = nn;
            
            while(temp1 != NULL)
            {
                temp1= temp1->next;
            }
            r=temp1;
        }
    }

    void display()
    {
        if( f == NULL)
        {
            cout<<"No job Scheduled."<<endl;
        }
        else
        {
            cout<<"Job's Pending: "<<endl;
            node *temp = new node();
            temp=f;
            while(temp->next != NULL)
            {
                cout<<temp->job<<endl;
                temp=temp->next;
            }
            cout<<temp->job<<endl;            
        }
    }

    void pop()
    {
        if(f==NULL)
        {
            cout<<"No job scheduled."<<endl;
        }
        else if (f==r)
        {
            node *temp = f;
            cout<<"Completed Job: ";
            cout<<temp->job;
            f=NULL;
            r=NULL;
        }
        else
        {
            node *temp = f;
            cout<<"Completed Job: ";
            cout<<temp->job;
            f=f->next;
        }
    }

    void search(string key)
    {
        if(f==NULL)
        {
            cout<<"No Job's scheduled to search."<<endl;
        }
        else{ 
            int count=0;
            node *temp=new node();
            temp=f;

            while(temp!=NULL)
            {
                if(temp->job == key)
                {
                    cout<<"Job Found.";
                    count++;
                    break;
                }
                temp=temp->next;
            }
            if(count==0)
            {
                cout<<"No such Task Found.";
            }
        }
    }
};

int main()
{
    DQ d;
    int m,p;
    string a,key;
    do
    {
        cout<<"\n1.To add Job \n2.To complete the job \n3.To display pending job's \n4.Search a job \n5.Exit"<<endl;
        cout<<"Enter respective no. to proceed: ";
        cin>>m;
        switch(m)
        {
            case 1:cout<<"Enter job name: ";
                    cin>>a;
                    cout<<"Enter it's priority: ";
                    cin>>p;
                    d.insert_rear(a,p);
                    cout<<"Job Scheduled."<<endl;
                    break;
            case 2: d.pop();
                    break;
            case 3: d.display();
                    break;
            case 4:cout<<"Enter Job name to search: ";
                    cin>>key;
                    d.search(key);
                    break;
            case 5:return 0;
                    break;
            default: break;
        }
    } while (1);

    return 0;
}
