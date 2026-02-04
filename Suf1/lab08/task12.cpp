void insert_element(int*& array, int& size, int index, int value) {
    if (index < 0 || index > size) return;

    int* new_array = new int[size + 1];

    for (int i = 0; i < index; i++) {
        new_array[i] = array[i];
    }

    new_array[index] = value;

    for (int i = index; i < size; i++) {
        new_array[i + 1] = array[i];
    }

    size++;

    delete[] array;
    array = new_array;
}