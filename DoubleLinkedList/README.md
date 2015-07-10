# DoubleLinkedList Lab

##Purpose
The purpose of this lab was to write a basic double linked list.  This lab made further use of pointers than the previous linked list lab, while also introducing basic exception handling and the use of templating.

##Core Concepts
1. Makefile use:
	This lab extended the use of makefiles for templated classes.  Use the flag -Wall.
2. Pointers:
	Unlike singly linked lists, double linked lists have two list pointers for easier list traversal in long lists.  As a result, doubly linked lists have certain edge cases that need to be taken care of that are not applicable to single linked lists.
3. Exception Handling:
	Very basic exception handling, essentially replacing conditionals in handling edge cases.
4. Templating:
	By making more generic classes, the number of types used can be greatly expanded.  I don't think that the DoubleLinkedList class is *infinitely* extensible since you then need copy constructors and things, but it's good enough that you should be able to use it for strings.
	
##Issues
1. Since templated header files include the implementation (.hpp) files, you don't include them as a section in the makefile.  Just include the .hpp and .h file as dependencies to the corresponding .o file.

2. I can't find any information on the internet about this convention, but I generally use .hpp as the extension for templated classes.

3.  Be careful when inserting into a linked list.  There are a few edge cases to look out for:
	1. When the list is empty, have both list pointers pointing at the node.  The node's two pointers should be pointing at nullptr.
	2. When inserting at the front or back of the list, create a temp pointer to hold the node the list pointer is holding, then move the list pointer to the new node.  The list pointer should point at the new node, but the new node should *not* point at the list pointer.
	3. Insertion inside the list (not at the front or back) is largely the same as 2), but in this case the new node's pointers need to point at the nodes adjacent to it.  Make sure that all pointers are accounted for or you'll end up with segfaults on segfaults.
	
4. This implementation involved returning node pointers from a function.  The only important note here is when traversing a list using a *while* loop and making comparisons within that loop, the last node is not included for the comparison.  Therefore, there is some code duplication required in order to make sure all nodes are checked.

5.  Removal of a node in a doubly linked list requires four cases:
	1) If the list is empty or the *find* method cannot find the user-specified value, then no search is made.
	2) If the list has only one node, then a node pointer is created to hold the node while the list pointers are cleared.
	3) If the list has more than one node but that node is at the front of the list, a holding node pointer is created and the list pointer is advanced.
	4) If the list has more than one node but that node is at the back of the list, a holding node pointer is created and the list pointer is reversed.
	
6. Make sure all insertion and removal methods increment or decrement the size of the list.  Methods in linked lists generally are fairly dependent on size.

