#pragma once

template<typename T>
struct TreeNode
{
	T element;
	TreeNode* Left_child;
	TreeNode* Right_child;

	TreeNode(T data) {
		this->element = data;
		this->Left_child = nullptr;
		this->Right_child = nullptr;
	}
};

using INT_NODE = TreeNode<int>;

class BinaryTree
{
private:

public:

	INT_NODE* root;

	BinaryTree();

	INT_NODE* create_node(int data);
	int HeightOfTheTree(INT_NODE* root_node);

	int CountNoOfLeaves(INT_NODE* root_node);
	int CountNoOfRootNodes(INT_NODE* root_node);
	int CountTotalNodes(INT_NODE* root_node);

	void PreOrderTraversal(INT_NODE* root_node);
	void InOrderTraversal(INT_NODE* root_node);
	void PostOrderTraversal(INT_NODE* root_node);

	bool SearchAndUpdateNodeVal(INT_NODE* root_node, int val_to_search, int val_to_update);

	void destroySubtree(INT_NODE* currentNode);

	~BinaryTree();
};

class BinarySeacrhTree : public BinaryTree
{
public:
	BinarySeacrhTree();

	INT_NODE* Insert(INT_NODE* root_node ,int data);
	INT_NODE* Search(INT_NODE* root_node, int data);
	INT_NODE* Delete(INT_NODE* root_node, int data);

	INT_NODE* FindMin(INT_NODE* root_node);
	INT_NODE* FindMax(INT_NODE* root_node);

	~BinarySeacrhTree();
};