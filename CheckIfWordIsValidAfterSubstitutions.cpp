class Solution {
public:
    bool isValid(string s) {
        if(s[0] != 'a'){
            return false;
        }

        stack<int> st;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i]=='a'){
                //simply push
                st.push(s[i]);
            }
            else if(s[i]=='b'){
                //push only when the top is 'a'
                if(!st.empty() && st.top()=='a'){
                    st.push(s[i]);
                }
                else{
                    return false;
                }
            }
            //if next character is 'c'
            else{
                //pop the b then a
                if(!st.empty() && st.top()=='b'){
                    st.pop();
                    if(!st.empty() && st.top()=='a'){
                        st.pop();
                    }
                    else{
                        return false;
                    }
                }
                else{
                    return false;
                }
            }
        } 
        if(st.empty()){
            return true;
        }

        return false; 
        
    }
};
