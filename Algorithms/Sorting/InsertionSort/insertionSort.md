# Insertion Sort

## Idea
* The main idea of this is that we sort each segment consists of 1 first element, 2 first elements, ...  $N$ elements.

* If we finish sorting $i$ elements in the array, we can sort $i + 1$ elements by finding the correct position of the $(i + 1)^{th}$ element and **insert** it.

## Pros
* If the array is almost sorted, Insertion Sort will execute very fast. Say, if you want to sort Highscore in a game.

## Cons
* The time complexity is **$O(N^2)$** since it requires two loops. Hence, it is unefficient with a large amount of elements.