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
    int getLen(ListNode* head){
        ListNode* temp=head;
        int len=0;
        while(temp != NULL){
            temp=temp->next;
            len++;

        }
        return len;
    }
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        int len=getLen(head);
        int i=1;
        if(len==1){
            return NULL;
        }
        if(len==n){
            head=head->next;
            return head;

        }

        ListNode* temp=head;
        while(i <= len-n-1){
            temp=temp->next;
            i++;
        }
        if(temp->next !=NULL){
            temp->next=temp->next->next;

        }
        
        return head;
        
    }
};
