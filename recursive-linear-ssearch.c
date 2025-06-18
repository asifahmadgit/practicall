#include <stdio.h>

// Recursive function to search for an element in the array
int recursiveLinearSearch(int arr[], int key, int index, int size) {
    if (index >= size) {
        return -1;  // Element not found
    }
    if (arr[index] == key) {
        return index;  // Element found
    }
    return recursiveLinearSearch(arr, key, index + 1, size);  // Recursive call
}

int main() {
    int arr[100], n, key, i, result;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    result = recursiveLinearSearch(arr, key, 0, n);

    if (result != -1)
        printf("Element %d found at index %d.\n", key, result);
    else
        printf("Element %d not found in the list.\n", key);

    return 0;
}
