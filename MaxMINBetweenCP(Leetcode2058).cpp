/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> ans={-1,-1};

        
        ListNode* prev=head;
        if(prev==NULL){
            return ans;
        }

        ListNode* curr=prev->next;
        if(curr==NULL){
            return ans;
        }

        ListNode* nxt=curr->next;
        if(nxt==NULL){
            return ans;
        }

        int firstCP=-1;
        int minDist=INT_MAX;
        int lastCP=-1;
        int i=1;

        while(nxt !=NULL){
            bool isCP=false;
            if((curr->val > prev->val && curr->val > nxt->val) || (curr->val < prev->val && curr->val < nxt->val)){
               isCP=true;
            }

            if(isCP && firstCP==-1){
                firstCP=i;
                lastCP=i;
            }
            else if(isCP){
                minDist=min(minDist, i-lastCP);
                lastCP=i;
            }

            i++;
            prev=prev->next;
            curr=curr->next;
            nxt=nxt->next;
        }

        if(firstCP==lastCP){
            //only 1 CP
            return ans;
        }
        else{
            ans[0]=minDist;
            ans[1]=lastCP-firstCP;
        }
            
        

        return ans;
           
        
    
        
        
    }
};