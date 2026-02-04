void delete_by_index(int*& array, int& size, int index) {
    if (index < 0 || index >= size) return;

    for (int i = index; i < size - 1; i++) {
        array[i] = array[i + 1];
    }

    size--;

    int* new_array = new int[size];
    for (int i = 0; i < size; i++) {
        new_array[i] = array[i];
    }

    delete[] array;
    array = new_array;
}

int* get_array_delete_by_index(int* array, int size, int index, int& new_size) {
    if (index < 0 || index >= size) {
        new_size = size;
        return nullptr;
    }

    new_size = size - 1;
    int* new_array = new int[new_size];

    for (int i = 0, j = 0; i < size; i++) {
        if (i != index) {
            new_array[j++] = array[i];
        }
    }

    return new_array;
}