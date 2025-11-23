#include "task14.h"
#include <iostream>

int main()
{
    long pile;
    int max_stones;
    bool computer_mode;

    init_game(pile, max_stones, computer_mode);

    //Игровой процесс
    while (pile > 0)
    {
        pile_current(pile, max_stones);
        player_move(pile, max_stones);
        if (pile == 0) {
            std::cout << "Вы выиграли!"; return 0;
        }

        if (computer_mode)
            computer_move_strategy(pile, max_stones);
        else
            computer_move_no_strategy(pile, max_stones);

        if (pile == 0) {std::cout << "Компьютер выиграл!"; return 0;}
    }

    return 0;
}