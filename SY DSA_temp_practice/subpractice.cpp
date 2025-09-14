#include<iostream>
#include<cstring>
using namespace std;

int prec(char k)
{
    if(k == '^')
        return 3;
    else if(k== '/' || k=='*')
        return 2;
    else if(k=='+' || k=='-')
        return 1;
    else 
        return -1;
}

void infixTopostFix(char s[])
{
    char postfix[1000];
    int postfixindex=0;
    int len = strlen(s);
    char stack[1000];
    int stacktop=-1;

    for(int i=0;i<len;i++){
        char c = s[i];

        if((c >='a' && c<='z')  || (c >='0' && c<='9') || (c >='A' && c<='Z'))
        {
            postfix[postfixindex] = c;
            postfixindex++;
        }
        else if(c=='(')
        {
            ++stacktop;
            stack[stacktop] = c;
        }
        else if( c== ')')
        {
            while( (stacktop >= 0) && stack[stacktop] != '(')
            {
                postfix[postfixindex]=stack[stacktop];
                postfixindex++;
                stacktop--;
            }
            stacktop--;
        }
        else
        {
            while((stacktop >= 0 && (prec(s[i]) < prec(stack[stacktop])||prec(s[i]) == prec(stack[stacktop]))))
            {
                postfix[postfixindex] = stack[stacktop];
                postfixindex++;
                stacktop--;
            }
            stacktop++;
            stack[stacktop] = c;
        }
    }

    while(stacktop>=0)
    {
        postfix[postfixindex] = stack[stacktop];
        postfixindex++;
        stacktop--;
    }

    postfix[postfixindex] = '\0';
    std::cout<<postfix;
}

int main()
{
    char exp[]= "(A+B)*(C-D)";
    infixTopostFix(exp);
    return 0;
}