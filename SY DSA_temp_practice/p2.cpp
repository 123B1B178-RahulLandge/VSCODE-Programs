#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int prec(char k){
    if(k=='^')
        return 3;
    else if(k=='/' || k=='*')
        return 2;
    else if(k=='+' || k=='-')
        return 1;
    else 
        return -1;
}

void infixToPrefix(char s[])
{
    char prefix[1000];
    int preIndex=0;
    char stack[1000];
    int top=-1;
    int len=strlen(s);
    for(int i=0;i<len;i++){
        char c=s[i];
        if( (c>='a'&&c<='z') || (c>='A'&&c<='Z') || (c>='0'&&c<='9'))
        {
            prefix[preIndex]=c;
            preIndex++;
        }
        else if(c=='(')
        {
            ++top;
            stack[top]=c;
        }
        else if(c==')'){
            while(top>=0 && stack[top]!='('){
                prefix[preIndex]=stack[top];
                preIndex++;
                top--;
            }
            top--;
        }
        else{
            while(top>=0 && (prec(s[i])<prec(stack[top]) || prec(s[i])==prec(stack[top])))
            {
                prefix[preIndex]=stack[top];
                preIndex++;
                top--;
            }
            top++;
            stack[top]=c;
        }
    }
    while(top>=0){
        prefix[preIndex]=stack[top];
        preIndex++;
        top--;
    }

    reverse(prefix,prefix+preIndex);
    prefix[preIndex]='\0';
    cout<<prefix;
}

int main()
{
    char exp[]="(1+2)*3";
    int n=strlen(exp);
    reverse(exp,exp+n);
    for(int i=0;i<n;i++){
        if(exp[i]=='(')
            {exp[i]=')';}
        else if(exp[i]==')')
            {exp[i]='(';}
    }
    infixToPrefix(exp);
    return 0;
}