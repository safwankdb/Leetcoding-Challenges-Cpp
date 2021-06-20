# Leetcoding Challenges C++

C++ solutions for whatever monthly challenge problems I solve.

### June

- #### Max Area of Island
    DFS on the islands, keep track of visited squares. If visited, return 0, else area = 1 + area of neighbours.

- #### Interleaving String
    Basic string dp. Start from front of both strings (bottom up), maintain ```dp[i][j]``` which is true if ```s3[:i+j]``` is interleaving of ```s1[:i]``` and ```s2[:j]```.

- #### Maximum Area of a Piece of Cake After Horizontal and Vertical Cuts
    Just find the largest gap between 2 consecutive cuts in both directions (need sorting).

- #### Open the Lock
    Do a BFS search, stop searching a branch if any deadlock is encountered.

- #### Min Cost Climbing Stairs
    Simple 1D dynamic programming. Use top down approach. Total cost from ith step depends on total cost from next 2 steps.

- #### Stone Game VII
    For stone array from ```[i,...,j]```, look at all possibilities of next 2 steps. Use dp to store solution of ```[i+1,...,j-1], [i+2,...,j], [i,...,j-2]```.

- #### Max Units on a Truck
    Variation of Knapsack, since the cost (size) of each box is the same, we can greedily pack the boxes starting with highest units to lowest till truck is filled.

- #### Matchsticks to Square
    Use DFS, add obvious pruning condition, sort the matchstickin in descending order so pruning can be done earlier. Another faster solution exists using dp.

- #### Generate Parantheses
    Vary number of outer brackets from 0 to n. For the remaining k brackets, add all combinations of f(a) and f(b) where a + b = k. Use set to filter duplicates.

- #### Number of Subarrays with Bounded Maximum
    Keep track of left most valid element to include, whenever ```left <= nums[i] <= right``` is encountered, set it as the most latest needed value, for all values <= left, add all subarrays from left most valid to latest needed. If value >= right is found, reset both pointers.

- #### Range Sum Query - Mutable
    Use Fenwick tree. Make an array indexed from 1 to n, for every index i, the array contains sum of m elements including and below i from the original array, where m is the value of LSB of i. Update accordingly.

- #### Swim in Rising Water
    Use binary search to find minimum viable t. To check a single value of t, use dfs based union-find like in [Max Area of Island](https://leetcode.com/problems/max-area-of-island/).
