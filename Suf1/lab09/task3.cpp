int* max_elements(int** array, int row, int col)
{
    int* result = new int[row];

    for (int i = 0; i < row; i++)
    {
        int max = array[i][0];

        for (int j = 1; j < col; j++)
        {
            if (array[i][j] > max)
            {
                max = array[i][j];
            }
        }

        result[i] = max;
    }

    return result;
}
