class Solution {
public:
    int myAtoi(string s) {
        int i=0, num=0, sign=1;

        //ignoring the leading whitespaces
        while(s[i]==' '){
            i++;
        }

        //checking for the sign
       if((i<s.length()) && (s[i]=='-' || s[i]=='+')){
           if(s[i]=='-'){
               sign=-1;
           }
           i++;

       }

        //converting digits into integers
        while(isdigit(s[i]) && i<s.length()){
            if(num>(INT_MAX)/10 || (num==(INT_MAX)/10 && s[i]> '7' )){
                if(sign==-1){
                    return INT_MIN;
                }
                else{
                    return INT_MAX;
                }
                
            }
            num=num*10 + (s[i]-'0');
            i++;
            
        }

        return sign*num;        
    }
};