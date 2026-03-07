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

    ListNode* findmid(ListNode* head)
    {
        ListNode* slow=head;
        ListNode* fast=head;

        while(fast!=nullptr&&fast->next!=nullptr)
        {
            slow=slow->next;
            fast=fast->next->next;
        }

        return slow;
    }

    void reversell(ListNode* &x)
    {
        ListNode* prev=nullptr;
        ListNode* curr=x;
        while(curr)
        {
            ListNode* temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        //prev is the revese list

        x=prev;
    }

    void merge2LL( ListNode* &l1, ListNode* &l2)
    {
        

        while(l1&&l2)
        {
            ListNode* temp1=l1->next;
            ListNode* temp2=l2->next;
            l1->next=l2;
            l2->next=temp1;

            l1=temp1;
            l2=temp2;

           
        }
    }
    void reorderList(ListNode* head) {

        if(!head || !head->next) return;


        //find mid element
        ListNode* mid=findmid(head);

        ListNode* curr=mid->next;

        //split into two

        mid->next=nullptr;

        //reverse 2nd half

        reversell(curr);


        //merge two linked list

        merge2LL(head,curr);

        
    }
};
