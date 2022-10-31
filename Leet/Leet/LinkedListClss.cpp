#include "LinkedListClss.h"
#include <string>

ListNode* LinkedlistClss::reverseList(ListNode* head)
{
    ListNode* prev = nullptr;
    ListNode* nxt = nullptr;
    ListNode* curr = head;

    while (curr)
    {

        nxt = curr->next;
        curr->next = prev;

        prev = curr;
        curr = nxt;

    }

    return prev;
}

ListNode* LinkedlistClss::mergeTwoLists(ListNode* pHead1, ListNode* pHead2) {

    ListNode* dummy = new ListNode(0, nullptr);
    ListNode* tail_ptr = dummy;

    if (pHead1 == nullptr)
    {
        return pHead2;
    }
    else if (pHead2 == nullptr)
    {
        return pHead1;
    }

    while (pHead1 && pHead2)
    {
        if (pHead1->val < pHead2->val)
        {
            tail_ptr->next = pHead1;
            pHead1 = pHead1->next;
        }
        else
        {
            tail_ptr->next = pHead2;
            pHead2 = pHead2->next;
        }

        tail_ptr = tail_ptr->next;
    }

    if (pHead1)
    {
        tail_ptr->next = pHead1;
    }
    else if (pHead2)
    {
        tail_ptr->next = pHead2;
    }

    return dummy->next;
}

void LinkedlistClss::reorderList(ListNode* head)
{

    ListNode* p = head;

    while (p)
    {
        auto t = p->next;
        ListNode* prev_node = nullptr;

        //find till last node
        while (t && t->next)
        {
            prev_node = t;
            t = t->next;
        }

        if (prev_node)
        {
            //After finding the last node
            prev_node->next = nullptr;
            t->next = p->next;
            p->next = t;
        }

        if (t)
            p = t->next;
        else
            p = nullptr;
    }
}
