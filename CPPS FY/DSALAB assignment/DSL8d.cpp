//Postfix expression Evaluation

#include <iostream>
using namespace std;

int stack[100], n=100, top=-1;

void push(int val) {
   if(top>=n-1)
   cout<<"Stack Overflow"<<endl;
   else {
      top++;
      stack[top]=val;
   }
}
void pop() {
   if(top<=-1)
   cout<<"Stack Underflow"<<endl;
   else {
      top--;
   }
}
void display() {
   if(top>=0) {
      cout<<"Stack elements are:";
      for(int i=top; i>=0; i--)
      cout<<stack[i]<<" ";
      cout<<endl;
   } else
   cout<<"Stack is empty";
}
int TOP()
{
    return top;
}
int isOperand(char c)
{
     if (isdigit(c)) {
          return 1;}
    else{
          return 0;
          }
}
int evaluatePostfix(string exp)
{
    int st[10];

    for (int i = 0; i < exp.size(); ++i) {
    if (isdigit(exp[i]))
            push(exp[i]-'0');
    else 
    {
        int o1 = stack[top];
        pop();
        int o2 = stack[top];
        pop();
        switch (exp[i]) 
        {
            case '+':
                push(o2 + o1);
                break;
            case '-':
                push(o2 - o1);
                break;
            case '*':
                push(o1 * o2);
                break;
            case '/':
                push(o2 / o1);
                break;
        }
    }
}
    return stack[top];
}

int main()
{
   string exp = "512+4*+3-";
   cout << "postfix evaluation: " << evaluatePostfix(exp);
return 0;
}