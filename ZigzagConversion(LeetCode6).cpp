class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1){
            return s;
        }

        string ans="";

        //storing the characters of the given string in the zigzag patter
        vector<string> zigzag(numRows);
        //chr-> index of the character of the string to be inserted
        //i-> index of the string of the zigzag vector

        int chr=0;
        while(chr<s.size()){
            //inserting top to bottom
            for(int i=0 ; i<numRows && chr<s.size() ; i++){
                zigzag[i].push_back(s[chr]);
                chr++;
            }

            //inserting diagonally
            for(int i=numRows-2 ; i>0 && chr<s.size() ; i--){
                zigzag[i].push_back(s[chr]);
                chr++;
            }
        }

        for(auto str:zigzag){
            ans += str;
        }
        
        return ans;
    }
};