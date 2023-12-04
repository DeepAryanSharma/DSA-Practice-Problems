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
    bool isPalindrome(ListNode* head) {
        //if linked list is empty
        if(head==NULL){
            return true;
        }
        //if only 1 node is present
        if(head->next==NULL){
            return true;
        }

        //if more than 1 nodes are present
        ListNode* slow=head;
        ListNode* fast=head;

        //finding the mid
        while(slow!=NULL && fast!=NULL){
            fast=fast->next;
            if(fast!=NULL){
                fast=fast->next;
                slow=slow->next;
            }
        }
        ListNode* mid=slow;

        //reversing till mid
        ListNode* prev=NULL;
        ListNode* curr=mid;
        ListNode* forward=curr->next;

        while(curr != NULL){
            forward=curr->next;
            curr->next=prev;
            prev=curr;
            curr=forward;
           
        }

        //checking for palindrome
        ListNode* temp1= head;
        ListNode* temp2= prev;
        while(temp2 != NULL){
            if(temp1->val != temp2->val){
                return false;
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        return true;

        
    }
};