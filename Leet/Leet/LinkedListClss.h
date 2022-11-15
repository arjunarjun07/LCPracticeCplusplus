#pragma once
#include <unordered_map>
#include <vector>

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

class LRUCache
{
	struct DLL
	{
		int key = -1;
		int data = -1;
		DLL* prev = nullptr;
		DLL* nxt = nullptr;

		DLL(int key, int val)
		{
			this->key = key;
			data = val;
		}

		~DLL()
		{			
		}
	};

	int cache_capacity = 0;
	std::unordered_map<int, DLL*> cache_map;

	DLL* front = nullptr; //MRU
	DLL* back = front; //LRU

	void AddNode(int key, int value) // Add front
	{
		DLL* node = new DLL(key, value);
		cache_map.insert({ key, node });

		if (front)
		{
			node->nxt = front;
			front->prev = node;
			front = node;
		}
		else
		{
			front = node;
			back = node;
		}
	}

	void DeleteNode(DLL* node_ptr) //delete back
	{
		if (node_ptr)
		{
			(node_ptr->prev)? node_ptr->prev->nxt = node_ptr->nxt : nullptr;
			(node_ptr->nxt)? node_ptr->nxt->prev = node_ptr->prev : nullptr;
		}

		if (node_ptr == back)
		{
			back = back->prev;
		}

		if (node_ptr == front)
		{
			front = front->nxt;
		}

		cache_map.erase(node_ptr->key);
		delete node_ptr;
	}

public:
	LRUCache(int capacity) {
		cache_capacity = capacity;
	}

	int get(int key)
	{
		int res = -1;

		auto itr = cache_map.find(key);

		if (itr != cache_map.end())
		{
			DLL* curr_node = itr->second;
			if (curr_node)
			{
				res = itr->second->data;

				if (curr_node == front)
				{
					return res;
				}
				else
				{
					int k = curr_node->key;
					int val = curr_node->data;

					DeleteNode(curr_node);
					AddNode(k, val);
				}
			}
		}

		return res;
	}

	void put(int key, int value) 
	{
		auto itr = cache_map.find(key);

		if (itr != cache_map.end())
		{
			itr->second->data = value;

			int k = itr->second->key;
			int val = itr->second->data;
			DeleteNode(itr->second);
			AddNode(k, val);
		}
		else
		{
			if (cache_map.size() < cache_capacity)
			{
				AddNode(key, value);
			}
			else
			{
				//evict LRU key
				DeleteNode(back);
				AddNode(key, value);
			}
		}
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

	void TestLRUCache();

	ListNode* mergeKLists(std::vector<ListNode*>& lists);

	ListNode* reverseKGroup(ListNode* head, int k);
};