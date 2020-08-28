#include <iostream>
void draw(char board[]);
void take_turn(char board[], int winner, int player, int &plays);
int check_winner(char board[], int winner, int plays);
void end_game(char board[], int winner);