# July Challenge

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

