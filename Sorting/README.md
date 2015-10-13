#Purpose

This lab introduces some basic sorting techniques.  The sorts we'll deal with in this lab are pretty basic, iterative sorts that ultimately are pretty inefficient, but they're a good starting point. All the sorts will be contained within one method, with certain common behaviors moved into helper methods.

#Sorts

*Note*: Don't worry about the assert statement-this functions as a debugging check at the end of the method to make sure it sorts properly.  

1. **Bubble Sort**: Also known as *sinking sort*, this sort works by starting at the beginning of the array and comparing every element of the array against each other, swapping the elements in order to get the array sorted.

	My implementation contains a *for* loop nested inside a *while* loop.  Usually there are certain benefits for choosing one over the other (cleanliness mainly).  You really could go either way here since bubble sort will take at most *n-1* passes in an array of size *n*.  I use a boolean value, *swapped* as the condition for running the loop, which ensures that once the array is sorted we don't start a new pass through the array.  In short, the *while* loop just controls whether or not we need to pass through the array again.
	
	When we enter the *while* loop our flag is set to *true*.  Once we enter the body, we immediately set it to *false*.  If at any time during the pass we perform a swap, then we'll set the flag back to *true* and do another pass.  Otherwise, we can end the sort-the array is sorted.
	
	We also create a counter *i* that will shorten the amount of array that is searched through.  Just set it to zero for now.  
	
	Within our inner *for* loop, we start by comparing the elements *arr[0]* and *arr[1]*, swapping if *arr[0]&gtarr[1]*.  We then compare *arr[1]* and *arr[2]*, etc. until we get to *arr[n-1]* to *arr[n]*, swapping as necessary. The swap is placed in an *if* statement with the comparison as its condition-we also switch the flag to true if any swaps occur, because we'll need to do another pass.  At the end of all these swaps, the maximum value is guaranteed to be at the correct index.  
	
	This is why our value *i* is important.  We can guarantee that the *n*th pass will have the last $n$ values sorted, so by using *i* we can automatically limit the number of comparisons to just the ones we need.  This will make bubble sort much faster for larger arrays.
	

2. **Selection Sort**:  This sort first finds the smallest (you can do it with the largest element too) element in the list and moves it to the front.  At this point, the array is implicitly partitioned into a sorted sublist and an unsorted remainder.  You then find the smallest element in the unsorted remainder, and add it to the sorted sublist, shifting the unsorted remainder as necessary.  

3. **Insertion Sort**: Take the first element of the array and consider it sorted.  Then you have a situation similar to selection sort, where you have a sorted and unsorted portion of your array.  For every subsequent value in the unsorted portion, place it where it needs to be in the sorted portion, shifting values as needed (this is the insertion portion).  Repeat until sorted.

4. **Bogo Sort**: This is not a sort of any real importance, but is good as a baseline.  If an array is unsorted, shuffle it.  If it's still unsorted, repeat until sorted.  

#Performance Notes

All of the useful sorts (aka not bogo sort) take O(n^2) time; that is, in the worst case scenario (sorting a list in descending order), we expect the time to sort to increase at a squared rate.  There are some tricks we do to minimize unnecessary comparisons, but these tricks do not have a large enough effect to change the fundamental performance of these algorithms.  If you're in need of sorting, don't use these.

The positives of these sorts is that they are easy to implement and visualize.  It's a good way to start a conversation about sorting and algorithm performance, even if they're not very good at what they do.

#Other Concepts

1. This lab introduces .gitignore files, which probably should have been used much earlier.  Any files that can be regenerated from the commit files (which in this case are .o files, .txt files for testing, and executables), shouldn't be committed.  .gitignore stops users from accidentally committing these files when using a command like `git add *`, making things much easier.  In order to use .gitignore, cd into the directory, then write `touch .gitignore` into the command line.  Make sure that you can view hidden files on your operating system.  Open the .gitignore file on your text editor and write the types of files extensions you don't want, such as *.o (all .o files) or *.txt (all .txt files).

2. This lab also allows the user to generate random numbers and time the sorts.  This is language dependent, so I won't really explain further.