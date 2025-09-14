//Waiting List Using Queue as Array.

#include<iostream>
using namespace std;
int f=-1,r=-1;
const int size=10;
int token,q[size];


void insert(int t)
{
    if(f==-1 && r==-1)
    {
        r++;
        q[r]=t;
        f=0;
    }
    else if(r < size-1)
    {
        r++;
        q[r]=t;
    }
    else
    {
        cout<<"Waiting List is  Full"<<endl;
    }
}

void delete_q()
{
    if(f==-1 || f>r)
    {
        cout<<"No Waitings :("<<endl;
    }
    else if(f<=r)
    {
        int k=q[f];
        cout<<"Deleted Token "<<q[f]<<endl;
        cout<<"Table No "<<f+1<<" is now free."<<endl;
        f++; 
    }
}

void display()
{
    cout<<"Waiting List"<<endl;
    if(f>r)
    {
        cout<<"NO Waiting List :("<<endl;
    }
    else
    {
        for(int i=f;i<=r;i++)
        {
            cout<<"Token No:"<<q[i]<<endl;
        }
    }  
}


int main()
{
    int x,k;

    while(1)
    {
        cout<<"1.Add to waiting List\n2.Seat/remove a person\n3.Waiting List\n4.Exit\n";
        cout<<"Enter Choice: ";
        cin>>k;
        switch (k)
        {
        case 1:cout<<"Enter token no: ";
                cin>>x;
                insert(x);
            break;
        case 2:delete_q();
            break;
        case 3:display();
            break;
        case 4:return 0;
            break;
        default:
            break;
        }
    }
           
    return 0;
}