void delete_elements(int*& array, int& size, int index, int amount) {
    if (index < 0 || index >= size || amount <= 0) return;
    if (index + amount > size) amount = size - index;
    int new_size = size - amount;
    int* new_array = new int[new_size];

    for (int i = 0; i < index; i++) {
        new_array[i] = array[i];
    }

    for (int i = index + amount, j = index; i < size; i++, j++) {
        new_array[j] = array[i];
    }

    delete[] array;
    array = new_array;
    size = new_size;
}