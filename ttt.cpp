#include <iostream>
#include "ttt_functions.hpp"

int main() {
    int position;
    int plays = 0;
    int winner = -1;
    bool valid_play = false;
    char board[] = {'1','2','3','4','5','6','7','8','9'};

    while (winner == -1 && plays < 9) {

        while (!valid_play && winner == -1) {
            draw(board);
            std::cout << "Player 1: Pick a position (1-9): ";
            std::cin >> position;

            if(board[position - 1] != 'X' && board[position - 1] != 'O') {
                board[position - 1] = 'X';
                valid_play = true;
                plays++;
            }
        }
        valid_play = false;

        // check if the game has been won
        winner = check_winner(board, winner, plays);

        while (!valid_play && winner == -1) {
            draw(board);
            std::cout << "Player 2: Pick a position (1-9): ";
            std::cin >> position;

            if(board[position - 1] != 'X' && board[position - 1] != 'O') {
                board[position - 1] = 'O';
                valid_play = true;
                plays++;
                if (plays >= 9) {
                    winner = 0;
                }
            }
        }
        valid_play = false;

        // check if the game has been won
        winner = check_winner(board, winner, plays);
    }

    // display the winner of the game
    end_game(board, winner);

}