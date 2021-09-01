#include "AVL.h"
#include <iostream>
AVL* insert( AVL* root, std::string data)
{
	if (root == nullptr)
	{
		root = new AVL(data);
	}
	else if (root->key > data)
	{
		root->left = insert(root->left, data);
	}
	else if (root->key < data)
	{
		root->right = insert(root->right, data);
	}
	root = balance(root); //FIX BALANCE!!!!
	return root;
}

AVL* balance(AVL* root)
{
	// height left subtree - height right subtree
	
	// balance < -1 = right subtree too tall
	
	int balance_factor = difference(root);
	// balance > 1 = left subtree too tall
	if (balance_factor > 1)
	{
		// if its an outer node
		if (difference(root->left) > 0)
		{
			right_rotation(root);
		}
		//inner node
		else
		{
			left_rotation(root->left);
			right_rotation(root);
		}
	}
	else if (balance_factor < -1)
	{
		if (difference(root->right) < 0)
		{
			left_rotation(root);
		}
		else
		{

			right_rotation(root->right);
			left_rotation(root);
		}
	}
	return root;
}

int height(AVL* root)
{
	// if root is empty, then height = 0
	if (root == nullptr)
	{
		return 0;
	}
	else if (height(root->left) >= height(root->right))
	{
		return 1 + height(root->left);
	}
	else
	{
		return 1 + height(root->right);
	}
}

int difference(AVL* root)
{
	return height(root->left) - height(root->right);
}


AVL* left_rotation(AVL* root)
{
	// balance > 1 = left subtree too tall, right rotation
	AVL* temp;
	temp = root->right;
	root->right = temp->left;
	temp->left = root;
	return temp;
}
AVL* right_rotation(AVL* root)
{
	AVL* temp;
	temp = root->left;
	root->left = temp->right;
	temp->right = root;
	return temp;
}
void print_inorder(AVL* root)
{
	if (root == nullptr)
		return;
	print_inorder(root->left);
	std::cout << root->key << ", ";
	print_inorder(root->right);
}
void pre_order(AVL* root)
{
	if (root == nullptr)
		return;
	std::cout << root->key << ", ";
	pre_order(root->left);
	pre_order(root->right);
}