#include <iostream>
#include <stack>
#include <string>
using namespace std;
bool isOperand(char c) {
  return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z');
}

int precedence(char c) {
  if (c == '^') return 3;
  else if (c == '*' || c == '/') return 2;
  else if (c == '+' || c == '-') return 1;
  else return -1; 
}

string infixToPostfix(string s) {
  stack<char> st;
  string postFix; 
  for (int i = 0; i < s.length(); i++) {
    if (isOperand(s[i])) { 
      postFix += s[i];
    }
    else if (s[i] == '(') {
      st.push('(');
    }
    else if (s[i] == ')') {
      while (!st.empty() && st.top() != '(') {
        postFix += st.top();
        st.pop();
      }
      if (!st.empty() && st.top() == '(') {
        st.pop();
      }
    }
    else { 
      while (!st.empty() && precedence(s[i]) <= precedence(st.top())) { // Pop and append all the operators from the stack that have higher or equal precedence than the scanned operator
        postFix += st.top();
        st.pop();
      }
      st.push(s[i]); 
    }
  }
  while (!st.empty()) { 
    postFix += st.top();
    st.pop();
  }
  return postFix; 
}

int main() {
  string infix;
  cout << "WELCOME TO INFIX TO POSTFIX CONVERTER: " << endl;
  cout << "Enter your Infix Expression: ";
  getline(cin, infix);
  string postfix = infixToPostfix(infix); 
  cout << "The Postfix Expression is : " << postfix << endl; 
  return 0;
}
