#include <iostream>
#include <vector>
#include <algorithm>

#define ROW 9
#define COL 9
#define EMPTY -1

// std::pair<int,int> findEmptySquare(std::vector<std::vector<int>>& sudokuGrid) {
//     for (int i = 0; i < ROW; i++) {
//         for (int j = 0; i < COL; j++) {
//             if (sudokuGrid[i][j] == EMPTY) {
//                 return {i, j};
//             }
//         }
//     }

//     return {-1, -1};
// }

bool isValidForRow(const std::vector<int>& sudokuGridRow,  const int candidate) {
    // // Test for suitability for row
    if (std::find(sudokuGridRow.begin(), sudokuGridRow.end(), candidate) != sudokuGridRow.end())
        return false;

    return true;
}

bool isValidForColumn(const std::vector<std::vector<int>>& sudokuGrid, const std::pair<int, int> coordinates, const int candidate) {
    // For each row, check the column for candidate being already present
    for (auto& row: sudokuGrid) {
        if (row[coordinates.second] == candidate) {
            return false;
        }
    }

    return true;
}

bool isValidForSmallSquare(const std::vector<std::vector<int>>& sudokuGrid, const std::pair<int, int> coordinates, const int candidate) {
        int rowStart{0};
        int rowEnd{2};
        int columnStart{0};
        int columnEnd{2};

        // Check the row coordinate and compare it to the 9 smaller grids within the sudoku grid 
        if (coordinates.first > 2 && coordinates.first < 5 ) {
            rowStart = 3;
            rowEnd = 5;
        } else if (coordinates.first > 5) {
            rowStart = 6;
            rowEnd = 8;
        }

        // Check the column coordinate and compare it to the 9 smaller grids within the sudoku grid
        if (coordinates.second > 2 && coordinates.second < 5 ) {
            columnStart = 3;
            columnEnd = 5;
        } else if (coordinates.second > 5) {
            columnStart = 6;
            columnEnd = 8;
        }

        for (int i = rowStart; i <= rowEnd; i++) {
            for (int j = columnStart; j <= columnEnd; j++) {
                if (sudokuGrid[i].at(j) == candidate)
                    return false; 
            }
        }

        return true;
}

bool isCandidateValid(const std::vector<std::vector<int>>& sudokuGrid, const std::pair<int, int> coordinates, const int candidate) {
    if (isValidForRow(sudokuGrid[coordinates.first], candidate)
        && isValidForColumn(sudokuGrid, coordinates, candidate)
        && isValidForSmallSquare(sudokuGrid, coordinates, candidate)) {
            return true;
        }
    
    return false;
}

// bool solveSudoku(std::vector<std::vector<int>>& sudokuGrid) {
//     // Check if the grid has been solved, meaning there are no more empty squares in it.
//     std::pair<int,int> find = findEmptySquare(sudokuGrid);

//     // If the findEmptySquare returns pair of negative ones, there are no empty squares
//     if (find.first == -1)
//         return true;
    
//     // If there are empty square, begin testing numbers for it
//     for (int i = 1; i < 10; i++) {

//         //Check if the number is suitable for the square according to sudokus rules


//     }
// } 

int main() {

    std::cout << "Welcome to SudokuSolver!" << std::endl;
    std::cout << "=========================" << std::endl;

    // The negative number 1 is used to indicate an empty square in the grid.
    std::vector<std::vector<int>> puzzle{
        {-1, -1, -1, 2, 6, -1, 7, -1, 1},
        {6, 8, -1, -1, 7, -1, -1, 9, -1},
        {1, 9, -1, -1, -1, 4, 5, -1, -1},
        {8, 2, -1, 1, -1, -1, -1, 4, -1},
        {-1, -1, 4, 6, -1, 2, 9, -1, -1},
        {-1, 5, -1, -1, -1, 3, -1, 2, 8},
        {-1, -1, 9, 3, -1, -1, -1, 7, 4},
        {-1, 4, -1, -1, 5, -1, -1, 3, 6},
        {7, -1, 3, -1, 1, 8, -1, -1, -1}
    };

    std::cout << "The hardcoded sudoku is solvable?" << std::endl;
    std::cout << "=================================" << std::endl;
    // std::cout << solveSudoku(puzzle) << std::endl;
    // std::pair<int,int> empty = findEmptySquare(puzzle);
    // std::cout << "First empty square is located at: " << empty.first << ", " << empty.second << std::endl;
    // int candidate = 2;
    // std::cout << "Is it possible to place number " << candidate << " on row 1? "<< std::boolalpha << isValidForRow(puzzle[1], candidate) << std::endl; 
    // int candidate = 3;
    // std::pair<int,int> coordinates{0, 8};
    // std::cout << "Is it possible to place number " << candidate << " on column " << coordinates.second << "? " << std::boolalpha << isValidForColumn(puzzle, coordinates, candidate) << std::endl;
    // 
    int candidate = 1;
    std::pair<int,int> coordinates{0, 2};
    std::cout << "Is it possible to place number " << candidate << " at coordinates " << coordinates.first << "," << coordinates.second << "? " << std::boolalpha << isCandidateValid(puzzle, coordinates, candidate) << std::endl; 



    return 0;
}