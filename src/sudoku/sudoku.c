#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SUB_BOARD_SIZE 3
#define BOARD_SIZE (SUB_BOARD_SIZE*SUB_BOARD_SIZE)
#define TRUE 1
#define FALSE 0
#define count 20
#define delimiter 2

int board[BOARD_SIZE][BOARD_SIZE];

int is_block_valid(int pos1, int pos2, int mark) {
    int block_index_row = pos1 / SUB_BOARD_SIZE;
    int block_index_column = pos2 / SUB_BOARD_SIZE;
    for(int i = block_index_row * SUB_BOARD_SIZE; i < (block_index_row + 1) * SUB_BOARD_SIZE; i++) {
        for(int j = block_index_column * SUB_BOARD_SIZE; j < (block_index_column + 1) * SUB_BOARD_SIZE ; j++) {
            if (board[i][j] == mark) {
                return FALSE;                
                break;
            }
        }
    }
    return TRUE;
}

int is_valid(int pos1, int pos2, int mark) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        if((board[pos1][i] == mark) || (board[i][pos2] == mark)) {
            return FALSE;
            break;
        }   
    }
    return is_block_valid(pos1, pos2, mark);
    if(board[pos1][pos2] == 0) {
        return TRUE;
    }
    return TRUE;
}

void mark_board(int pos1, int pos2, int mark) {
    if(is_valid(pos1, pos2, mark) == TRUE)
        board[pos1][pos2] = mark;
}

void initialize_board() {
    int row_random = 0;
    int col_random = 0;
    for (int i = 0; i < count; i++) {
        int nr = rand() % BOARD_SIZE + 1;    
        row_random = rand() % (BOARD_SIZE - 1);
        col_random = rand() % (BOARD_SIZE - 1);
        if(is_valid(row_random, col_random, nr) == TRUE)
            board[row_random][col_random] = nr;
    } 

}

void print() {
    printf(" ------------ ------------- ------------ \n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("|");
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == 0) 
                printf(" .. ");
            else
                printf("  %d ", board[i][j]);
            if((j == SUB_BOARD_SIZE - 1) || (j == SUB_BOARD_SIZE * delimiter - 1)) printf("| ");
        }
        printf("|\n");
        if((i == SUB_BOARD_SIZE - 1) || (i == SUB_BOARD_SIZE * delimiter - 1))
            printf(" ------------ ------------- ------------ \n");
    }
    printf(" ------------ ------------- ------------ \n");
}

int solve_sudoku(int row, int col) {
    if (row == BOARD_SIZE - 1 && col == BOARD_SIZE)
        return 1;
    if (col == BOARD_SIZE) {
        row++;
        col = 0;
    }   
    if (board[row][col] > 0)
        return solve_sudoku(row, col + 1);
 
    for (int num = 1; num <= BOARD_SIZE; num++) { 
        if (is_valid(row, col, num) == TRUE) {   
            board[row][col] = num;
            if (solve_sudoku(row, col + 1) == 1)
                return 1;
        }
        board[row][col] = 0;
    }
    return 0;
}
