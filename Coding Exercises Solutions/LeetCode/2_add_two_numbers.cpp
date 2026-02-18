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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int saved = 0;
        int sum = l1->val + l2->val;
        if (sum >= 10)
        {
            sum %= 10;
            saved = 1;
        }

        ListNode *result = new ListNode(sum);

        ListNode *temp = result;
        l1 = l1->next;
        l2 = l2->next;
        // sum both
        while (l1 && l2)
        {
            sum = l1->val + l2->val + saved;
            if (sum >= 10)
            {
                sum %= 10;
                saved = 1;
            }
            else
            {
                saved = 0;
            }
            temp->next = new ListNode(sum);

            temp = temp->next;
            l1 = l1->next;
            l2 = l2->next;
        }

        // add remaining of l1
        while (l1)
        {
            sum = l1->val + saved;
            if (sum >= 10)
            {
                sum %= 10;
                saved = 1;
            }
            else
            {
                saved = 0;
            }
            temp->next = new ListNode(sum);
            temp = temp->next;

            l1 = l1->next;
        }

        // add remaining of l2
        while (l2)
        {
            sum = l2->val + saved;
            if (sum >= 10)
            {
                sum %= 10;
                saved = 1;
            }
            else
            {
                saved = 0;
            }
            temp->next = new ListNode(sum);
            temp = temp->next;

            l2 = l2->next;
        }

        // Check saved number to add a last node
        if (saved == 1)
        {
            temp->next = new ListNode(1);
        }
        return result;
    }
};