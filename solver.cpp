#include <iostream>
#include <vector>
#include <algorithm>

#define N 9

bool isValidForRow(const std::vector<int>& sudokuGridRow,  const int candidate) {
    // If the candidate already exists whithin the row, return false. 
    if (std::find(sudokuGridRow.begin(), sudokuGridRow.end(), candidate) != sudokuGridRow.end())
        return false;

    return true;
}

bool isValidForColumn(const std::vector<std::vector<int>>& sudokuGrid, const std::pair<int, int> coordinates, const int candidate) {
    // If the candidate already exists on any row in the current index, return false.
    for (auto& row: sudokuGrid) {
        if (row[coordinates.second] == candidate) {
            return false;
        }
    }

    return true;
}

bool isValidForSmallSquare(const std::vector<std::vector<int>>& sudokuGrid, const std::pair<int, int> coordinates, const int candidate) {

    int rowStart = coordinates.first - (coordinates.first % 3);
    int columnStart = coordinates.second - (coordinates.second % 3);
    
    for (int i = rowStart; i < 3; i++) {
        for (int j = columnStart; j < 3; j++) {
            if (sudokuGrid[i][j] == candidate)
                return false; 
        }
    }

    return true;
}

bool isCandidateValid(const std::vector<std::vector<int>>& sudokuGrid, const std::pair<int, int>& coordinates, const int& candidate) {
    // The candidate number is valid when it slots in the current row, column and and smalled 3x3 grid
    if (isValidForRow(sudokuGrid[coordinates.first], candidate)
        && isValidForColumn(sudokuGrid, coordinates, candidate)
        && isValidForSmallSquare(sudokuGrid, coordinates, candidate)) {
            return true;
        }
    
    return false;
}

void printSudoku(const std::vector<std::vector<int>>& sudokuGrid) {
    std::cout << "==============================" << std::endl;
    for (auto& row : sudokuGrid) {
        for (auto value : row) {
            std::cout << value << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << "==============================" << std::endl;
}

bool findEmpty(const std::vector<std::vector<int>>& sudokuGrid, std::pair<int,int>& emptySquare) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (sudokuGrid[i][j] == 0) {
                emptySquare = std::make_pair(i, j);
                return true;
            }
        }
    }

    return false;
}

bool solveSudoku(std::vector<std::vector<int>>& sudokuGrid) {
    // printSudoku(sudokuGrid);
    std::pair<int, int> emptySquare;
    
    // Check if the grid has been solved, meaning there are no more empty squares in it.
    if(!findEmpty(sudokuGrid, emptySquare))
        return true;

    // printSudoku(sudokuGrid);
    // std::cout << emptySquare.first << ", " << emptySquare.second << "\n";
    // Begin testing numbers for the emptySquare
    
    for (int x = 1; x <= N; x++) {
        if (isCandidateValid(sudokuGrid, emptySquare, x)) {
            sudokuGrid[emptySquare.first][emptySquare.second] = x;
            if (solveSudoku(sudokuGrid)) {
                // std::cout << emptySquare.first << ", " << emptySquare.second << "-> " << x << " OK\n";
                return true;
            }
            // std::cout << emptySquare.first << ", " << emptySquare.second << "-> " << x << " FAIL\n";
            sudokuGrid[emptySquare.first][emptySquare.second] = 0;
        } 
    }

    return false;

}

int main() {

    std::cout << "Welcome to SudokuSolver!" << std::endl;
    std::cout << "=========================" << std::endl;

    // The number 0 is used to indicate an empty square in the grid.
    std::vector<std::vector<int>> puzzle{
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}
    };

    std::cout << "Is the hardcoded sudoku solvable?" << std::endl;
    std::cout << "=================================" << std::endl;
    std::cout << std::boolalpha << solveSudoku(puzzle) << std::endl;

    printSudoku(puzzle);
    
    return 0;
}