#include <iostream>
#include <vector>
#include <utility>

#define ROW 9
#define COL 9
#define EMPTY -1

std::pair<int,int> findEmptySquare(std::vector<std::vector<int>>& sudokuGrid) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; i < COL; j++) {
            if (sudokuGrid[i][j] == EMPTY) {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

// bool solveSudoku(std::vector<std::vector<int>>& sudokuGrid) {

// } 

int main() {
    ;
    std::cout << "Welcome to SudokuSolver!" << std::endl;
    std::cout << "=========================" << std::endl;

    std::vector<std::vector<int>> puzzle{
        {-1, -1, -1, 2, 6, -1, 7, -1, 1},
        {6, 8, -1, -1, 7, -1, -1, -9, -1},
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
    std::pair<int,int> empty = findEmptySquare(puzzle);
    std::cout << "First empty square is located at: " << empty.first << ", " << empty.second << std::endl; 


    return 0;
}