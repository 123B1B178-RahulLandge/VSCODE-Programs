#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left,*right,*parent;
    int color;


    node(int d){
        data=d;
        left=nullptr;
        right=nullptr;
        parent=nullptr;
        color=1;
    }
};

class RedBlack{
    node *root;

    void rotateLeft(node* &root,node* &pt){
        node* pt_right=pt->right;
        pt->right=pt_right->left;

        if(pt->right!=nullptr){
            pt->right->parent=pt;
        }

        pt_right->parent=pt->parent;

        if(pt->parent==nullptr){
            root=pt_right;
        }else if(pt==pt->parent->right){
            pt->parent->right=pt_right;
        }else{
            pt->parent->left=pt_right;
        }

        pt_right->left=pt;
        pt->parent=pt_right;
    }

    void rotateRight(node* &root,node* &pt){
        node* pt_left=pt->left;
        pt->left=pt_left->right;

        if(pt->left!=nullptr){
            pt->left->parent=pt;
        }

        pt_left->parent=pt->parent;

        if(pt->parent==nullptr){
            root=pt_left;
        }else if(pt==pt->parent->right){
            pt->parent->right=pt_left;
        }else{
            pt->parent->left=pt_left;
        }

        pt_left->right=pt;
        pt->parent=pt_left;

    }

    void fixViolation(node* &root,node* &pt){
        node* parent_pt=nullptr;
        node* grand_parent_pt=nullptr;

        while(pt!=root && pt->color!=0 && pt->parent->color==1){
            parent_pt=pt->parent;
            grand_parent_pt=pt->parent->parent;

            if(parent_pt == grand_parent_pt->left){
                node* uncle_pt=grand_parent_pt->right;

                if(uncle_pt!=nullptr && uncle_pt->color==1){
                    grand_parent_pt->color=1;
                    parent_pt->color=0;
                    uncle_pt->color=0;
                    pt=grand_parent_pt;
                }else{
                    if(pt==parent_pt->right){
                        rotateLeft(root,parent_pt);
                        pt=parent_pt;
                        parent_pt=pt->parent;
                    }
                    rotateRight(root,grand_parent_pt);
                    swap(parent_pt->color,grand_parent_pt->color);
                    pt=parent_pt;
                }
            }else{
                node* uncle_pt = grand_parent_pt->left;

                if(uncle_pt!=nullptr && uncle_pt->color==1){
                    grand_parent_pt->color=1;
                    parent_pt->color=0;
                    uncle_pt->color=0;
                    pt=grand_parent_pt;
                }else{
                    if(pt==parent_pt->left){
                        rotateRight(root,parent_pt);
                        pt=parent_pt;
                        parent_pt=pt->parent;
                    }
                    rotateLeft(root,grand_parent_pt);
                    swap(parent_pt->color,grand_parent_pt->color);
                    pt=parent_pt;
                }
            }
        }
        root->color=0;
    }

    void inorderHelper(node * root){
        // if (root == nullptr)
        //     return;

        // inorderHelper(root->left);
        // cout << root->data << " (" << (root->color == 1 ? "R" : "B") << ") ";
        // inorderHelper(root->right);
        if(root!=nullptr){
            inorderHelper(root->left);
            cout<<root->data<<"("<<root->color<<")"<<" ";
            inorderHelper(root->right);
        }
    }

    public:
    RedBlack(){
        root=nullptr;
    }

    void insert(int val){
        node *pt=new node(val);

        node *y=nullptr;
        node *x=root;

        while(x!=nullptr){
            y=x;
            if(pt->data > x->data) x=x->right;
            else if(pt->data < x->data) x=x->left;
        }

        pt->parent=y;

        if(y==nullptr){
            root=pt;
        }else if(pt->data > y->data){
            y->right=pt;
        }else{
            y->left=pt;
        }

        fixViolation(root,pt);
    }

    void inorder(){
        if(root==nullptr){
            return;
        }

        inorderHelper(root);
        cout<<endl;
    }
};

int main(){
    RedBlack tree;

    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);
    tree.insert(5);
    tree.insert(1);

    cout << "Inorder traversal with color (R=Red, B=Black):" << endl;
    tree.inorder();

    return 0;
}