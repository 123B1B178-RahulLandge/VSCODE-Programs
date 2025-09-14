#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;

int prec(char k)
{
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
    int prefixIndex=0;
    char stack[1000];
    int stacktop = -1;
    int len = strlen(s);

    for(int i=0; i<len ;i++)
    {
        char c=s[i];
        if((c >= 'a' && c <= 'z') || ( c>= 'A' && c <= 'Z') || (c>= '0' && c<= '9'))
        {
            prefix[prefixIndex] = c;
            prefixIndex++;
        }
        else if( c=='(')
        {
            ++stacktop;
            stack[stacktop]=c;
        }
        else if( c==')')
        {
            while( (stacktop>=0) && stack[stacktop] != '(')
            {
                prefix[prefixIndex] = stack[stacktop];
                prefixIndex++;
                stacktop--;
            }
            stacktop--;
        }
        else{
            while((stacktop >= 0 && (prec(s[i]) < prec(stack[stacktop])||prec(s[i]) == prec(stack[stacktop]))))
            {
                prefix[prefixIndex]=stack[stacktop];
                prefixIndex++;
                stacktop--;
            }
            stacktop++;
            stack[stacktop]=c;
        }
    }

    while(stacktop >=0)
    {
        prefix[prefixIndex]=stack[stacktop];
        prefixIndex++;
        stacktop--;
    }

    reverse(prefix,prefix+prefixIndex);
    prefix[prefixIndex]='\0';
    cout<<prefix;
}

int main()
{
    char exp[]="(A+B)*(C-D)";
    int n=strlen(exp);
    reverse(exp,exp+n);
    for(int i=0;i<n;i++)
    {
        if(exp[i] =='(')
        {
            exp[i] = ')';
        }
        else if(exp[i] ==')')
        {
            exp[i] = '(';
        }
    }
    infixToPrefix(exp);
    return 0;
}