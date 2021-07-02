# July Challenge

#### Find K Closest Elements
- Use min heap to find top k elements with custom comparator parametrized with x (use lambda with capture).
- Since the array is sorted, use binary search to find the starting index of subarray.

#### Gray Code
- Use DFS. For each number pushed into answer array, insert the next unvisited number obatined by flipping a single bit, continue till all are visited. This is slightly slow.
- Use the result of n-1. Dor first half prepend a 0 to all numbers, then reverse the list and prepend 1 to all.

