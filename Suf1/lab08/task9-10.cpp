int* find_all_elements(int* const array, int size, int element, int& count) {
    count = 0;

    for (int i = 0; i < size; i++) {
        if (array[i] == element) count++;
    }

    if (count == 0) return nullptr;

    int* index = new int[count];
    int idx = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == element) {
            index[idx++] = i;
        }
    }

    return index;
}

int* find_all_elements(int* const array, int size, bool(*condition)(int), int& count) {
    count = 0;

    for (int i = 0; i < size; i++) {
        if (condition(array[i])) count++;
    }

    if (count == 0) return nullptr;

    int* result = new int[count];
    int idx = 0;
    for (int i = 0; i < size; i++) {
        if (condition(array[i])) {
            result[idx++] = array[i];
        }
    }

    return result;
}