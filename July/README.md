# July Challenge


#### Kth Smallest Element in a Sorted Matrix
- For all the below methods : if using heap / set, work with tuple<int, int, int> of (value, row, column).
- Add all elements to heap and pop k times -> O(n^2 + klog(n)) = O(n^2)
- Maintain size of heap at k by adding and popping min element after each add. -> O(n^2)
- For a value x, write countLessThan(x) which return number of elements less than x. It can be done in nlog(n) time by just binary search inside every row. Then binary search the value of x for which function returns countLessThan(x) = k. -> O(nlog(n)log(range(matrix)))
- Use BFS. If there is a set S of possible elements for m'th position and let x_m be the m'th smallest element, the possible elements for m+1'th position would lie in (S \ {x_m}) U (Neighbors of x_m). Iterate until k, for each position pop the min element from a heap, update the frontier set. -> O(klog(k))


#### Reduce Array Size to The Half
- Use hashmap to get frequency of elements. Choose elements greedily until half are removed (Can use max heap for this).

#### Reshape Matrix
- Allocate memory and fill it iteratively. i'th element would have index [i / c][i % c].

#### Count Vowels Permutation
- Make a 2D DP where DP[i][j] is the number of strings of length i starting with j'th vowel.

#### Max Sum of Rectangle No Larger Than K
- Use the concept from [Maximum subarray sum less than equal to k](https://www.geeksforgeeks.org/maximum-sum-subarray-having-sum-less-than-or-equal-to-given-sum-using-set/). Can be found in O(nlog(n)).
- Iterate over all combinations of columns to be included in the rectangle (O(m^2)), find their sum, apply the above function on the sum array.

#### Find K Closest Elements
- Use min heap to find top k elements with custom comparator parametrized with x (use lambda with capture).
- Since the array is sorted, use binary search to find the starting index of subarray.

#### Gray Code
- Use DFS. For each number pushed into answer array, insert the next unvisited number obatined by flipping a single bit, continue till all are visited. This is slightly slow.
- Use the result of n-1. Dor first half prepend a 0 to all numbers, then reverse the list and prepend 1 to all.

