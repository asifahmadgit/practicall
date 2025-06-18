#include <stdio.h>

#define SIZE 100

void insert(int arr[], int *n, int pos, int value) {
    if (*n >= SIZE) {
        printf("Array is full. Insertion not possible.\n");
        return;
    }

    if (pos < 0 || pos > *n) {
        printf("Invalid position. Insertion not possible.\n");
        return;
    }

    for (int i = *n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }

    arr[pos] = value;
    (*n)++;
}

void delete(int arr[], int *n, int pos) {
    if (*n <= 0) {
        printf("Array is empty. Deletion not possible.\n");
        return;
    }

    if (pos < 0 || pos >= *n) {
        printf("Invalid position. Deletion not possible.\n");
        return;
    }

    for (int i = pos; i < *n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    (*n)--;
}

void display(int arr[], int n) {
    printf("Array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int arr[SIZE], n, pos, value;

    // Input initial array
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    display(arr, n);

    // Insertion
    printf("\n---Insertion---\n");
    printf("Enter position to insert (0 to %d): ", n);
    scanf("%d", &pos);
    printf("Enter value to insert: ");
    scanf("%d", &value);
    insert(arr, &n, pos, value);
    display(arr, n);

    // Deletion
    printf("\n---Deletion---\n");
    printf("Enter position to delete (0 to %d): ", n - 1);
    scanf("%d", &pos);
    delete(arr, &n, pos);
    display(arr, n);

    return 0;
}
