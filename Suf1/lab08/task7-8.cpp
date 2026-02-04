int max_element(int* const array, int size) {
    if (size <= 0) return -1;

    int max_index = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] > array[max_index]) {
            max_index = i;
        }
    }
    return max_index;
}

int min_element(int* const array, int size) {
    if (size <= 0) return -1;

    int min_index = 0;
    for (int i = 1; i < size; i++) {
        if (array[i] < array[min_index]) {
            min_index = i;
        }
    }
    return min_index;
}

int max_element(int* const array, int size, bool(*condition)(int)) {
    int max_index = -1;
    for (int i = 0; i < size; i++) {
        if (condition(array[i])) {
            if (max_index == -1 || array[i] > array[max_index]) {
                max_index = i;
            }
        }
    }
    return max_index;
}

int min_element(int* const array, int size, bool(*condition)(int)) {
    int min_index = -1;
    for (int i = 0; i < size; i++) {
        if (condition(array[i])) {
            if (min_index == -1 || array[i] < array[min_index]) {
                min_index = i;
            }
        }
    }
    return min_index;
}