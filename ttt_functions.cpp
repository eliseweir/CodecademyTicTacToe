#include <iostream>

// draw the tic-tac-toe board
// written by Codecademy.com
void draw(char board[]) {

    std::cout << "     |     |      \n";

    std::cout << "  " << board[0] << "  |  " << board[1] << "  |  " << board[2] << "\n";

    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";

    std::cout << "  " << board[3] << "  |  " << board[4] << "  |  " << board[5] << "\n";

    std::cout << "_____|_____|_____ \n";
    std::cout << "     |     |      \n";

    std::cout << "  " << board[6] << "  |  " << board[7] << "  |  " << board[8] << "\n";
    std::cout << "     |     |      \n";

    std::cout << "\n";
}

// check if the game has been won
int check_winner(char board[], int winner, int plays) {
    // first row
    if (board[0] == board[1] && board[1] == board[2]) {
        if (board[0] = 'X') {
            winner = 1;
        }
        else if (board[0] = 'O') {
            winner = 2;
        }
    }
    // second row
    else if (board[3] == board[4] && board[4] == board[5]) {
        if (board[3] = 'X') {
            winner = 1;
        }
        else if (board[3] = 'O') {
            winner = 2;
        }
    }
    // third row
    else if (board[6] == board[7] && board[7] == board[8]) {
        if (board[6] = 'X') {
            winner = 1;
        }
        else if (board[6] = 'O') {
            winner = 2;
        }
    }
    // fisrt column
    else if (board[0] == board[3] && board[3] == board[6]) {
        if (board[0] = 'X') {
            winner = 1;
        }
        else if (board[0] = 'O') {
            winner = 2;
        }
    }
    // second column
    else if (board[1] == board[4] && board[4] == board[7]) {
        if (board[1] = 'X') {
            winner = 1;
        }
        else if (board[1] = 'O') {
            winner = 2;
        }
    }
    // third column
    else if (board[2] == board[5] && board[5] == board[8]) {
        if (board[2] = 'X') {
            winner = 1;
        }
        else if (board[2] = 'O') {
            winner = 2;
        }
    }
    // diagonal
    else if (board[0] == board[4] && board[4] == board[8]) {
        if (board[0] = 'X') {
            winner = 1;
        }
        else if (board[0] = 'O') {
            winner = 2;
        }
    }
    // antidiagonal
    else if (board[2] == board[4] && board[4] == board[6]) {
        if (board[2] = 'X') {
            winner = 1;
        }
        else if (board[2] = 'O') {
            winner = 2;
        }
    }
    else if (plays >= 9) {
        winner = 0;
    }
    
    return winner;
}

void end_game(char board[], int winner) {
    std::cout << "\nFinal board: \n";
    draw(board);
    if (winner == 0) {
        std::cout << "Tied game!";
    }
    else {
        std::cout << "Player " << winner << " wins the game!";
    }
}