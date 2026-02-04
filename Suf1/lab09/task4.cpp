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

    int* first_row = new int[row];
    for (int i = 0; i < row; i++)
        first_row[i] = a[i][0];

    int* last_col = new int[col];
    for (int j = 0; j < col; j++)
        last_col[j] = a[row - 1][j];

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (j == 0)
                continue;

            if (i == row - 1)
                continue;

            if (a[i][j] > 0)
                a[i][j] *= first_row[i];
            else if (a[i][j] < 0)
                a[i][j] *= last_col[j];
        }
    }

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
            std::cout << a[i][j] << " ";
        std::cout << std::endl;
    }

    for (int i = 0; i < row; i++)
        delete[] a[i];
    delete[] a;

    delete[] first_row;
    delete[] last_col;

    return 0;
}
