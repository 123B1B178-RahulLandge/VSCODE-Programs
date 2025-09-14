
//Merging two sorted Linked Lists

#include<iostream>
using namespace std;

class node
{
    public:
    int data;
    node *next;

    node()
    {
        data=0;
        next = NULL;
    }

    node(int d)
    {
        data = d;
        next =NULL;
    }  
};

class LL
{
    public:
    node *head;

    LL()
    {
        head = 0;
    }

    void insert(int d)
    {
        node *nn = new node(d);
        if(head == NULL)
        {
            head = nn;
        }
        else
        {
            node *temp = new node();
            temp = head;

            while(temp->next !=NULL)
            {
                temp=temp->next;
            }

            temp->next = nn;
        }
    }

    void display()
    {
        if(head == NULL)
        {
            cout<<"LL is empty";
        }
        else
        {
            node *temp = new node();
            temp = head;

            while(temp->next !=NULL)
            {
                cout<<temp->data<<" ";
                temp=temp->next;
            }
            cout<<temp->data;
        }
    }
    

    void merge(LL &l1,LL &l2)
    {
        node *temp1 = new node();
        node *temp2 = new node();

        temp1 = l1.head;
        temp2 = l2.head;

        while(temp1 != NULL && temp2 != NULL)
        {
            if(temp1->data < temp2 ->data)
            {
                insert(temp1->data);
                temp1 = temp1->next;
            }
            else if(temp1->data > temp2 ->data)
            {
                insert(temp2->data);
                temp2 = temp2->next;
            }
            else if(temp1->data = temp2 ->data)
            {
                insert(temp1->data);
                temp1 = temp1->next;
            }
        }

        while(temp1 != NULL)
        {
            insert(temp1->data);
            temp1 = temp1->next;
        }

        while(temp2 != NULL)
        {
            insert(temp2->data);
            temp2 = temp2->next;
        }
    }
};

int main()
{
    LL l1,l2,l3;
    l1.insert(1);
    l1.insert(4);
    l1.insert(7);
    l2.insert(0);
    l2.insert(5);
    l2.insert(8);
    l2.insert(19);

    l3.merge(l1,l2);
    l3.display();
    return 0;
}