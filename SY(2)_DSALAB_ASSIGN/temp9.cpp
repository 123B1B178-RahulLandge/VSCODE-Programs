#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left,*right;
    int height;

    node(){
        data=0;
        height=0;
        left=nullptr;
        right=nullptr;
    }

    node(int d){
        data=d;
        height=0;
        left=nullptr;
        right=nullptr;
    }
};

class AVL{
    public:

    int getHeight(node *root){
        if(root==nullptr) return 0;
        else{
            return root->height;
        }
        
    }

    int balanceFactor(node* root){
        if(root==nullptr)
            return 0;
        
        return getHeight(root->left)-getHeight(root->right);
    }

    node* rotateLeft(node* x){
        node *y=x->right;
        node *T2=y->left;

        y->left=x;
        x->right=T2;

        y->height=max(getHeight(y->left),getHeight(y->right))+1;
        x->height=max(getHeight(x->left),getHeight(x->right))+1;

        return y;
    }

    node* rotateRight(node* y){
        node* x=y->left;
        node* T2=x->right;

        x->right=y;
        y->left=T2;

        y->height=max(getHeight(y->left),getHeight(y->right))+1;
        x->height=max(getHeight(x->left),getHeight(x->right))+1;

        return x;
    }

    node* balance(node* root){
        if(root==nullptr) return root;

        root->height=max(getHeight(root->left), getHeight(root->right)) + 1;

        int bf = balanceFactor(root);

        if(bf > 1 && balanceFactor(root->left)<0){
            root->left=rotateLeft(root->left);
            rotateRight(root);
        }
        if(bf < -1 && balanceFactor(root->right) > 0){
            root->right=rotateRight(root->right);
            rotateLeft(root->left);
        }
        if(bf > 1 && balanceFactor(root->left) > 0){
            rotateRight(root);     
        }
        if(bf < -1 && balanceFactor(root->right) < 0){
            rotateLeft(root);
        }

        return root;
    }

    node* insert(node *root,int val){
        if(root==nullptr || root->data==val){
            return new node(val);
        }

        if(root->data > val)
            root->left=insert(root->left,val);
        else if(root->data < val){
            root->right=insert(root->right,val);
        }

        return balance(root);
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
    AVL a;
    node *root=nullptr;
    root=a.insert(root,5);
    root=a.insert(root,2);
    root=a.insert(root,3);
    root=a.insert(root,1);

    a.inorder(root);
    return 0;
}