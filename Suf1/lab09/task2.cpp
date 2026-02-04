bool find_first_element(int** array, int row, int col,
int element, int &irow, int &icol)
{
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (array[i][j] == element)
            {
                irow = i;
                icol = j;
                return true;
            }
        }
    }

    irow = -1;
    icol = -1;
    return false;
}

bool find_last_element(int** array, int row, int col,
                       int element, int &irow, int &icol)
{
    bool found = false;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if (array[i][j] == element)
            {
                irow = i;
                icol = j;
                found = true;
            }
        }
    }

    if (!found)
    {
        irow = -1;
        icol = -1;
    }

    return found;
}