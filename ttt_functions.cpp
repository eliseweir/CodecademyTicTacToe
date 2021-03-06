#include <iostream>
#include<limits>
#include <string>
using namespace std;

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

// take a turn putting down a marker
void take_turn(char board[], int winner, int player, int &plays) {
    int position;
    bool valid_play = false;

    // while the play is not valid and there is no winner, continue prompting
    while (!valid_play && winner == -1) {
        // draw the board and ask the player to pick a position
        cout << string( 100, '\n' );
        draw(board);
        std::cout << "Player "<< player << ": Pick a position (1-9): ";
        std::cin >> position;

        // check for non-integer or non 1-9 input
        while(1) {
            if (std::cin.fail() || position < 1 || position > 9) {
                std::cin.clear();
                std::cin.ignore(numeric_limits<streamsize>::max(),'\n');
                cout << string( 100, '\n' );
                draw(board);
                std::cout << "Player "<< player << ": Pick a position (1-9): ";
                std::cin >> position;
            }
            if (!std::cin.fail()) {
                break;
            }
        }

        // if the space is empty, fill with the player's marker, mark it as 
        // a valid play, and iterate the total number of plays
        if(board[position - 1] != 'X' && board[position - 1] != 'O') {
            if (player == 1) {
                board[position - 1] = 'X';
            }
            else if (player == 2) {
                board[position - 1] = 'O';
            }
            valid_play = true;
            plays++;
        }
    }
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

// remove position numbers from the board
void clean_board(char board[]) {
    for (int k=0; k < 9; k++) {
        if (board[k] != 'X' && board[k] != 'O') {
            board[k] = ' ';
        }
    }
}

// output the result of the game
void end_game(char board[], int winner) {
    // clean up the board for display
    clean_board(board);

    // output the final board and the winner
    cout << string( 100, '\n' );
    std::cout << "\nFinal board:\n";
    draw(board);
    if (winner == 0) {
        std::cout << "Tied game!";
    }
    else {
        std::cout << "Player " << winner << " wins the game!";
    }
}