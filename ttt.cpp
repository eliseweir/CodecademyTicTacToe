#include <iostream>
#include "ttt_functions.hpp"

int main() {
    bool won = false;
    bool valid_play = false;
    int position;
    int plays = 0;
    //std::vector<char> board = {'1','2','3','4','5','6','7','8','9'};
    char board[] = {'1','2','3','4','5','6','7','8','9'};

    while (!won && plays < 9) {

        while (!valid_play && !won) {
            draw(board);
            std::cout << "Player 1: Pick a position (1-9): ";
            std::cin >> position;

            if(board[position - 1] != 'X' && board[position - 1] != 'O') {
                board[position - 1] = 'X';
                valid_play = true;
                plays++;
                if (plays >= 9) {
                    won = true;
                }
            }
        }
        valid_play = false;

        while (!valid_play && !won) {
            draw(board);
            std::cout << "Player 2: Pick a position (1-9): ";
            std::cin >> position;

            if(board[position - 1] != 'X' && board[position - 1] != 'O') {
                board[position - 1] = 'O';
                valid_play = true;
                plays++;
                if (plays >= 9) {
                    won = true;
                }
            }
        }
        valid_play = false;


  }
}