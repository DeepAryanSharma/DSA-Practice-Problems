class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        //initially
        int stops=0;
        int dist=0;
        int i=0;
        int fuel=startFuel;
        priority_queue<pair<int, int>> maxHeap; //{fuel, pos}

        while(true){
            //travel the maximum posible station using the current fuel and store the in betweeen stations and their fuel info in the maxHeap
            while(i<stations.size()){
                if(stations[i][0] <= dist+fuel){
                    maxHeap.push({stations[i][1], stations[i][0]});
                }
                else{
                    break;
                }
                i++;
            }
            //update the dist and fuel
            dist+=fuel;
            fuel=0;

            //if already reached
            if(dist >= target){
                break;
            }
            //if no station is available within range
            if(maxHeap.empty()){
                stops=-1;
                break;
            }

            //if refuel is required before reaching the target
            pair<int, int> top=maxHeap.top();
            fuel= (dist- top.second) + top.first;
            dist=top.second;
            maxHeap.pop();
            stops++;
        }

        return stops;
        
    }
};
