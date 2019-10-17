## This project is created to show the reusability of the code and is separated in such files to be easily maintained

I first create a Binary Tree on which every other data structure directly or undirectly is based on

Firstly  a Binary Tree is implemented
Based on the binary tree a Binary Search Tree is created
Based on the Binary Search Tree a Complete Binary Tree is implemented
Based on the Complete Binary Tree a Binary Heap is created
Based ont Binary Heap a Priority Queue is implemented

There are some main directories in which a makefile is included as well as a main function for testing and the item the user
wants to use

In the modules directory all of the functions for each data structure are implemented is the directory with the respective name
Every directory includes an .h file which includes the item type of the data structure the current data structured is
based on
(for example BST is based on BT so in the directory binary-search-tree the is a file btModuleTypes.h which defines 
the item type for the BT function in the binary-tree directory which is inluced through the makefile)

