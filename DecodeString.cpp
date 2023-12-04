class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        for(auto ch:s){
            //if next character is a closing bracket
            if(ch==']'){
                //make string of all characters and strings till the opening bracket
                string repeatingString="";
                while(!st.empty() && st.top() != "["){
                    repeatingString += st.top();
                    st.pop();
                }
                //pop the opening bracket
                st.pop();
                //construct the number
                string numericTimes="";
                while(!st.empty() && isdigit(st.top()[0])){
                    numericTimes += st.top();
                    st.pop();
                }
                reverse(numericTimes.begin(), numericTimes.end());
                //converting the string type number to integer type
                int n= stoi(numericTimes);
                
                //decode the current string
                string currentDecode="";
                while(n--){
                    currentDecode += repeatingString;
                }
                //push the decoded string in the stack for further decoding
                st.push(currentDecode);
                
            }
            else{
                //simply push all the characters and string other than the closing bracket
                //convert the char type characters to string type bcoz the stack is of string type
                string temp="";
                temp +=ch;
                st.push(temp);
            }
        }
        //construct the answer
       string ans="";
       while(!st.empty()){
           ans +=st.top();
           st.pop();
       }   
       reverse(ans.begin(),ans.end());
       return ans;
    }
};
