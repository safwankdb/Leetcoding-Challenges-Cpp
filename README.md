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
