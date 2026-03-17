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

    ListNode* reversell(ListNode* head,ListNode* end)
    {
        ListNode* prev=nullptr;
        ListNode* curr=head;
        while(curr!=end)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }

        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {

        int temp=k;

        ListNode* fast=head;

        while(temp)
        {
            if(fast==nullptr)
            {
                return head;
            }
            fast=fast->next;
            temp--;
        }

        ListNode* newhead=reversell(head,fast);

        head->next=reverseKGroup(fast,k);


        return newhead;


        
    }
};