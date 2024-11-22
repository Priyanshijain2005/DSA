
bool hasCycle(ListNode *head)
{
    if (head == NULL)
    {
        return false;
    }

    ListNode *slow = head;
    ListNode *fast = head;

    while (slow && fast && fast->next)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
        }
        slow = slow->next;

        if (slow == fast)
        {
            return true;
        }
    }

    return false;
    }