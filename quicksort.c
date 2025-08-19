#include <stdio.h>

void swap(int k[], int i, int j) {
    int temp = k[i];
    k[i] = k[j];
    k[j] = temp;
}

int partition(int k[], int low, int high) {
    int pivot = k[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (k[j] < pivot) {
            i++;
            swap(k, i, j);
        }
    }
    swap(k, i + 1, high);
    return i + 1;
}

void quickSort(int k[], int low, int high) {
    if (low < high) {
        int pi = partition(k, low, high);
        quickSort(k, low, pi - 1);
        quickSort(k, pi + 1, high);
    }
}

void printArray(int k[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", k[i]);
    printf("\n");
}

int main() {
    int k[] = {5, 3, 19, 14, 67};
    int n = sizeof(k) / sizeof(k[0]);

    printf("Original array: ");
    printArray(k, n);

    quickSort(k, 0, n - 1);

    printf("Sorted array: ");
    printArray(k, n);

    return 0;
}