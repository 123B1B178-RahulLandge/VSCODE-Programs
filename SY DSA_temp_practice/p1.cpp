#include<iostream>
#include<cstring>
using namespace std;

int prec(char k)
{
    if(k =='^')
        return 3;
    else if(k=='*' || k=='/')
        return 2;
    else if(k=='+' || k=='-')
        return 1;
    else
        return -1;
}

void infixToPostfix(char s[])
{
    char postfix[1000];
    int postIndex=0;
    char stack[1000];
    int top=-1;
    int len = strlen(s);
    for(int i=0;i<len;i++){
        char c = s[i];
        if( (c>='a' && c<='z')||(c >='A' && c<='Z')||(c>='0' && c<='9') ){
            postfix[postIndex]=c;
            postIndex++;
        }
        else if(c=='(')
        {
            ++top;
            stack[top]=c;
        }
        else if(c==')')
        {
            while(top>=0 && stack[top]!='(')
            {
                postfix[postIndex]=stack[top];
                postIndex++;
                top--;
            }
            top--;
        }
        else{
            while((top >=0 && (prec(s[i]) < prec(stack[top]) || prec(s[i])==prec(stack[top]))))
            {
                postfix[postIndex]=stack[top];
                postIndex++;
                top--;
            }
            top++;
            stack[top]=c;
        }   
    }
    while(top>=0){
        postfix[postIndex]=stack[top];
        postIndex++;
        top--; 
    }
    postfix[postIndex]='\0';
    cout<<postfix;
}

int main()
{
    char exp[]="(A-B/C)*(A/K-L)";
    infixToPostfix(exp);
    return 0;
}