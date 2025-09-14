#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left,*right;

    node(int d){
        data=d;
        left=nullptr;
        right=nullptr;
    }
};


    node* insert(node* root,int val){
        if(root==nullptr){
            return new node(val);
        }
        else if(root->data==val){
            return root;
        }
        else{
            if(val>root->data)
                root->right=insert(root->right,val);
            else 
                root->left=insert(root->left,val);
        }

        return root;
    }

    void inorder(node* root){
        if(root==nullptr) return;

        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }


    node* minNode(node* root){
        node * curr=root;
        while(curr->left!=nullptr){
            curr=curr->left;
        }
        return curr;
    }
    node* deleteNode(node* root,int d){
        if(root==nullptr){
            cout<<"Not found";
            return root;
        }
            

        if(root->data > d){
            root->left=deleteNode(root->left,d);
        }else if(root->data < d){
            root->right=deleteNode(root->right,d);
        }else{
            if(root->left==nullptr || root->right==nullptr){
                if(root->left==nullptr){
                    node* temp=root->right;
                    delete root;
                    return temp;
                }else{
                    node* temp=root->left;
                    delete root;
                    return temp;
                }
            }else{
                node* temp=minNode(root->right);
                root->data=temp->data;
                root->right=deleteNode(root->right,temp->data);
            }
        }
    }

    void swaper(node* root){
        node* temp=root->right;
        root->right=root->left;
        root->left=temp;
    }
    void mirror(node * root){
        if(root==nullptr) return;

        swaper(root);
        mirror(root->left);
        mirror(root->right);
    }

    node* search(node* root,int d){
        if(root==nullptr){
            cout<<"No. not found"<<endl;
            return root;
        }

        if(root->data > d){
            root->left=search(root->left,d);
        }else if(root->data < d){
            root->right=search(root->right,d);
        }else{
            cout<<"Found the given no.: " << root->data<<endl;
            return root;
        }
        return root;
    }

    void levelwise(node *root){
        if(root==nullptr) {
            cout<<"No element";
            return;
        }

        node* queue[10];
        int front=0,rear=0;
        queue[rear]=root;
        rear++;

        while(front<rear){
            node* curr=queue[front];
            front++;
            cout<<curr->data<<" ";
            if(curr->left) {
                queue[rear]=curr->left;
                rear++;
            }
            if(curr->right){
                queue[rear]=curr->right;
                rear++;
            }
        }
        cout<<endl;
    }
int main(){
    node *root=nullptr;
    root=insert(root,10);
    root=insert(root,4);
    root=insert(root,2);
    root=insert(root,5);
    root=insert(root,11);
    root=insert(root,22);
    root=insert(root,34);

    inorder(root);
    cout<<endl;

    levelwise(root);

    node* temp=search(root,34);

    root=deleteNode(root,11);

    inorder(root);
    cout<<endl;

    mirror(root);
    inorder(root);
    cout<<endl;

    return 0;
}