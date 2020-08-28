#include <iostream>
#include "ttt_functions.hpp"

int main() {
    int plays = 0; // number of turns taken
    int winner = -1; // current winner: no one -1, tie 0, player 1, or player 2
    char board[] = {'1','2','3','4','5','6','7','8','9'};

    // continue to play while there is no winner and the board is not filled up
    while (winner == -1 && plays < 9) {

        // have player 1 take a turn
        take_turn(board, winner, 1, plays);

        // check if the game has been won
        winner = check_winner(board, winner, plays);

        // have player 2 take a turn
        take_turn(board, winner, 2, plays);

        // check if the game has been won
        winner = check_winner(board, winner, plays);
    }

    // display the winner of the game
    end_game(board, winner);

}