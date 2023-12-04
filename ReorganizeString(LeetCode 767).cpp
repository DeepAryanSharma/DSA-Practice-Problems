class Solution {
public:
    string reorganizeString(string s) {
        
        //creating a frequency table for all the characters of the string
        int hash[26]={0};
        for(int i=0 ; i<s.length() ; i++){
            hash[s[i] - 'a']++;
        }

        //finding out the most frequently occuring element
        char most_freq_char;
        int max_freq=INT_MIN;
        for(int i=0 ; i<26 ; i++){
            if(hash[i] > max_freq){
                max_freq=hash[i];
                most_freq_char= i+'a';
            }
        }

        //arranging the most frequent character
        int index=0;
        while(max_freq>0 && index<s.length()){
            s[index]=most_freq_char;
            max_freq--;
            index +=2;
        }
        hash[most_freq_char - 'a'] = 0;

        //if all the occurences of the most frequent character are not placed then the rearrangement is not possible
        if(max_freq != 0 ){
            return "";
        }
        
        //now arrange the remaining characters of the string
        for(int i=0 ; i<26 ; i++){
            while(hash[i] > 0){
                if(index >= s.length()){
                    index=1;
                }
                s[index]=i + 'a';
                hash[i]--;
                index +=2;
            }
        } 
        return s;
    }
};