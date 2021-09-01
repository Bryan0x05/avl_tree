#include <iostream>
#include <fstream>
#include <string>
#include "AVL.h"
int main(int argc, char* argv[])
{
	/*
	std::string word;
	std::ifstream infile;
	infile.open("words.txt");

	if (!infile.is_open())
	{ 
		std::cerr << "Error opening file\n";
		return -1;
	}
	//while next character is not equal to END OF FILE character
	while (infile.peek() != EOF)
	{
		std::getline(infile, word);
	}
	*/
	AVL* root(nullptr);
	std::string arr[] = {"F","G","H"};
	for (int index = 0; index < (sizeof(arr) / sizeof(arr[0])); index++)
	{
		root = insert(root, arr[index]);
	}
	std::cout << "inorder': ";
	print_inorder(root);
	std::cout << std::endl << "preorder: ";
	pre_order(root);
	std::cout << std::endl;
	std::cout << std::endl;
	return 0;
}
