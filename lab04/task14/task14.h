#pragma once

// Инициализация игры. Пользователь введёт количество камней, максимально возможное количество камней за ход и выберет режим компьютера
void init_game(long &pile, int &max_stones, bool &computer_mode);

// Показ текущего состояния кучи
void pile_current(long pile, int max_stones);

// Ход пользователя
void player_move(long &pile, int max_stones);

// Ход компьютера со стратегией
int computer_move_strategy(long &pile, int max_stones);

// Ход компьютера без стратегии
int computer_move_no_strategy(long &pile, int max_stones);

// Проверка на конец игры
inline bool game_over(long &pile) {
    return pile == 0;
}
