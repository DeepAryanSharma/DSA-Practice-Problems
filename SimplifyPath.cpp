class Solution {
public:
    void buildAns(stack<string> &s, string &ans){
        if(s.empty()){
            return;
        }

        string top=s.top();
        s.pop();
        buildAns(s,ans);
        ans += top;
    }
    string simplifyPath(string path) {
        stack<string> s;
        int i=0;
        while(i<path.size()){
            int start=i;
            int end=i+1;
            while(end<=path.size() && path[end]!='/'){
                end++;
            }
            string minPath=path.substr(start, end-start);
            i=end;

            if(minPath== "/." || minPath== "/"){
                continue;
            }
            else if(minPath !="/.."){
                s.push(minPath);
            }
            else if(!s.empty()){
                s.pop();
            }
            
        }

        if(s.empty()){
            return "/";
        }
        else{
            string ans="";
            buildAns(s,ans);

            return ans;
        }

        

        
        
    }
};
