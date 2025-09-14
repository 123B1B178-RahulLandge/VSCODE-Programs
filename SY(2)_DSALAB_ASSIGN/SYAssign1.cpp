#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int key;
    string value;
    node *left,*right;

    node(){
        key=0;
        value="";
        left=NULL;
        right=NULL;
    }

    node(int k,string val){
        key=k;
        value=val;
        left=NULL;
        right=NULL;
    }   
};

node *insert(node*root,int k,string val){
    if(root == NULL){
        return new node(k,val);
    }
    if(root->key==k){
        return root;
    }
    
    if(root->key < k){
        root->right = insert(root->right,k,val);
    }else{
        root->left = insert(root->left,k,val);
    }

    return root;
}

void inorder(node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" : "<<root->value<<endl;
        inorder(root->right);
    }
}

void preorder(node *root){
    if(root!=NULL){
        cout<<root->key<<" : "<<root->value<<endl;
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root){
    if(root !=NULL){
        postorder(root->left);
        postorder(root->right);
        cout<<root->key<<" : "<<root->value<<endl;
    }
}

bool search(node *root, int k){
    if(root==NULL){
        cout<<"Not found"<<endl;
        return false;
    }
    if(root->key == k){
        cout<<"Found"<<endl;
        cout<<"Value: "<<root->value<<endl;
        return true;
    }
    if(root->key > k) return search(root->left,k);
    
    return search(root->right,k);
}

node* minNode(node* root){
    node *curr=root;
    while(curr->left!=nullptr){
        curr=curr->left;
    }
    return curr;
}

node *deletenode(node*root,int k){
    if (root == nullptr)
        return root;
   
    if (k < root->key) {
        root->left = deletenode(root->left, k);
    }
    
    else if (k > root->key) {
        root->right = deletenode(root->right, k);
    }
    
    else {
        if(root->left == nullptr || root->right == nullptr){
            if (root->left == nullptr) {
                node* temp = root->right;
                cout<<"Deleted key : "<<root->key<<endl;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                node* temp = root->left;
                cout<<"Deleted key : "<<root->key<<endl;
                delete root;
                return temp;
            }
        }else{
            node* temp = minNode(root->right);
            root->key=temp->key;
            root->value=temp->value;
            root->right=deletenode(root->right,temp->key);
        }   
    }
    return root;
}

void level(node *root){
    if(root==NULL){
        return;
    }
    queue<node*>q;
    q.push(root);
    node *p=new node();
    while(!q.empty()){
        p=q.front();
        q.pop();
        cout<<p->key<<" : "<<p->value<<endl;
        if(p->left){
            q.push(p->left);
        }
        if(p->right){
            q.push(p->right);
        }
    }
}

void swap(node * root){
    node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

node* mirror(node* root){
    if(root == NULL){
        return root;
    }
    swap(root);
    mirror(root->left);
    mirror(root->right);
}

int main(){
    node * root = NULL;
    int choice,key,search_key,delete_key;
    string val;


    while(1){
        cout<<"1.Insert A Word \n2.Inorder Traversal \n3.Preorder Traversal \n4.Postorder Traversal \n5.Search A word \n6.Delete a word \n7.Mirror Image of dictionary \n8.Create copy of dictionary \n9.Display dictionary level-wise \n10.Exit \nEnter Your choice:";
        cin>>choice;
        switch(choice){
            case 1:{cout<<"Enter key:";
                    cin>>key;
                    cout<<"Enter Value:";
                    cin>>val;
                    root=insert(root,key,val);
                    break;
                }
            case 2:{cout<<"Inorder Traversal : "<<endl;
                    inorder(root);
                    break;}
            case 3: {cout<<"Preorder Traversal : "<<endl;
                    preorder(root);
                    break;}
            case 4:{cout<<"Postorder Traversal : "<<endl;
                    postorder(root);
                    break;}
            case 5:{cout<<"Enter key to search: ";
                    cin>>search_key;
                    cout<<search(root,search_key);
                    break;}
            case 6:{cout<<"Enter key to delete : ";
                    cin>>delete_key;
                    deletenode(root,delete_key);
                    break;}
            case 7:{mirror(root);
                    cout<<"Mirror Image is:"<<endl;
                    inorder(root);
                    break;}
            case 8:{
                    node *root1=root;
                    cout<<"Copy created"<<endl;
                    break;}
            case 9:{cout<<"Levelwise:"<<endl;
                    level(root);
                    break;}
            case 10:{return 0;
                    break;}
            default : cout<<"Invalid Choice";
        }  
    }
    
    return 0;
}
