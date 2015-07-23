#Purpose

This lab introduces some basic sorting techniques.  The sorts we'll deal with in this lab are pretty basic, iterative sorts that ultimately are pretty inefficient, but they're a good starting point.

#Sorts
1. **Bubble Sort**: Also known as *sinking sort*, this sort works by starting at the beginning of the array and comparing every element of the array against each other, swapping the elements in order to get to the right order.  As the sort progresses, the elements of the array will "bubble" into the right places.  The sort implementation here includes a flag so that if the list is sorted prior to every element being compared, the sort will quit.  This will hopefully save some time in what is otherwise a fairly inefficient process.  This is probably the most naive of sorts and should never be used for large data sets, but it's easy to set up.

2. **Selection Sort**:  This sort first finds the smallest (you can do it with the largest element too) element in the list and moves it to the front.  At this point, the array is implicitly partitioned into a sorted sublist and an unsorted remainder.  You then find the smallest element in the unsorted remainder, and add it to the sorted sublist, shifting the unsorted remainder as necessary.  

3. **Insertion Sort**: Take the first element of the array and consider it sorted.  Then you have a situation similar to selection sort, where you have a sorted and unsorted portion of your array.  For every subsequent value in the unsorted portion, place it where it needs to be in the sorted portion, shifting values as needed (this is the insertion portion).  Repeat until sorted.

4. **Bogo Sort**: This is not a sort of any real importance, but is good as a baseline.  If an array is unsorted, shuffle it.  If it's still unsorted, repeat until sorted.  

#Other Concepts

1. This lab introduces .gitignore files, which probably should have been used much earlier.  Any files that can be regenerated from the commit files (which in this case are .o files, .txt files for testing, and executables), shouldn't be committed.  .gitignore stops users from accidentally committing these files when using a command like `git add *`, making things much easier.  In order to use .gitignore, cd into the directory, then write `touch .gitignore` into the command line.  Make sure that you can view hidden files on your operating system.  Open the .gitignore file on your text editor and write the types of files extensions you don't want, such as *.o (all .o files) or *.txt (all .txt files).

2. This lab also allows the user to generate random numbers and time the sorts.  This is language dependent, so I won't really explain further.