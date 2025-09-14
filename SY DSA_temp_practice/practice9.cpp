#include<iostream>
using namespace std;
int top=-1;
int stack[10];

void s_push(int n)
{
    if(top>=n)
    {
        cout<<"Stack Overflow."<<endl;
    }
    else
    {
        top++;
        stack[top]=n;
    }
}

void s_pop()
{
    if(top==-1)
    {
        cout<<"Stack Underflow."<<endl;
    }
    else
    {
        int x = stack[top];
        top--;
        cout<<"Deleted Element: "<<x<<endl;
    }
}

void s_peek()
{
    if(top==-1)
    {
        cout<<"Stack Underflow."<<endl;
    }
    else
    {
        cout<<"Peek Element: "<<stack[top];
    }
}

void s_display()
{
    if(top==-1)
    {
        cout<<"Stack Underflow."<<endl;
    }
    else
    {
        for(int i=0;i<=top;i++)
        {
            cout<<stack[i]<<" ";
        }
        cout<<'\n';
    }
}

void s_search(int n)
{
    if(top==-1)
    {
        cout<<"Stack Underflow."<<endl;
    }
    else
    {
        int count = 0;
        for(int i=0;i<=top;i++)
        {
            if(stack[i]==n)
            {
                cout<<"Element Found at location: "<<i+1<<endl;
                count++;
            }
        }
        if(count == 0)
        {
            cout<<"Element not found."<<endl;
        }
        cout<<'\n';
    }
}
int main()
{
    int m,x;
    string ch;
    do
    {
        cout<<"\n1.To add element \n2.To delete element \n3.To display stack \n4.To search element."<<endl;
        cout<<"Enter respective no. to proceed: ";
        cin>>m;
        switch(m)
        {
            case 1:cout<<"Enter element to add: ";
                    cin>>x;
                    s_push(x);
                    cout<<"Element Added.";
                    break;
            case 2: s_pop();
                    break;
            case 3: s_display();
                    break;
            case 4: cout<<"Enter element to search: ";
                    cin>>x;
                    s_search(x);
                    break;
            default: cout<<"To continue enter y: ";
                    cin>>ch;
        }
        cout<<"To continue enter y: ";
        cin>>ch;
    } while (ch=="y" || ch=="y");
    return 0;
}