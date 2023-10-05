#include "sudoku.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(void) {
    srand(time(NULL));
    
    initialize_board();
    // First unsolvable sudoku
   /* mark_board(0, 0, 4);
    mark_board(0, 7, 3);
    mark_board(0, 8, 9);
    mark_board(1, 5, 3);
    mark_board(1, 7, 4);
    mark_board(3, 5, 6);
    mark_board(4, 8, 4);
    mark_board(5, 3, 7);
    mark_board(5, 4, 3);
    mark_board(5, 6, 2);    
    mark_board(6, 8, 2);
    mark_board(7, 1, 2);
    mark_board(8, 0, 3);
    mark_board(8, 1, 5);
    mark_board(8, 3, 1);
    mark_board(8, 4, 9);
    mark_board(8, 5, 7);
*/

// second unsolvable sudoku
   /* mark_board(0, 2, 4);
    mark_board(0, 5, 5);
    mark_board(1, 7, 8);
    mark_board(2, 3, 6);
    mark_board(2, 5, 8);
    mark_board(2, 8, 3);
    mark_board(3, 0, 1);
    mark_board(3, 1, 2);
    mark_board(3, 2, 9);
    mark_board(3, 4, 4);
    mark_board(4, 0, 3);
    mark_board(5, 7, 4);
    mark_board(6, 6, 1);
    mark_board(7, 1, 4);
    mark_board(7, 2, 1);
    mark_board(7, 8, 7);
    mark_board(8, 0, 2);
    mark_board(8, 4, 8);*/

    print();

    printf("Solved sudoku:\n");
    if (solve_sudoku(0, 0) == 1)
        print();
    else
        printf("No solution exists\n");
    return 0;
}
