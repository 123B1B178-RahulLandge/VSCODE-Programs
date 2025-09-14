#include<iostream>
using namespace std;

class node{
    public:
    char data;
    node *lchild;
    node *rchild;

    node(){
        data=0;
        lchild =NULL;
        rchild=NULL;
    }

    node(char d){
        data = d;
        lchild = NULL;
        rchild = NULL;
    }
};

int main(){
    node *root = new node('A');
    node *second = new node('B');
    root->lchild = second;
    node *third = new node('C');
    root->rchild = third;
    node *fourth = new node('D');
    root->lchild->lchild=fourth;
    node *fifth = new node('E');
    root->lchild->rchild = fifth;
    node *sixth = new node('F');
    root->rchild->rchild = sixth;

    cout<<"Binary Tree is :";
    cout<<root->data<<" ";
    cout<<root->lchild->data<<" ";
    cout<<root->rchild->data<<" ";
    cout<<root->lchild->lchild->data<<" ";
    cout<<root->lchild->rchild->data<<" ";
    cout<<root->rchild->rchild->data<<" ";
    return 0;
}