"""Find row,col of an unassigned cell
If there is none, return true
For digits from 1 to 9
    1) If there is no conflict for digit at cell -
        assign digit to the cell and
            recursively proceed to fill the rest of the grid
    2) If recursion successful, return true
    3) Else remove the digit and try another
If all the digits have been tried and nothing worked, return false
"""
from __future__ import annotations
from typing import List, Dict, Tuple, Callable, Generator

def is_there_conflict(grid: List[List], row: int, col: int, digit: int):
    #Check in row
    if digit in grid[row]:
        return True
    #Check in column
    for row_num in range(9):
        if grid[row_num][col] == digit:
            return True
    #Check in 3 x 3 grid
    #find the modulus for getting the grid
    row_mod = row//3
    col_mod = col//3
    for grid_row in grid[row_mod*3: row_mod*3+3]:
        for grid_cell in grid_row[col_mod*3: col_mod*3+3]:
            if grid_cell == digit:
                return True
    #All checks passed, return True
    return False


def find_empty_cell(grid: List[List]):
    for row in range(9):
        for col in range(9):
            if grid[row][col] == 0:
                return row,col
    return None

def sudoku(grid: List[List]):
    next_empty_cell = find_empty_cell(grid)
    
    if not next_empty_cell:
        #Grid search is over, sudoku complete
        return True
    row, col = next_empty_cell #Decompress a tuple

    for potential_digit in range(1,10):
        if is_there_conflict(grid, row, col, potential_digit):
            continue
        grid[row][col] = potential_digit
        if sudoku(grid):
            return True
        #No solution found with the current digit, let's check next  
        grid[row][col] = 0
    
    return False

                
            

def print_grid(grid: List[List]):
    print("\n")
    for i, row in enumerate(grid):
        if i!=0 and i%3 == 0:
            print("- "*11)
        print(" ".join(map(str,row[:3]+ ["|"] + row[3:6] + ["|"] + row[6:])).replace("0","-"))
    print("\n")


# Driver main function to test above functions
if __name__=="__main__":
    # creating a 2D array for the grid
    grid=[[0 for x in range(9)]for y in range(9)]

    # assigning values to the grid
    grid=[[3,0,6,5,0,8,4,0,0],
          [5,2,0,0,0,0,0,0,0],
          [0,8,7,0,0,0,0,3,1],
          [0,0,3,0,1,0,0,8,0],
          [9,0,0,8,6,3,0,0,5], 
          [0,5,0,0,9,0,6,0,0], 
          [1,3,0,0,0,0,2,5,0], 
          [0,0,0,0,0,0,0,7,4], 
          [0,0,5,2,0,6,3,0,0]] 
      
    print_grid(grid)
    # if success print the grid 
    if(sudoku(grid)): 
        print_grid(grid) 
    else: 
        print("No solution exists")