#pragma once
#include <string>
struct AVL
{

	std::string key;
	AVL* left ;
	AVL* right;
	AVL() : left(nullptr), right(nullptr) {}

	AVL(std::string data) : key(data), left(nullptr), right(nullptr) {}
	//to-do
	//make a desctructor
};
// adds elements to tree, creating allocating data as needed
AVL* insert( AVL* root, std::string data); 
// Checks balance, and fixes imbalances by calling rotation functions
AVL* balance( AVL* root);
// finds the height of a given node in the tree
int height(AVL* root);
// Finds the difference between left and right subtrees
int difference(AVL* root);
// print using inorder traversal ( left, self, right)
void print_inorder(AVL* root);
// print using pre-order traversal (self, left, right)
void pre_order(AVL* root);
// rotates nodes of the tree to correct the tree height
AVL* left_rotation(AVL* root);
AVL* right_rotation(AVL* root);