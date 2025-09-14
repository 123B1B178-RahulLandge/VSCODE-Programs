#include<iostream>
#include<algorithm>
using namespace std;


int stack[100],n=100,top=-1;


void push(int k)
{
    if(top>n){
        cout<<"StackOverflow";
    }
    else{
        ++top;
        stack[top]=k;
    }
}

void pop()
{
    if(top<=-1){
        cout<<"Stack Underflow";
    }
    else{
        top--;
    }
}

void postfixEval(string s){
    for(int i=0;i<s.size();i++){
        if(isdigit(s[i])){
            push(s[i]-'0');
        }
        else{
            int o1=stack[top];
            pop();
            int o2=stack[top];
            pop();
            switch(s[i]){
                case '+' : push(o2+o1);
                            break;
                case '-' : push(o2-o1);
                            break;
                case '*' : push(o2*o1);
                            break;
                case '/' : push(o2/o1);
                            break;
            }
        }
    }
    cout<<stack[0];
}

int main()
{
    string exp="84/2*";
    postfixEval(exp);
    return 0;
}