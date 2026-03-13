/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head==nullptr)
        {
            return head;
        }
        ListNode * slow=head;
        ListNode * fast=head;

        bool flag=false;

        while(fast!=nullptr&&fast->next!=nullptr)
        {
            fast=fast->next->next;
            slow=slow->next;
            if(fast==slow)
            {
                flag=true;
                break;

            }
        }

        if(flag==false)
        {
            return nullptr;
        }

        slow=head;

        while(fast!=slow)
        {
            slow=slow->next;
            fast=fast->next;
        }

        return slow;


        
    }
};