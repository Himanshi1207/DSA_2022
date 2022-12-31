// Evaluate the value of an arithmetic expression in Reverse Polish Notation.

// Valid operators are +, -, *, and /. Each operand may be an integer or another expression.

// Note that division between two integers should truncate toward zero.

// It is guaranteed that the given RPN expression is always valid. That means the expression would always evaluate to a result, and there will not be any division by zero operation.

 

// Example 1:

// Input: tokens = ["2","1","+","3","*"]
// Output: 9
// Explanation: ((2 + 1) * 3) = 9
// Example 2:

// Input: tokens = ["4","13","5","/","+"]
// Output: 6
// Explanation: (4 + (13 / 5)) = 6

#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        stack<unsigned long long int> st;
        for(int i=0;i<tokens.size();i++){
            if(tokens[i]=="+"){
                unsigned long long int op1=st.top();
                st.pop();
                unsigned long long int op2=st.top();
                st.pop();
                st.push(op1+op2);
                
            }
            else if(tokens[i]=="*"){
                unsigned long long int op1=st.top();
                st.pop();
                unsigned long long int op2=st.top();
                st.pop();
                st.push(op1*op2);
            }
            else if(tokens[i]=="-"){
                unsigned long long int op1=st.top();
                st.pop();
                unsigned long long int op2=st.top();
                st.pop();
                st.push(op2-op1);
            }
            else if(tokens[i]=="/"){
                int op1=st.top();
                st.pop();
                int op2=st.top();
                st.pop();
                st.push(op2/op1);
            }
            else{
                unsigned long long int temp=stoi(tokens[i]);
                st.push(temp);
            }
        }
        return st.top();
    }
};