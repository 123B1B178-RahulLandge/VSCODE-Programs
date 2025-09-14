#include<iostream>
using namespace std;

class A
{
    private:
    int top=-1;
    float age;
    string name;
    public:
    void push();
    void pop();
    void display();
}a[10];
void A::push()
    {
        if(top>=10)
        {
            cout<<"stack is full!!";
        }
        else{
            top++;
            cout<<"Enter age";
            cin>>a[top].age;
            cout<<"Enter name:";
            cin>>a[top].name;
        }
    }

    void A:: pop()
    {
        if(top==-1)
        {
            cout<<"stack is empty";
        }
        else{
            top--;
        }
    }

    void A:: display()
    {
        if(top==-1)
        {
            cout<<"stack is empty";
        }
        else{
            for(int i=0;i<=top;i++)
            {
                cout<<a[i].age<<"\t";
                cout<<a[i].name<<endl;
            }
        }
    }
int main()
{
    int n,m;
    A b;
    cout<<"POP=1 \n PUSH =2\n display=3\n Exit=4";
    cin>>n;
        switch(n)
        {
            case 1:a[0].pop();
                    break;
            case 2:a[0].push();
            break;
            case 3:a[02].display();
                    break;
            default:cout<<"invalid";
        }
    cout<<"Enter";
    cin>>m;
    if(m==0)
    {
        main();
    }
    else{
        return 0;
    }
    

}