#include <iostream>

void init_console(int** array, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cin >> array[i][j];
        }
    }
}

int** init_console(int row, int col)
{
    int** array = new int*[row];

    for (int i = 0; i < row; i++)
    {
        array[i] = new int[col];
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cin >> array[i][j];
        }
    }

    return array;
}

void print_console(int** array, int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}