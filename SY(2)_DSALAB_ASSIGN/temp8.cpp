#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node *left,*right;

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

    node* insert(node *root,int val){
        if(root==nullptr) {
            return new node(val);
        }

        if(root->data==val){
            return root;
        }

        if(root->data < val){
            root->right=insert(root->right,val);
        }else if(root->data > val){
            root->left=insert(root->left,val);
        }

        return root;
    }

    node *deleteNode(node *root,int key){
        if(root==nullptr){
            return root;
        }

        if(root->data < key){
            root->right=deleteNode(root->right,key);
        }else if(root->data > key){
            root->left=deleteNode(root->left,key);
        }else{
            if(root->left==nullptr || root->right==nullptr){
                if(root->left==nullptr){
                    node* temp = root->right;
                    delete root;
                    return temp;
                }else if(root->right==nullptr){
                    node *temp = root->left;
                    delete root;
                    return temp;
                }
            }else{
                node * temp = minNode(root->right);
                root->data = temp->data;
                root->right=deleteNode(root->right,temp->data);
            }
        }
        return root;
    }

    node *minNode(node * root){
        node *curr=root;

        while(curr->left !=nullptr){
            curr=curr->left;
        }

        return curr;
    }

    node* search(node* root,int key){
        if(root==nullptr){
            cout<<"Not found";
            return root;
        }

        if(root->data > key){
            return search(root->left,key);
        }else if(root->data < key){
            return search(root->right,key);
        }else{
            cout<<"Found No.: "<<root->data;
            return root;
        }
    }

    void swap(node *root){
        node* temp=root->left;
        root->left=root->right;
        root->right=temp;
    }

    node* mirror(node* root){
        if(root==nullptr){
            return root;
        }
        swap(root);
        mirror(root->left);
        mirror(root->right);
    }

    void levelwise(node *root){
        if(root==nullptr){
            return;
        }

        queue<node*>q;
        q.push(root);

        node *p=new node();

        while(!q.empty()){
            p=q.front();
            q.pop();

            cout<<p->data<<" ";

            if(p->left) q.push(p->left);
            if(p->right) q.push(p->right);
        }
    }


    void inorder(node *root){
        if(root!=nullptr){
            inorder(root->left);
            cout<<root->data<<" ";
            inorder(root->right);
        }
    }
};

int main(){
    BST b;
    node *root=nullptr;
    root=b.insert(root,10);
    root=b.insert(root,1);
    root=b.insert(root,3);
    root=b.insert(root,5);
    root=b.insert(root,2);

    b.inorder(root);
    cout<<endl;

    b.deleteNode(root,3);
    b.inorder(root);

    b.search(root,6);
    cout<<endl;

    b.levelwise(root);
    return 0;
}