#include<iostream>
using namespace std;

class node{
    public:
    int pow,coeff;
    node *next;

    node(){
        pow=0;
        coeff=0;
        next=NULL;
    }

    node(int p,int c){
        pow = p;
        coeff = c;
        next = NULL;
    }
};

class LL{
    public:
    node *head;

    LL(){
        head=0;
    }

    void insert(int p,int c){
        node *nn = new node(p,c);
        if(head==NULL){
            head=nn;
        }else{
            node *temp = new node();
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next = nn;
        }
    }

    void display(){
        if(head==NULL){
            cout<<"No node present";
        }else{
            node *temp = new node();
            temp = head;
            while(temp->next!=NULL){
                cout<<temp->coeff<<"^"<<"("<<temp->pow<<")"<<" + ";
                temp=temp->next;
            }
            cout<<temp->coeff<<"^"<<"("<<temp->pow<<")";
        }
    }

    void add(LL l1,LL l2){
        node *temp = l1.head;
        node *temp1 = l2.head;

    while(temp1 != NULL && temp!=NULL){
        if(temp->pow > temp1->pow){
            insert(temp->pow,temp->coeff);
            temp=temp->next;
        }
        else if(temp->pow < temp1->pow){
            insert(temp1->pow,temp1->coeff);
            temp1=temp1->next;
        }
        else if(temp->pow == temp1->pow){
            insert(temp1->pow,temp1->coeff+temp->coeff);
            temp = temp->next;
            temp1 = temp1->next;
        }
    }
    while(temp1!=NULL){
            insert(temp1->pow,temp1->coeff);
            temp1 = temp1->next;
        }

    while(temp!=NULL){
        insert(temp->pow,temp->coeff);
        temp = temp->next;
    }    
    }
};

int main(){
    LL l,l1,l2;

    l1.insert(6,5);
    l1.insert(4,1);
    l1.insert(1,5);

    l2.insert(8,1);
    l2.insert(6,7);
    l2.insert(1,2);

    l.add(l1,l2);
    l.display();
    return 0;
}