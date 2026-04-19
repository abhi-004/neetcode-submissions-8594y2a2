class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string c: tokens){
            if (c=="+" || c=="-" || c=="*" || c=="/"){
                int num1 = st.top(); 
                st.pop();

                int num2 = st.top();
                st.pop();

                if (c == "+") { st.push(num1 + num2); } 
                if (c == "-") { st.push(num2 - num1); }
                if (c == "*") { st.push(num1 * num2); }
                if (c == "/") { st.push(num2 / num1); }
                }
                else { st.push(stoi(c)); }
        }
        return st.top();
    }
};
