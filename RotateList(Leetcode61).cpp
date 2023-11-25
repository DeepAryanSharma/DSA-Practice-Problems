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
    int findLen(ListNode* head){
        int len=0;
        ListNode* temp=head;
        while(temp != NULL){
            temp=temp->next;
            len++;
        }
        return len;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        //if list is empty
        if(head==NULL){
            return head;
        }
        int len=findLen(head);
        int i=0;
        
        //actual unique rotations
        k=k%len;
        if(k==0){
            //list will remain same after rotation
            return head;
        }
        
        ListNode* prev=head;
        while(i < len-k-1){
            prev=prev->next;
            i++;
        }
        ListNode* newHead=prev->next;
        prev->next=NULL;

        ListNode* temp=newHead;
        while(temp->next!= NULL){
            temp=temp->next;
        }

        temp->next=head;

        return newHead;
        



        
    }
};
