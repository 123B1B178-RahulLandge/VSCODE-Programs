
/* TITLE : Rat In Maze problem solved by using Stack

Team members :
 1.Rohit Lad  PRN-123B1B176
 2.Soniya Lakade PRN-123B1B177
 3.Rahul Landge PRN-123B1B178
 4.Tanmay Latke PRN-123B1B179
*/

#include <iostream>
using namespace std;

class node {
public:
    int m, n;
    node *next;

    node()
    {
        m=0;
        n=0;
        next = NULL;
    }

    node(int k,int l)
    {
        m=k;
        n=l;
        next = NULL;
    }
};

class LL {
public:
    node *head;
    node *top;

    LL(){
        head = 0;
        top=0;
    }

    void insert(int k, int l) {
        node *nn = new node(k, l);
        if (head == NULL) {
            head = nn;
        } 
        else{
            node *temp = new node();
            temp=head;
            while (temp != top && temp->next !=NULL) {
                temp = temp->next;
            }
            temp->next = nn;
            top=nn;
        }  
    }

    void del() {
    if (head == NULL) {
        cout << "Stack is empty." << endl;
        return;
    }
    
    if (head->next == NULL) {
        delete head;  
        head = NULL;
        top=NULL; 
        return;
    }

    node *temp = head;
    node *temp1 = NULL;

    while (temp != top) {
        temp1 = temp;
        temp = temp->next;
    }

    delete temp;
    top=temp1;      
    top->next = NULL; 
}


    void display() {
        if (head == NULL) {
            cout << "Stack is empty." << endl;
        } 
        else {
            node *temp = new node();
            temp=head;
            while (temp != top && temp->next != NULL) {
                cout << "(" << temp->m << "," << temp->n << ")" << " ";
                temp = temp->next;
            }
            cout << "(" << temp->m << "," << temp->n << ")" << " ";
            cout << endl;
        }
    }
};

bool issafe(int** arr, int x, int y, int n) {
    if(x < n && y < n && arr[x][y] == 1){
        return true;
    }
    return false;
}

bool ratinMaze(int** arr, int x, int y, int n, LL &l) { 
    if (x == n - 1 && y == n - 1) {
        l.insert(x, y);
        return true;
    }

    if (issafe(arr, x, y, n)) {
        l.insert(x, y);
        if (ratinMaze(arr, x + 1, y, n, l)) {  
            return true;
        }

        if (ratinMaze(arr, x, y + 1, n, l)) {
            return true;
        }
    
        l.del();
        return false;
    }

    return false;
}

int main() {
    int n;
    cout << "Enter n: ";
    cin >> n;
    LL l;
    int** arr = new int*[n];
    for (int i = 0; i < n; i++){
        arr[i] = new int[n];
    }

    cout << "Enter Array (0 for blocked, 1 for path):" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    if (ratinMaze(arr, 0, 0, n, l)) {
        cout<<"The Final Path: ";
        l.display();
    } else {
        cout << "No path found!" << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] arr[i];
    }
    delete[] arr;

    return 0;
}

