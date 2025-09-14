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
        pow=p;
        coeff=c;
        next=NULL;
    }
};

class LL{
    public:
    node *head;

    LL(){
        head=0;
    }

    void insert(int p,int c){
        node *nn=new node(p,c);
        if(head==NULL){
            head=nn;
        }else{
            node *temp=new node();
            temp=head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next=nn;
        }
    }

    void polyadd(LL &l1,LL &l2,LL &l3){
        node *temp1=l2.head;
        node *temp2=l3.head;

        while(temp1!=NULL && temp2!=NULL){
            if(temp1->pow == temp2->pow){
                int new_coeff = temp1->coeff + temp2->coeff;
                l1.insert(temp1->pow,new_coeff);
                temp1=temp1->next;
                temp2=temp2->next;
            }
            else if(temp1->pow < temp2->pow){
                l1.insert(temp2->pow,temp2->coeff);
                temp2=temp2->next;
            }
            else if(temp1->pow > temp2->pow){
                l1.insert(temp1->pow,temp1->coeff);
                temp1=temp1->next;
            }
        }
    }

    void display(){
        node *temp=new node();
        temp=head;
        while(temp->next!=NULL){
            cout<<temp->coeff<<"x^"<<temp->pow<<"+";
            temp=temp->next;
        }
        cout<<temp->coeff<<"x^"<<temp->pow<<endl;
    }
};

int main(){
    LL l,l1,l2,l3;
    l2.insert(5,5);
    l2.insert(2,2);
    l2.insert(1,7);
    l2.display();
    l3.insert(4,2);
    l3.insert(3,1);
    l3.insert(1,6);
    l3.display();
    l.polyadd(l1,l2,l3);
    l1.display();
    return 0;
}