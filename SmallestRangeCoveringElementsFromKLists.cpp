//creating a data type class to store information of the element 
class Node{
    public:
    int data;
    int row;
    int col;

    Node(int val, int r, int c){
        this->data=val;
        this->row=r;
        this->col=c;
    }
};

class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};
class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<Node*, vector<Node*>, compare> minHeap;

        int mini=INT_MAX;
        int maxi=INT_MIN;

        int k=nums.size();
        //insert first element of every list in the minHeap
        for(int i=0 ; i<k ; i++){
            int element=nums[i][0];
            mini=min(mini, element);
            maxi=max(maxi, element);
            Node* temp=new Node(element, i, 0);
            minHeap.push(temp);
        }

        //initial answer range 
        int ansStart=mini;
        int ansEnd=maxi;

        while(!minHeap.empty()){
            Node* top=minHeap.top();
            minHeap.pop();
            
            int topElement=top->data;
            int topRow=top->row;
            int topCol=top->col;
            //curr mini
            mini=topElement;
            //check for curr range
            if(maxi-mini < ansEnd-ansStart){
                ansStart=mini;
                ansEnd=maxi;
            }

            //push next element 
            if(topCol+1 < nums[topRow].size()){
                maxi=max(maxi, nums[topRow][topCol+1]);
                Node* temp=new Node(nums[topRow][topCol+1], topRow, topCol+1);
                minHeap.push(temp);
            }
            else{
                //if the list is finished
                break;
            }
        }

        vector<int> ans;
        ans.push_back(ansStart);
        ans.push_back(ansEnd);

        return ans;
        
    }
};
