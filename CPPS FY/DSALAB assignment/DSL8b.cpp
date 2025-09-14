//Prefix expression Evaluation.

#include <iostream>
#include <algorithm>
using namespace std;

int stack[100], n = 100, top = -1;

void push(int val) {
    if (top >= n - 1)
        cout << "Stack Overflow" << endl;
    else {
        top++;
        stack[top] = val;
    }
}

void pop() {
    if (top <= -1)
        cout << "Stack Underflow" << endl;
    else {
        top--;
    }
}

int evaluatePrefix(string exp) {
    for (int i = exp.size() - 1; i >= 0; --i) {
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        } else {
            int o1 = stack[top];
            pop();
            int o2 = stack[top];
            pop();
            switch (exp[i]) {
                case '+':
                    push(o1 + o2);
                    break;
                case '-':
                    push(o1 - o2);
                    break;
                case '*':
                    push(o1 * o2);
                    break;
                case '/':
                    push(o1 / o2);                   
                    break;
            }
        }
    }
    return stack[top];
}

int main() {
    string exp = "-9+*123"; 
    cout << "Prefix evaluation: " << evaluatePrefix(exp) << endl;
    return 0;
}
