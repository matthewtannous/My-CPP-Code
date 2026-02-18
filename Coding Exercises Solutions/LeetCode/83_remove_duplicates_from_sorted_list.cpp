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
class Solution
{
  public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        for (ListNode *trav = head; trav && trav->next; trav = trav->next)
        {
            while (trav->next && trav->val == trav->next->val)
            {
                // delete next
                ListNode *temp = trav->next;
                trav->next = temp->next;
                delete temp;
            }
        }

        return head;
    }
};