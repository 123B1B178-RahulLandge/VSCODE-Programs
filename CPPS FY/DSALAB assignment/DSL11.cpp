#include<iostream>
using namespace std;

class node{
    public:
    string emp_name;
    int emp_id;
    node *next;
    node(){
        emp_name = "none";
        emp_id = 0;
        next=NULL;
    }
    node(string n,int i){
        emp_name = n;
        emp_id = i;
        next=NULL;
    }
};

class LL{
    public:
    node *head;
    LL(){
        head=0;
    }

    void insert(string n, int i){
        node *nn = new node(n,i);

        if(head == NULL){
            head=nn;
        }
        else{
            node *temp = head;
            while(temp->next != NULL){
                temp=temp->next;
            }
            temp->next = nn;
        }
    }

    void search(int i){
        int count=0;
        node *temp = head;
        cout<<"<--Employee Detail-->"<<endl;
        while(temp != NULL){
        if(temp->emp_id == i){
            cout<<temp->emp_id<<" : "<<temp->emp_name<<endl;
            count++;
            break;
        }
        temp=temp->next;
        }
        if(count==0){
            cout<<"NO employee with id "<<i<<" found."<<endl;
        }
    }

    friend void display(LL l[]);
};

void display(LL l[]){
    cout<<"Emp_ID   Emp_Name"<<endl;
    for(int i=0;i<10;i++){
        node *temp = l[i].head;
        while(temp != NULL){
            cout<<temp->emp_id<<"    :    "<<temp->emp_name<<endl;
            temp = temp->next;
        }
    }
}

int HashFunction(int i){
    return i%10;
}

int main(){
    LL l[10];
    string name;
    int k,id;

    do{
        cout<<"1.Enter employee detail \n2.Search for emp_id \n3.Display all employee detail \n4.Exit \n";
        cout<<"Enter Choice: ";
        cin>>k;
        switch(k){
            case 1: {cout<<"Enter employee id: ";
                    cin>>id;
                    cout<<"Enter employee name: ";
                    cin>>name;
                    l[HashFunction(id)].insert(name,id);
                    break;}
            case 2: {cout<<"Enter Employee id to search: ";
                    cin>>id;
                    l[HashFunction(id)].search(id);
                    break;}
            case 3:{display(l);
                        break;}
            case 4 : return 0;
            }
    }while(1);
    
    return 0;
}