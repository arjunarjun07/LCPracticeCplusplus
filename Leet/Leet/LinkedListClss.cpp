#include "LinkedListClss.h"
#include <string>
#include <map>
#include <unordered_map>

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

void LinkedlistClss::delete_at_index(ListNode* head, int index)
{
    if (!head)
    {
        return;
    }

    ListNode* curr = head;
    ListNode* prev = nullptr;

    int indx_countr = 1;
    while (curr && indx_countr < index)
    {
        indx_countr++;
        prev = curr;
        curr = curr->next;
    }

    if (prev && curr)
    {
        prev->next = curr->next;
        delete(curr);
    }
}

ListNode* LinkedlistClss::removeNthFromEnd(ListNode* head, int n)
{
    ListNode* left = head, * right = head;

    while (n--)
    {
        right = right->next;
    }

    if (!right) //Try two nodes with n = 2 to understand this line
        return head->next;
    
    while (right->next) 
    {
        left = left->next;
        right = right->next;
    }
    
    ListNode* toDelete = left->next;
    left->next = left->next->next;
    
    delete toDelete;
    
    return head;
}

bool LinkedlistClss::hasCycle(ListNode* head)
{
    bool hascycle = false;

    std::map<long int, int> hashmap;

    ListNode* ptr = head;

    while (ptr)
    {
        int addr = (long int)&(*ptr);

        if (hashmap.find(addr) == hashmap.end())
        {
            hashmap.insert(std::pair{ addr, ptr->val});
            ptr = ptr->next;
        }
        else
        {
            //cycle found
            hascycle = true;
            break;
        }
    }

    return hascycle;
}

NodeR* LinkedlistClss::copyRandomList(NodeR* head)
{
    NodeR* p = head;


    NodeR* dummy_h = new NodeR(-1);
    NodeR* new_list_head = dummy_h;

    std::map<NodeR*, int> old_list;
    std::map<int, NodeR*> new_list;
    
    //create new nodes & duplicate the links exactly as the source
    int index = 0;
    while (p)
    {
        NodeR* new_node = new NodeR(p->val);

        dummy_h->next = new_node;
        dummy_h = dummy_h->next;


        old_list.insert({p, index});
        new_list.insert({index, new_node});

        p = p->next;
        index++;
    }


    //make random pointers links of src list similar in the new list
    p = head;
    NodeR* new_n = new_list_head->next;

    while (p)
    {
        if (p->random)
        {
            int i = old_list[p->random];
            new_n->random = new_list[i];
        }
        else
        {
            new_n->random = nullptr;
        }
        
        new_n = new_n->next;
        p = p->next;
    }

    //delete head node
    if (new_list_head)
    {
        NodeR* temp = new_list_head;
        new_list_head = new_list_head->next;

        delete temp;
    }

    return new_list_head;
}

ListNode* LinkedlistClss::addTwoNumbers(ListNode* l1, ListNode* l2)
{
    int carry = 0;

    ListNode* dummy = new ListNode(0, nullptr);
    ListNode* dummy_head_ptr = dummy;

    ListNode* NewNode = nullptr;

    while (l1 && l2)
    {
        int sum_of_digits = l1->val + l2->val + carry;

        if (sum_of_digits <= 9)
        {
            carry = 0;
            NewNode = new ListNode(sum_of_digits, nullptr);
        }
        else
        {
            NewNode = new ListNode(sum_of_digits % 10, nullptr);
            carry = sum_of_digits / 10;
        }

        dummy->next = NewNode;
        dummy = dummy->next;

        l1 = l1->next;
        l2 = l2->next;
    }

    //if carry != 0 or list 1 || list2 not empty

    if (l1)
    {
        while (l1)
        {
            int sum_of_digits = l1->val + carry;

            if (sum_of_digits <= 9)
            {
                carry = 0;
                NewNode = new ListNode(sum_of_digits, nullptr);
            }
            else
            {
                NewNode = new ListNode(sum_of_digits % 10, nullptr);
                carry = sum_of_digits / 10;
            }

            dummy->next = NewNode;
            dummy = dummy->next;

            l1 = l1->next;
        }
    }
    else if(l2)
    {
        while (l2)
        {
            int sum_of_digits = l2->val + carry;

            if (sum_of_digits <= 9)
            {
                carry = 0;
                NewNode = new ListNode(sum_of_digits, nullptr);
            }
            else
            {
                NewNode = new ListNode(sum_of_digits % 10, nullptr);
                carry = sum_of_digits / 10;
            }

            dummy->next = NewNode;
            dummy = dummy->next;

            l2 = l2->next;
        }
    }

    if (carry != 0 && (l1 == nullptr && l2 == nullptr))
    {
        NewNode = new ListNode(carry, nullptr);
        dummy->next = NewNode;
        dummy = dummy->next;
    }

    if (dummy_head_ptr->next)
    {
        ListNode* temp = dummy_head_ptr;

        dummy_head_ptr = dummy_head_ptr->next;

        delete temp;
    }

    return dummy_head_ptr;
}