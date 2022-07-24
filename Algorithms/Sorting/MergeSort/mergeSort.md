# Merge Sort

## Idea
Merge Sort works using recursion:
* First divide the elements into two equal parts, then sort each part. The smaller parts can be divided again until it is easier to compare.
* After sorting, we **merge** two parts back together. To merge, follow these steps:
    * Firstly, create a new array ***A*** to contain all sorted elements.
    * Compare the first element of two parts. The smaller one is put into ***A*** and remove from the respective part.
    * Continue until all elements of each part is removed and put into ***A***.

## Pros
* Runs fast, time complexity of **$O(N\log(N))$**.
* This is a stable sorting algorithm.

## Cons
* Needs extra memory for temporary array ***A*** (space complexity **$O(N)$**).