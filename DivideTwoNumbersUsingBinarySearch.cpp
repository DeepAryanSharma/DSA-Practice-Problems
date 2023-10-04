class Solution {
public:
    int divide(int dividend, int divisor) {

        long long s=0;
        long long e=abs(dividend);
        long long mid=s+(e-s)/2;
        long long ans=0;
        while(s<=e){
            // Handle edge cases
            if(divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
            return INT_MAX;
            }
            if(abs(divisor*mid)==abs(dividend)){
                //found the ans
                ans= mid;
                break;
            }

            if(abs(divisor*mid)<abs(dividend)){
                //this is a possbile ans so store it in the ans
                ans=mid;
                //further search in right 
                s=mid+1;
            }
            else{
                //this is not a possible ans
                e=mid-1;
            }

            
            mid=s+(e-s)/2;
        }
        //determining the sign of the ans
        if((dividend>0 && divisor>0) || (dividend<0 && divisor<0)){
            return ans;
        }
        else{
            return -ans;
        }
        
    }

};