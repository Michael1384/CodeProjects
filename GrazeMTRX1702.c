/* enter your code here, make sure your compiled
executable is named "graze" */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main(void) {
    char square[12][2] = {"*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*", "*"};
    char valids[12][3] = {"b0", "c0", "a1", "b1", "c1", "d1", "d2", "a2", "b2", "c2", "b3", "c3"};
    char move[3];
    int player, turn;
    int validity = 0;
    int game = 0;
    char occupied;
    int failcount = 0;

// First print empty graze board (easier to visualise this way)

    printf("  abcd\n");
    printf("0  %s%s \n", square[0], square[1]);
    printf("1 %s%s%s%s\n", square[2], square[3], square[4], square[5]);
    printf("2 %s%s%s%s\n", square[6], square[7], square[8], square[9]);
    printf("3  %s%s \n", square[10], square[11]);

// Create for loop for the game

for(int i = 0; i < 12; i++) {

// Determine iteration of moves

        player = (i % 2) + 1;
        turn = (player == 1) ? 'X' : 'O';
        occupied = (player == 1) ? 'O' : 'X';
        
// Ask for move input from player
        printf("Player %d turn: ", player);
        scanf("%s", move);

// Check if input move is a valid string, of the 12 possible strings

if (
    strcmp(move, "0b") == 0 || strcmp(move, "0c") == 0 ||
    strcmp(move, "1a") == 0 || strcmp(move, "1b") == 0 ||
    strcmp(move, "1c") == 0 || strcmp(move, "1d") == 0 ||
    strcmp(move, "2a") == 0 || strcmp(move, "2b") == 0 ||
    strcmp(move, "2c") == 0 || strcmp(move, "2d") == 0 ||
    strcmp(move, "3b") == 0 || strcmp(move, "3c") == 0){
    } else {
        i--;
        printf("Invalid turn: must be playable cell\n");
        continue;
        } 
        
// Check for the input square and see if it is a valid move
// This check is done within a while loop which checks if there are any possible moves left for the other player
// Where if after current move by Player X, such that Player Y will no longer have any moves, the game ends. 

// This first section of 'if' and 'else if' inside the while loop are to check if the current players move is eligible
// If eligible, change the square to the players value. 

    if (strcmp(move, "0b") == 0) {
            if (square[1][0] == occupied || square[3][0] == occupied || square[0][0] != '*') {
                printf("Invalid turn: must be playable cell\n");
                i--;
                continue;
            } else {
                square[0][0] = turn;
            }
        } else if (strcmp(move, "0c") == 0) {
            if (square[0][0] == occupied || square[4][0] == occupied || square[1][0] != '*') {
                printf("Invalid turn: must be playable cell\n");
                i--;
                continue;
            } else {
                square[1][0] = turn;
            }
        } else if (strcmp(move, "1a") == 0) {
            if (square[3][0] == occupied || square[6][0] == occupied || square[2][0] != '*') {
                printf("Invalid turn: must be playable cell\n");
                i--;
                continue;
            } else {
                square[2][0] = turn;
            }
        } else if (strcmp(move, "1b") == 0) {
            if (square[0][0] == occupied || square[2][0] == occupied || square[4][0] == occupied || square[7][0] == occupied || square[3][0] != '*') {
                printf("Invalid turn: must be playable cell\n");
                i--;
                continue;
            } else {
                square[3][0] = turn;
            }
        } else if (strcmp(move, "1c") == 0) {
            if (square[1][0] == occupied || square[3][0] == occupied || square[5][0] == occupied || square[8][0] == occupied || square[4][0] != '*') {
                printf("Invalid turn: must be playable cell\n");
                i--;
                continue;
            } else {
                square[4][0] = turn;
            }
        } else if (strcmp(move, "1d") == 0) {
            if (square[4][0] == occupied || square[9][0] == occupied || square[5][0] != '*') {
                printf("Invalid turn: must be playable cell\n");
                i--;
                continue;
            } else {
                square[5][0] = turn;
            }
        } else if (strcmp(move, "2a") == 0) {
            if (square[2][0] == occupied || square[7][0] == occupied || square[6][0] != '*') {
                printf("Invalid turn: must be playable cell\n");
                i--;
                continue;
            } else {
                square[6][0] = turn;
            }
        } else if (strcmp(move, "2b") == 0) {
            if (square[3][0] == occupied || square[6][0] == occupied || square[8][0] == occupied || square[10][0] == occupied || square[7][0] != '*') {
                printf("Invalid turn: must be playable cell\n");
                i--;
                continue;
            } else {
                square[7][0] = turn;
            }
        } else if (strcmp(move, "2c") == 0) {
            if (square[4][0] == occupied || square[7][0] == occupied || square[9][0] == occupied || square[11][0] == occupied || square[8][0] != '*') {
                printf("Invalid turn: must be playable cell\n");
                i--;
                continue;
            } else {
                square[8][0] = turn;
            }
        } else if (strcmp(move, "2d") == 0) {
            if (square[5][0] == occupied || square[8][0] == occupied || square[9][0] != '*') {
                printf("Invalid turn: must be playable cell\n");
                i--;
                continue;
            } else {
                square[9][0] = turn;
            }
        } else if (strcmp(move, "3b") == 0) {
            if (square[7][0] == occupied || square[11][0] == occupied || square[10][0] != '*') {
                printf("Invalid turn: must be playable cell\n");
                i--;
                continue;
            } else {
                square[10][0] = turn;
            }
        } else if (strcmp(move, "3c") == 0) {
            if (square[8][0] == occupied || square[10][0] == occupied || square[11][0] != '*') {
                printf("Invalid turn: must be playable cell\n");
                i--;
                continue;
            } else {
                square[11][0] = turn;
            }
        }
// The current players move have been checked, now it is time to check if the other player has any possible moves left

// The method of checking for fail is by using a fail count, where if it equals 12, the game ends

// Must use independent if statements, and set failcount back to 0 if they do not add to 12 by the end of an iteration

    failcount == 0;

    if (square[1][0] == turn || square[3][0] == turn || square[0][0] != '*') {
        failcount++;
    }
    if (square[0][0] == turn || square[4][0] == turn || square[1][0] != '*') {
        failcount++;
    }
    if (square[3][0] == turn || square[6][0] == turn || square[2][0] != '*') {
        failcount++;
    }
    if (square[0][0] == turn || square[2][0] == turn || square[4][0] == turn || square[7][0] == turn || square[3][0] != '*') {
        failcount++;
    }
    if (square[1][0] == turn || square[3][0] == turn || square[5][0] == turn || square[8][0] == turn || square[4][0] != '*') {
        failcount++;
    }
    if (square[4][0] == turn || square[9][0] == turn || square[5][0] != '*') {
        failcount++;
    }
    if (square[2][0] == turn || square[7][0] == turn || square[6][0] != '*') {
        failcount++;
    }
    if (square[3][0] == turn || square[6][0] == turn || square[8][0] == turn || square[10][0] == turn || square[7][0] != '*') {
        failcount++;
    }
    if (square[4][0] == turn || square[7][0] == turn || square[9][0] == turn || square[11][0] == turn || square[8][0] != '*') {
        failcount++;
    }
    if (square[5][0] == turn || square[8][0] == turn || square[9][0] != '*') {
        failcount++;
    }
    if (square[7][0] == turn || square[11][0] == turn || square[10][0] != '*') {
        failcount++;
    }
    if (square[8][0] == turn || square[10][0] == turn || square[11][0] != '*') {
        failcount++;
    } 

    printf("  abcd\n");
    printf("0  %s%s \n", square[0], square[1]);
    printf("1 %s%s%s%s\n", square[2], square[3], square[4], square[5]);
    printf("2 %s%s%s%s\n", square[6], square[7], square[8], square[9]);
    printf("3  %s%s \n", square[10], square[11]);

// If failcount is 12, print now that player has won, and end game

    if (failcount == 12) {
        printf("Player %d wins!\n", player);
        exit(0);
    } else {failcount = 0;}

// If not, then redo and iterate once again.

}

 return (0);}
