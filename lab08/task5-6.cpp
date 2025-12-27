int find_element(int* const array, int size, bool(*condition)(int)) {
    for (int i = 0; i < size; i++) {
        if (condition(array[i])) {
            return i;
        }
    }
    return -1;
}

int count_element(int* const array, int size, bool(*condition)(int)) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (condition(array[i])) {
            count++;
        }
    }
    return count;
}