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

    ListNode* reversell(ListNode* x,ListNode* y)
    {
        ListNode* prev=nullptr;

        ListNode* curr=x;

        while(curr!=y)
        {
            ListNode* temp=curr->next;

            curr->next=prev;
            prev=curr;
            curr=temp;
            

        }

        return prev;

    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        // Step 1: Check if k nodes exist using fast pointer

        ListNode* fast=head;

        for(int i=0;i<k;i++)
        {
            if(fast==nullptr)
            {
                return head;
            }
            fast=fast->next;
           
        }
        
        // Step 2: Reverse k nodes in place

        ListNode* newhead=reversell(head,fast);
        
        // Step 3: Recurse on remaining list and connect with the head

        head->next=reverseKGroup(fast,k); //since old head now become the tail



        return newhead;
        

    
    }
};