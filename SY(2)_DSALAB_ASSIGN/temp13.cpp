#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(){
        data=0;
        left=nullptr;
        right=nullptr;
    }

    node(int d){
        data=d;
        left=nullptr;
        right=nullptr;
    }
};

class BST{
    public:

    node* insert(node* root,int val){
        if(root==nullptr || root->data==val){
            return new node(val);
        }

        if(root->data > val){
            root->left = insert(root->left,val);
        }else if(root->data < val){
            root->right = insert(root->right,val);
        }

        return root;
    }

    void inorder(node* root){
        stack<node* >s;
        node *curr=root;
        while(curr!=nullptr || !s.empty()){
            if(curr!=nullptr){
                s.push(curr);
                curr=curr->left;
            }else{
                curr=s.top();
                s.pop();
                cout<<curr->data<<" ";
                curr=curr->right;
            }
        }
    }

    void preorder(node* root){
        stack<node*>s;
        s.push(root);

        node* curr=nullptr;

        while(!s.empty()){
            node *curr=s.top();
            s.pop();
            cout<<curr->data<<" ";

            if(curr->right) s.push(curr->right);
            if(curr->left) s.push(curr->left);
        }
    }

    void postorder(node* root){
        if(root==nullptr) return;

        stack<node*> s1,s2;

        s1.push(root);
        node *curr=nullptr;

        while(!s1.empty()){
            node*curr=s1.top();
            s1.pop();
            s2.push(curr);

            if(curr->left) s1.push(curr->left);
            if(curr->right) s1.push(curr->right);
        }

        while(!s2.empty()){
            cout<<s2.top()->data<<" ";
            s2.pop();
        }
    }
};

int main(){
    BST b;
    node *root=nullptr;
    root=b.insert(root,4);
    root=b.insert(root,2);
    root=b.insert(root,10);
    root=b.insert(root,1);

    b.postorder(root);

    return 0;
}