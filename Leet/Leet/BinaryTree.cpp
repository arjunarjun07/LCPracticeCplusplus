#include "BinaryTree.h"
#include <iostream>

using namespace std;

BinaryTree::BinaryTree()
{
	root = nullptr;
}

INT_NODE* BinaryTree::create_node(int data) 
{
	// Creates a new node
	INT_NODE* node = new INT_NODE(data);

	return node;
}

int BinaryTree::HeightOfTheTree(INT_NODE* root_node)
{
	int h = 0;

	if (root_node == nullptr)
	{
		return h;
	}
	else
	{
		// Find the height of left, right subtrees
		int left_height = HeightOfTheTree(root_node->Left_child);
		int right_height = HeightOfTheTree(root_node->Right_child);

		// Find max(subtree_height) + 1 to get the height of the tree
		return max(left_height, right_height) + 1;
	}

	return h;
}

void BinaryTree::PreOrderTraversal(INT_NODE* root_node)
{
	if (root_node)
	{
		cout << " " << root_node->element;
		PreOrderTraversal(root_node->Left_child);
		PreOrderTraversal(root_node->Right_child);
	}
}

void BinaryTree::InOrderTraversal(INT_NODE* root_node)
{
	if (root_node)
	{
		InOrderTraversal(root_node->Left_child);
		cout << " " << root_node->element;
		InOrderTraversal(root_node->Right_child);
	}
}

void BinaryTree::PostOrderTraversal(INT_NODE* root_node)
{
	if (root_node)
	{
		PostOrderTraversal(root_node->Left_child);
		PostOrderTraversal(root_node->Right_child);
		cout << " " << root_node->element;
	}
}

int BinaryTree::CountNoOfLeaves(INT_NODE* root_node)
{
	if (root_node && (root_node->Left_child != nullptr || root_node->Right_child != nullptr))
	{
		return (CountNoOfLeaves(root_node->Left_child) + CountNoOfLeaves(root_node->Right_child));
	}
	else if (root_node && root_node->Left_child == nullptr && root_node->Right_child == nullptr)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

int BinaryTree::CountNoOfRootNodes(INT_NODE* root_node)
{
	if (root_node && (root_node->Left_child != nullptr || root_node->Right_child != nullptr))
	{
		return (1 + CountNoOfRootNodes(root_node->Left_child) + CountNoOfRootNodes(root_node->Right_child));
	}
	else
	{
		return 0;
	}
}

int BinaryTree::CountTotalNodes(INT_NODE* root_node)
{
	if (root_node)
	{
		return (1 + CountTotalNodes(root_node->Left_child) + CountTotalNodes(root_node->Right_child));
	}
	else
	{
		return 0;
	}
}

void BinaryTree::destroySubtree(INT_NODE* currentNode)
{
	//deleting the nodes of a tree should be done from leaves
	//so following post order traversal

	if (currentNode != nullptr) {
		
		destroySubtree(currentNode->Left_child);
		destroySubtree(currentNode->Right_child);

		delete currentNode;
		currentNode = nullptr;
	}
}

BinaryTree::~BinaryTree()
{
	destroySubtree(root);
}

bool BinaryTree::SearchAndUpdateNodeVal(INT_NODE* root_node, int val_to_search, int val_to_update)
{
	if (root_node)
	{
		if (root_node->element == val_to_search)
		{
			cout << "Node found - updating val from " << val_to_search << " - to - " << val_to_update;
			root_node->element = val_to_update;

			return true;
		}
		else
		{
			/* then recur on left subtree */
			bool res1 = SearchAndUpdateNodeVal(root_node->Left_child, val_to_search, val_to_update);
			// node found, no need to look further
			if (!res1)
			{
				/* node is not found in left,
				so recur on right subtree */
				res1 = SearchAndUpdateNodeVal(root_node->Right_child, val_to_search, val_to_update);
			}

			return res1;
		}
	}
	else
	{
		return false;
	}
}

BinarySeacrhTree::BinarySeacrhTree() : BinaryTree()
{

}

INT_NODE* BinarySeacrhTree::Insert(INT_NODE* root_node, int data)
{
	if (root_node)
	{
		if (data <= root_node->element)
		{
			root_node->Left_child = Insert(root_node->Left_child, data);
		}
		else
		{
			root_node->Right_child = Insert(root_node->Right_child, data);
		}

		return root_node;
	}
	else
	{
		root_node = create_node(data);
	}

	return root_node;
}

INT_NODE* BinarySeacrhTree::Search(INT_NODE* root_node, int data)
{
	if (root_node)
	{
		if (root_node->element == data)
		{
			return root_node;
		}

		if (data < root_node->element)
		{
			return Search(root_node->Left_child, data);
		}
		else if (data > root_node->element)
		{
			return Search(root_node->Right_child, data);
		}
	}
	else
	{
		return nullptr;
	}
}

INT_NODE* BinarySeacrhTree::FindMin(INT_NODE* root_node)
{
	INT_NODE* temp = nullptr;

	while (root_node)
	{
		temp = root_node;
		root_node = root_node->Left_child;
	}

	return temp;
}

INT_NODE* BinarySeacrhTree::FindMax(INT_NODE* root_node)
{
	INT_NODE* temp = nullptr;

	while (root_node)
	{
		temp = root_node;
		root_node = root_node->Right_child;
	}

	return temp;
}

INT_NODE* BinarySeacrhTree::Delete(INT_NODE* root_node, int data)
{
	// Return if the tree is empty
	if (root_node == nullptr) 
		return root_node;

	// Find the node to be deleted
	if (data < root_node->element)
	{
		root_node->Left_child = Delete(root_node->Left_child, data);
	}
	else if (data > root_node->element)
	{
		root_node->Right_child = Delete(root_node->Right_child, data);
	}
	else 
	{
		//Found the node - delete based on the child count
		/*
		* 0 child node
		* 1 child node
		* 2 child node
		*/

		if (root_node->Left_child == nullptr && root_node->Right_child == nullptr)
		{
			//0 child node 

			INT_NODE* temp = root_node;
			free(temp);

			return nullptr;
		}
		else if (root_node->Left_child != nullptr && root_node->Right_child == nullptr)
		{
			// 1 child node - Left child present

			INT_NODE* temp = root_node->Left_child;
			
			free(root_node);
			return temp;

		}
		else if (root_node->Left_child == nullptr && root_node->Right_child != nullptr)
		{
			// 1 child node - Right child present

			INT_NODE* temp = root_node->Right_child;

			free(root_node);
			return temp;

		}
		else
		{
			// 2 child node

			// If the node has two children - Inorder successor
			INT_NODE* temp = FindMin(root_node->Right_child);

			// Place the inorder successor in position of the node to be deleted
			root_node->element = temp->element;

			// Delete the inorder successor
			root_node->Right_child = Delete(root_node->Right_child, temp->element);
		}
	}

	return root_node;
}

BinarySeacrhTree::~BinarySeacrhTree()
{
}
