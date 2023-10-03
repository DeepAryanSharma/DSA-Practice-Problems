class Solution {
public:
    bool isVowel(char ch){
        ch=tolower(ch);
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u'){
            return true;
        }
        return false;
    }
    string reverseVowels(string s) {

        int low=0;
        int high=s.length()-1;

        while(low<=high){
            if(!isVowel(s[low])){
                low++;
            }
            else if(!isVowel(s[high])){
                high--;
            }
            else{
                swap(s[low], s[high]);
                low++;
                high--;
            }
        }

        return s;
        
    }
};