# Bubble Sort

## Idea
* For each pair of two consecutive elements. If the first element is smaller than the second element, their places are swapped (*the smaller element will **rises** to the top like a bubble*).
* This process is continued until there are no more pair that satisfy the condition. The maximum number of loops is $N - 1$, since each element can only rise $N - 1$ times, at max. 

## Pros
* Easy to implement and easy to understand.
* No extra memory required.

## Cons
* The time complexity is **$O(N^2)$** since it requires two ```for``` loops. Hence, it is unefficient with a large amount of elements.