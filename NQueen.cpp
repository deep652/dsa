// Problem
// possible ways to place N queens in N*N grid so they won't attach
// tasks
// 1. Define a N grid - start eith 4 rows and colums
// 2. define how to check if it is safe to place in that grid,
// considering a queen can attack in the same row, same column or diagonally
// 3. Write the solution, which does move row by row and check if that row is safe
// 4. how the backtrack works if it is not safe
#include<iostream>
#include<vector>
#include<string>
using namespace std;

class NQueen
{
    public:
    
    bool isSafe(int row, int col, vector<string> &grid,int N)
    {
        for(int i=0; i<col; i++)
        {
            if(grid[row][i] == 'Q')
            {
                return false;
            }
        }

        for(int i=0; i< row; i++)
        {
            if(grid[i][col] == 'Q')
            {
                return false;
            }
        }

        //upper left diagonal
        for(int i=row-1, j=col-1; i>=0 && j>=0; i--,j-- )
        {
            if(grid[i][j] == 'Q')
            {
                return false;
            }

        }

        //upper right diagonal
        for(int i=row-1, j=col+1; i>=0 && j<N; i--,j++ )
        {
            if(grid[i][j] == 'Q')
            {
                return false;
            }

        }
        return true;

    }//end of isSafe

    //recursive method
    void solve(int row, vector<string>&grid, vector<vector<string>> &solutions, int N)
    {
        if(row == N)
        {
            solutions.push_back(grid);
            return;
        }

        for(int col = 0; col<N; col++)
        {
            if(isSafe(row, col, grid, N))
            {
                grid[row][col]='Q';
            
            solve(row+1, grid, solutions, N);
            //here you will be once you get one solution, so 
            //Now you need to backtrack
            //doubt, do i need to reset only one cell, like grid[row][col] = '.'
            //or the entire grid need to be resetted, as we now reached the end 
            //of the grid;

            /**try to understand the below comment
             * this is heart of recursion and backtracking too
             */
            //this is recursice,
            //so stack clearning will happen for each row, and subsequently
            //because we are in loop, for each col too
            //so only removing the queen for each row and col will eventally clears
            //the entire girid

            grid[row][col] = '.' ; //Note this condition is inside the for loop
            }
        }
    }

    void solveQueen(int N) 
    {
        vector<string> grid(N, string(N, '.'));
        vector<vector<string>> solutions;
        
        solve(0, grid, solutions, N);

        //print the solution 

        //cout<<solutions.size();
        for(auto grid : solutions)
        {
            for(auto str: grid)
            {
                cout<<str<<endl;
            }
            cout<<"****"<<endl;
        }
    }

};

int main()
{
    int N = 4;
    NQueen obj;
    obj.solveQueen(N);
    return 0;
}
