#include<iostream>
using namespace std;

//function to print sudoku
void printGrid(int grid[9][9])
{
	for (int row=0;row<9;row++)
	{
		for(int col=0;col<9;col++)
		{
			cout<<grid[row][col]<<" ";
		}
		cout<<endl;
	}
}

bool isSafe(int grid[9][9],int row, int col, int num)
{
	for (int i=0;i<9;i++)
	{
		if(grid[row][i] == num || grid[i][col] == num || grid[row -row%3 + i/3][col -col%3 +i/3] == num)
		{
			return false;
		}
	}
	return true;
}

bool findUnassigned(int grid[9][9], int &row, int &col) {
    for (row = 0; row < 9; row++) {
        for (col = 0; col < 9; col++) {
            if (grid[row][col] == 0) {
                return true; 
            }
        }
    }
    return false;
}

bool solveSudoku(int grid[9][9])
{
	int row,col;
	if(!findUnassigned(grid,row,col))
	{
		return true;
	}
	
	for(int num=1;num<=9;num++)
	{
		if(isSafe(grid,row,col,num))
		{
			grid[row][col]=num;
			
			if(solveSudoku(grid))
			{
				return true;
			}
			
			grid[row][col] = 0;
		}
	}
	return false;
}

int main()
{
	cout<<"\n\t\t\t Welcome To The Sudoku!! \n";
	cout<<"\n\t Instructions To Play Sudoku\n";
	cout<<"\nThe goal of Sudoku is to fill the cells with numbers from 1 to 9. The numbers are placed in 9 squares, 3x3 each, thus, in each row, in each column and in each small square there are 9 cells. The same digit can be used only once in each separate column, each line and in each small square. The level of difficulty depends on how many digits are already indicated in the cells.\n";
	while(true)
	{
		cout<<"\n Difficulty Levels";
		cout<<"\n 1 - Easy\t";
		cout<<"\n 2 - Medium\t";
		cout<<"\n 3 - Hard\t";
		cout<<"\n 4 - Master\t";
		cout<<"\n 0 - End Game\n\n";
		
	// select the difficulty level
	int level;
	cout<<"Enter the difficulty level number : ";
	cin>>level;
	
	//level=easy
	if(level==1)
	{
		int grid[9][9] = {{9,2,6,3,4,0,0,0,1},
		                  {0,0,1,7,0,0,3,0,9},
						  {0,0,3,8,0,0,2,0,6},
						  {0,0,0,0,0,7,0,0,0},
						  {0,6,0,9,1,0,4,2,0},
						  {0,9,7,2,0,0,6,0,3},
						  {0,8,0,4,7,0,1,0,2},
						  {7,0,4,1,6,2,0,0,8},
					      {0,0,0,5,3,0,0,0,0}};
		
		cout<<"Unsolved Sudoku : \n\n";
		printGrid(grid);		      
					      
		if (solveSudoku(grid))
		{
	        cout<<"\nSolution : \n\n";
			printGrid(grid);
			break;
		}
		else
		{
			cout<<"No Solution Exist For This Sudoku\n";
		}
		
		return 0;
	}
	
	//level=medium
	if(level==2)
	{
		int grid[9][9] = {{0,0,0,0,0,1,2,8,0},
		                  {1,7,2,3,8,0,9,4,0},
						  {4,3,0,9,6,2,7,5,0},
						  {0,1,3,6,0,4,0,0,0},
						  {0,0,0,5,3,0,4,0,0},
						  {5,0,0,0,0,0,0,0,2},
						  {0,0,0,0,0,6,3,0,0},
						  {3,8,0,0,0,0,1,0,9},
					      {0,2,5,0,9,0,0,0,4}};
		
		cout<<"Unsolved Sudoku : \n\n";
		printGrid(grid);		      
					      
		if (solveSudoku(grid))
		{
	        cout<<"Solution : \n\n";
			printGrid(grid);
			break;
		}
		else
		{
			cout<<"No Solution Exist For This Sudoku\n";
		}
		
		return 0;
	}
	
	//level=hard
	if(level==3)
	{
		int grid[9][9] = {{0,5,0,0,0,0,9,6,0},
		                  {0,3,6,0,0,0,0,8,5},
						  {9,8,2,5,0,1,0,0,4},
						  {0,0,0,0,0,2,0,9,6},
						  {3,0,9,7,4,5,0,0,8},
						  {2,4,0,0,9,0,0,0,0},
						  {8,1,0,0,0,7,0,0,9},
						  {6,0,0,9,8,0,0,3,0},
					      {0,9,4,6,0,3,8,0,0}};
		
		cout<<"Unsolved Sudoku : \n\n";
		printGrid(grid);		      
					      
		if (solveSudoku(grid))
		{
	        cout<<"Solution : \n\n";
			printGrid(grid);
			break;
		}
		else
		{
			cout<<"No Solution Exist For This Sudoku\n";
		}
		
		return 0;
	}
	
	//level=master
	if(level==4)
	{
		int grid[9][9] = {{0,0,0,2,0,0,0,9,6},
		                  {6,2,9,1,8,5,0,0,0},
						  {0,0,0,6,0,0,0,0,0},
						  {1,0,8,0,6,0,0,0,2},
						  {0,3,6,4,0,1,9,0,0},
						  {7,0,0,0,0,0,6,0,0},
						  {4,0,7,5,1,0,0,0,0},
						  {0,0,0,0,2,4,1,0,0},
					      {5,1,0,0,0,0,4,0,8}};
		
		cout<<"Unsolved Sudoku : \n\n";
		printGrid(grid);		      
					      
		if (solveSudoku(grid))
		{
	        cout<<"Solution : \n\n";
			printGrid(grid);
			break;
		}
		else
		{
			cout<<"No Solution Exist For This Sudoku\n";
		}
		
		return 0;
	}
	
	//level=0
	if(level==0)
	{
		cout<<"Game Over";
	}
    }
	
}

