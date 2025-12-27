#include <iostream>

int main()
{
    int row, col;
    std::cin >> row >> col;

    int** a = new int*[row];
    for (int i = 0; i < row; i++)
        a[i] = new int[col];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            std::cin >> a[i][j];

    int index = -1;

    for (int i = 0; i < row; i++)
    {
        bool sorted = true;

        for (int j = 0; j < col - 1; j++)
        {
            if (a[i][j] > a[i][j + 1])
            {
                sorted = false;
                break;
            }
        }

        if (sorted)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
        std::cout << "NO";
    else
        std::cout << index;

    for (int i = 0; i < row; i++)
        delete[] a[i];
    delete[] a;

    return 0;
}