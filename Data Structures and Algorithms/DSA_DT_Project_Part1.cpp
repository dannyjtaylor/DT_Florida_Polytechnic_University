// CODE:

//directives
#include <iostream>
#include <vector>

//use namespace std so not as annoying lol :]
using namespace std;

//function for depth first search
void depthFirstSearch(vector<vector<int>>& grid, int row, int column) {
    //check for out-of-bounds or if the cell is water 
    if (row < 0 || column < 0 || row >= grid.size() || column >= grid[0].size() || grid[row][column] == 0) {
        return;
    }
    //mark the current cell as visited so land is not counted multiple times
    grid[row][column] = 0;
    //explore adjacent cells with DFS
    //row-1 is going up, row+1 is going down, column-1 is going left, column+1 is going right
    depthFirstSearch(grid, row - 1, column);
    depthFirstSearch(grid, row + 1, column);
    depthFirstSearch(grid, row, column - 1);
    depthFirstSearch(grid, row, column + 1);
}

//finction to count the number of islands for output
int islandNumber(vector<vector<int>>& grid) {
    int numberOfIslands = 0;
    //use nested for loop to iterate through entire grid
    for (int rows = 0; rows < grid.size(); rows++) {
        for (int columns = 0; columns < grid[0].size(); columns++) {
            //if the current cell is 1, land is found, increase number of islands
            if (grid[rows][columns] == 1) {
                ++numberOfIslands;
                //now that the island is found and counted, use depth first search to traverse through the whole island
                depthFirstSearch(grid, rows, columns);
            }
        }
    }
    //return number of islands for output
    return numberOfIslands;
}

int main(void) {

    //test grid 1
    vector<vector<int>> grid1 = {
        {1,1,1,1,0}, 
        {1,1,0,1,0}, 
        {1,1,0,0,0}, 
        {0,0,0,0,0}
        };
    //test grid 2
    vector<vector<int>> grid2 = {
        {1,1,0,0,0},
        {1,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,1}
    };
    vector<vector<int>> grid3 = {
        {1,0,0,0,1,0,0,0,0,1},
        {0,0,0,0,0,0,0,0,0,1},
        {0,0,0,0,0,0,0,0,0,1},
        {1,0,0,0,1,0,0,0,0,1},
    };
    //print grid and its respective 
    cout << "Grid 1: " << islandNumber(grid1) << endl;
    cout << "Grid 2: " << islandNumber(grid2) << endl;
    cout << "Grid 3: " << islandNumber(grid3) << endl;
    return 0;
}

/*    QUESTION 2A:
Research on how we can implement BFS/DFS algorithms. Briefly, explain the implementation steps with comments.


    After first iterating through the grid and land (1) is found, you can use DFS to search through the entire  
"island" so you know how extensive the island is, and then you can continue iterating through the grid and repeat
when land is found again until the end of the grid. When using DFS, at the first spot land is detected, recursion is
used to call DFS function again, going up, down, left, and right at each point in the grid. There is a base
case when the cell you're exploring (either up, down, left, or right) is water (cell is 0), out of bounds (cell
has a row/column number less than row/column length), or already found. (The program will know the cell is already
found by marking it as zero.)

Steps are also explained with comments in the code itself.


      QUESTION 2B:
Analyze the time complexity of the algorithms in terms of big Oh notation. (10 points)

   The code first begins when calling the islandNumber function, which has two for loops that are mxn (with m being 
the number of rows, and n being the number of columns). This means that so far we have O(mn) complexity, or O(n^2) 
complexity if the number of rows is equal to the number of columns. At each cell of the grid, the function
depthFirstSearch is called, where at first does a simple logic check, and marks the cell as visited. (O(1))
Then, it recursively calls itself over and over to explore the entire grid. Since the DFS function marks each cell 
visited as 0, then the number of explorations decreases, and eventually the whole grid is filled with 0's. This
does not add too much to the time complexity past the initial O(n^2) from the nested for loop to iterate through
the grid.

   Overall, the program has an O(n^2) time complexity.

*/