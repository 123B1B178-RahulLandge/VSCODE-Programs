#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int stack[100],n=100,top=-1;

void push(int k){
    if(top>=n-1){
        cout<<"Stack Overflow";
    }else{
        ++top;
        stack[top]=k;
    }
}

void pop()
{
    if(top<=-1){
        cout<<"Stack Underflow";
    }else{
        top--;
    }
}

void prefixEval(string s)
{
    for(int i=s.size()-1;i>=0;i--){
        if(isdigit(s[i])){
            push(s[i]-'0');
        }else{
            int o1=stack[top];
            pop();
            int o2=stack[top];
            pop();
            switch(s[i]){
                case '+' : push(o1+o2);
                           break;
                case '-' : push(o1-o2);
                           break;
                case '*' : push(o1*o2);
                           break;
                case '/' : push(o1/o2);
                           break;
                case '^' : push(pow(o1,o2));
                           break;
            }
        }
    }
    cout<<stack[top];
}

int main()
{
    string exp="-+7*456";
    prefixEval(exp);
    return 0;
}