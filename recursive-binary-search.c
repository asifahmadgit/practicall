#include <stdio.h>

// Recursive binary search function
int recursiveBinarySearch(int arr[], int low, int high, int key) {
    if (low > high) {
        return -1; // Base case: not found
    }

    int mid = (low + high) / 2;

    if (arr[mid] == key) {
        return mid; // Element found
    } else if (key < arr[mid]) {
        return recursiveBinarySearch(arr, low, mid - 1, key); // Search in left half
    } else {
        return recursiveBinarySearch(arr, mid + 1, high, key); // Search in right half
    }
}

int main() {
    int arr[100], n, key, i, result;

    printf("Enter the number of elements in the list: ");
    scanf("%d", &n);

    printf("Enter %d sorted elements (in ascending order):\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

    result = recursiveBinarySearch(arr, 0, n - 1, key);

    if (result != -1)
        printf("Element %d found at index %d.\n", key, result);
    else
        printf("Element %d not found in the list.\n", key);

    return 0;
}   