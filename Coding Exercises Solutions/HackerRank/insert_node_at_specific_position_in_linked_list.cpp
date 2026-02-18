SinglyLinkedListNode *insertNodeAtPosition(SinglyLinkedListNode *llist,
                                           int data, int position)
{
    if (position == 0)
    {
        SinglyLinkedListNode *temp = new SinglyLinkedListNode(data);
        temp->next = llist;
        return temp;
    }
    else
    {
        int count = 1;
        SinglyLinkedListNode *temp = llist;
        while (temp->next != nullptr && count < position)
        {
            temp = temp->next;
            count++;
        }
        if (count < position)
            return nullptr;

        // Insert after temp
        SinglyLinkedListNode *inserted = new SinglyLinkedListNode(data);
        inserted->next = temp->next;
        temp->next = inserted;
        return llist;
    }
}

// HackerRank solution (given position is always valid)
SinglyLinkedListNode *insertNodeAtPosition(SinglyLinkedListNode *llist,
                                           int data, int position)
{
    if (position == 0)
    {
        SinglyLinkedListNode *temp = new SinglyLinkedListNode(data);
        temp->next = llist;
        return temp;
    }
    else
    {
        SinglyLinkedListNode *temp = llist;

        // position is always valid in hackerrank
        for (int count = 1; count < position; count++)
            temp = temp->next;

        // Insert after temp
        SinglyLinkedListNode *inserted = new SinglyLinkedListNode(data);
        inserted->next = temp->next;
        temp->next = inserted;
        return llist;
    }
}