#include<iostream>
using namespace std;

class node{
    public:
    int token;
    node *next;

    node(){
        token=0;
        next=NULL;
    }
    node(int t){
        token=t;
        next=NULL;
    }
};

class LL{
    public:
    node *f;
    node *r;

    LL(){
        f=0;
        r=0;
    }

    void insert(int t){
        node *nn= new node(t);
        if(f==NULL && r==NULL){
            f=r=nn;
        }
        else{
            node *temp=new node();
            temp=f;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=nn;
            r=nn;
        }
    }

    void seat(){
        node *temp=new node();
        temp=f;
        if(f==NULL){
            cout<<"NO waiting list.";
        }
        else if(f==r){
            int k = f->token;
            cout<<"Delete Token:"<<k<<endl;
            f=NULL;
            r=NULL;
        }
        else{
            int k = f->token;
            cout<<"Delete Token:"<<k<<endl;
            f=f->next;
        }
    }

    void display(){
        node *temp = new node();
        temp=f;
        while(temp!=NULL){
            cout<<"Token:"<<temp->token<<endl;
            temp=temp->next;
        }
        cout<<'\n';
    }
};

int main()
{
    LL l;
    l.insert(2);
    l.insert(4);
    l.insert(8);
    l.insert(1);
    l.display();
    l.seat();
    l.seat();
    l.display();
    return 0;
}