#include <iostream>

int main()
{
    int row, col;
    std::cin >> row >> col;

    int** a = new int*[row];
    int** b = new int*[row];

    for (int i = 0; i < row; i++)
    {
        a[i] = new int[col];
        b[i] = new int[col];
    }

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            std::cin >> a[i][j];

    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            std::cin >> b[i][j];

    bool found = false;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (a[i][j] == b[i][j])
            {
                std::cout << a[i][j] << " ";
                found = true;
            }
        }
    }

    if (!found)
        std::cout << "NO";

    for (int i = 0; i < row; i++)
    {
        delete[] a[i];
        delete[] b[i];
    }
    delete[] a;
    delete[] b;

    return 0;
}