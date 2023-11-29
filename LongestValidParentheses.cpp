class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        //initially
        st.push(-1);
        int maxLen=0;

        for(int i=0 ; i<s.length() ; i++){
            //opening bracket
            if(s[i]=='('){
                st.push(i);
            }
            else{
                //closing bracket
                st.pop();
                if(st.empty()){
                    st.push(i);
                }
                else{
                    int len=i-st.top();
                    if(len>maxLen){
                        maxLen=len;
                    }
                }
            }
        }
        return maxLen;
        
    }
};
