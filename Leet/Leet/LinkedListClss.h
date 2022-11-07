#pragma once

// Definition for singly - linked list.
struct ListNode 
{
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class NodeR {
public:
	int val;
	NodeR* next;
	NodeR* random;

	NodeR(int _val) {
		val = _val;
		next = nullptr;
		random = nullptr;
	}
};

class LinkedlistClss
{
	void delete_at_index(ListNode* head, int index);

public:
	ListNode* reverseList(ListNode* head);
	
	ListNode* mergeTwoLists(ListNode* pHead1, ListNode* pHead2);

	void reorderList(ListNode* head);

	ListNode* removeNthFromEnd(ListNode* head, int n);

	bool hasCycle(ListNode* head);

	NodeR* copyRandomList(NodeR* head);

	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};