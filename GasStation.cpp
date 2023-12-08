class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        //initially
        int balance =0;
        int deficiency=0;
        int start=0;

        for(int i=0; i<gas.size() ; i++){
            //calculate balance
            balance += gas[i]-cost[i];

            //if not possible
            if(balance<0){
                //update deficiency
                deficiency += abs(balance);
                //update new start
                start=i+1;
                //reset balance
                balance=0;
            }
        }
        //check if this starting point is possible
        if(balance>=deficiency){
            return start;
        }
        else{
            return -1;
        }
        
    }
};
