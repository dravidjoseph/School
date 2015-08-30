# Linked List

##Purpose

This lab exists to provide familiarity with pointer manipulation and basic linked data structures for use later on.

##Concepts
1. Nodes: This class creates a structure called a *node*, which is an object containing a value (in our case an integer), and a pointer to one other node.  These nodes are the building blocks of a linked list.
2. Singly Linked List: Consists of a header node that points to the rest of the nodes in the list.  Also contains size of the list
3. Memory Management: We are declaring our nodes as `new`, which means that we end up allocating them on the heap as opposed to the stack.  This means we have to be careful that all our nodes are accounted for.