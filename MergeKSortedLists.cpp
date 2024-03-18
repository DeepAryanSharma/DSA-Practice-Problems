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

class compare{
    public:
    bool operator()(ListNode* a, ListNode* b){
        return a->val > b->val;
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //create a minHeap
        priority_queue<ListNode*, vector<ListNode*>, compare> minHeap;
        
        int k=lists.size();
        if(k==0){
            return NULL;
        }
        //push the first node of every linked list in the minHeap
        for(int i=0 ; i<k ; i++){
            if(lists[i]){
                minHeap.push(lists[i]);
            }
        }

        //initially for merged linked list
        ListNode* head=NULL;
        ListNode* tail=NULL;

        while(!minHeap.empty()){
            ListNode* temp=minHeap.top();
            minHeap.pop();

            //if it the first node in the answer linked list
            if(head==NULL){
                head=temp;
                tail=temp;
            }
            else{
                tail->next=temp;
                tail=temp;
            }

            //push the next node(if exists) in the minHeap
            if(temp->next){
                minHeap.push(temp->next);
            }
             
            
        }

        return head;
    }
};
