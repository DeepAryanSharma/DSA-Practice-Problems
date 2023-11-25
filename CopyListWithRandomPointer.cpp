/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head==NULL){
            return NULL;
        }
        //Step-1: Clone A->A'
        Node* it=head;
        while(it != NULL){
            Node* clonedNode= new Node(it->val);
            clonedNode->next=it->next;
            it->next=clonedNode;
            it=it->next->next;
        }

        //Step-2: Assign random links of A' with the help A
        it=head;
        while(it != NULL){
            Node* clonedNode=it->next;
            if(it->random){
                clonedNode->random=it->random->next;
            }
            it=it->next->next;

        }

        //Step-3 Detach A' from A
        it=head;
        Node* newHead=it->next;
        while(it != NULL){
            Node* clonedNode=it->next;
            it->next=it->next->next;
            if(clonedNode->next){
                clonedNode->next=clonedNode->next->next;
            }
            it=it->next;
        }

        return newHead;
        
    }
};
