#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class node{
    public:
    int key;
    node *left;
    node *right;

    node(int k){
        key=k;
        left=NULL;
        right=NULL;
    }
};
    node *insert(node *root,int key){
        if(root == NULL){
            return new node(key);
        }
        if(root->key==key){
            return root;
        }
        
        if(root->key < key){
            root->right = insert(root->right,key);
        }else{
            root->left = insert(root->left,key);
        }

        return root;
    }

    void dfs(node *root){
        if(root!=NULL){
            cout<<root->key<<" ";
            dfs(root->left);
            dfs(root->right);
        }
    }

    void recursiveBfs(node *root){
        node *curr=root;
        if(curr==NULL) return;
        if(curr->left != NULL)  cout<<curr->left->key<<" ";
        if(curr->right != NULL) cout<<curr->right->key<<" ";
        recursiveBfs(curr->left);
        recursiveBfs(curr->right);
    }

    void bfs(node *root){
        node *curr;
        queue<node *> q;
        q.push(root);

        while(!q.empty()){
            curr=q.front();
            cout<<curr->key<<" ";
            q.pop();

            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }

int main(){
    node *root=NULL;
    int choice,key;

    while(1){
        cout<<"\n1.Insert Node \n2.Depth First Search(DFS) \n3.Breadth first Search(BFS) \n4.Exit \nEnter Choice: ";
        cin>>choice;

        switch(choice){
            case 1: cout<<"Enter value: ";
                    cin>>key;
                    root=insert(root,key);
                    break;
            case 2: cout<<"==> Depth First Search: ";
                    dfs(root);
                    cout<<"\n";
                    break;
            case 3: cout<<"==> Breadth First Search: ";
                    bfs(root);
                    // cout<<root->key<<" ";
                    // recursiveBfs(root);
                    cout<<"\n";
                    break;
            case 4: return 0;
            default: cout<<"Invalid Choice.\n";
        }
    }
    // root=insert(root,7);
    // root=insert(root,4);
    // root=insert(root,9);
    // root=insert(root,3);
    // root=insert(root,5);
    // root=insert(root,8);
    // root=insert(root,10);
    // dfs(root);
    // bfs(root);
    return 0;
}

