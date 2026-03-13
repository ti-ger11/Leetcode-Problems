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

    ListNode* reversell(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* curr=head;
        
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;  
    }
    bool isPalindrome(ListNode* A) {
        
        if(A==NULL){return 0;}
        if(A->next==NULL)
        {
            return 1;
        }
        ListNode* fast=A;
        ListNode* slow=A;
        
        while(fast && fast->next)
        {
            fast=fast->next->next;
            slow=slow->next;
        }
        
        ListNode* s= reversell(slow);
        
        //compare
        
        ListNode* c1=A;
        ListNode* c2=s;
        
        while(c2)
        {
            if(c1->val!=c2->val)
            {
                return 0;
            }
            c1=c1->next;
            c2=c2->next;
        }
        
        
        return 1;
        
        
        
        
    }
};


