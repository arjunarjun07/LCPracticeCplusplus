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

class LinkedlistClss
{
public:
	ListNode* reverseList(ListNode* head);
	
	ListNode* mergeTwoLists(ListNode* pHead1, ListNode* pHead2);

	void reorderList(ListNode* head);
};