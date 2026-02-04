#pragma once

// Ход игрока
int player_move(int move);

// Ход компьютера
int computer_move(int current_remainder, int moves_left);

// Проверка на победителя
void check_winner(int num, int remainder);

// Игровой процесс
void game(int num);