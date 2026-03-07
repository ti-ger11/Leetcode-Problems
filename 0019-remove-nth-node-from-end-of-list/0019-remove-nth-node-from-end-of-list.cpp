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
    int count(ListNode* head)
    {
        int c=0;
        while(head)
        {
            c++;
            head=head->next;
        }
        return c;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //we need second last element to delete the last node
        
        ListNode* temp=head;

        int c=count(head);

        n=c-n+1;

        if(head->next==nullptr)
        {
            return nullptr;
        }

        if(n==1)
        {
            head=head->next;
            return head;
        }

        for(int i=0;i<n-2;i++)
        {
            temp=temp->next;
        }

        if(temp->next!=nullptr&&temp->next->next!=nullptr)
        {
            temp->next=temp->next->next;
        }

        else
        {
            temp->next=nullptr;
        }


        return head;

    
        
    }
};
