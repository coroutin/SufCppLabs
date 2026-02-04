int find_element(int* const array, int size, int element) {
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            return i;
        }
    }
    return -1;
}

int count_element(int* const array, int size, int element) {
    int count = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            count++;
        }
    }

    return count;
}