#SortingSuite Lab

This time-consuming lab has three main concepts: Recursive sorts, File I/O, and command-line arguments.

##Recursive sorts

Along with three of the four sorts given in the Sorts Lab (no bogo sort), we add two: merge sort and quicksort.  Unlike our previous iterative sorts (meaning they used loops), these sorts use recursion (calling themselves repeatedly).  This makes them more efficient for sorting large arrays, as our iterative sorts clearly got unwieldy.  

You can find writeups on the sorts on dravidjoseph.com, pending editing (they're really long).

##File I/O 

File objects aren't bad to use, but have some different specifications.  The big thing to realize is that files need to be open and then closed after use to be properly used.  The other thing to note is that when you open a file, the name of the file and the name of the file object are two separate items.  You need to make sure you're interacting with the file object, not the file name, because ultimately the file name isn't used much in the actual code..

You read from a file using `fileObject >> thing_to_be_read;` and write using `fileObject << thing_to_read`.  If you want to check whether the file is accessible, the syntax `fileObject.good()` will return a boolean depending on the accessibility of the file.  That's pretty much all you need to get through this lab.

##Command-line arguments

When you start the program by using this line or something like it `./Program arg1 arg2 arg3 arg4`.  Those args get stored in a 2D character array called `argv` (assuming your main function is set up for it, of course).  The best way to access the arguments is by accessing them via string: `std::string argument1 = argv[index]` where the zeroth index is `./Program` and the indices correspond sequentially.  You can then do necessary comparisons and so on. You can access the number of arguments using the `argc` parameter, of course.

##Function Pointers

See code for example.

##Issues

1) You can't use switch statements on strings.  Use enumerated types, or conditionals.
2) You should find a better way to convert strings to integers


