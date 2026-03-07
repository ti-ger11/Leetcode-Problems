class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy node handles edge case of removing the head cleanly
        ListNode* dummy = new ListNode(0, head);
        
        ListNode* fast = dummy;
        ListNode* slow = dummy;

        // Move fast n+1 steps ahead
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }

        // Move both until fast hits null
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }

        // slow is just before the node to delete
        slow->next = slow->next->next;

        return dummy->next;
    }
};