#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define pause 1000000

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int lf = low + 1;
    int rf = high;
    printf("Creating partition with lo = %d, hi = %d\n", low, high);
    usleep(pause);
    while (lf <= rf) {
        while (lf <= rf && arr[lf] <= pivot) {
            printf("%d <= %d, incrementing lf.\n", arr[lf], pivot);
            usleep(pause);
            lf++;
        }
        while (lf <= rf && arr[rf] >= pivot) {
            printf("%d >= %d, decrementing lf.\n", arr[rf], pivot);
            usleep(pause);
            rf--;
        }
        if (lf < rf) {
            swap(&arr[lf], &arr[rf]);
            printf("lf < rf, swapping %d and %d.\n", arr[lf], arr[rf]);
            usleep(pause);
            for (int i = low; i < high; i++) {
                printf("%d ", arr[i]);
            }
        printf("\n");
        }
    }
    swap(&arr[low], &arr[rf]);
    return rf;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {
    int max_size = 10;
    int* arr = (int*) malloc(max_size * sizeof(int));
    int n = 0;
    int input;

    printf("Enter numbers (enter -1 to stop):\n");
    while (1) {
        scanf("%d", &input);
        if (input == -1) {
            break;
        }

        if (n == max_size) {
            max_size *= 2;
            arr = (int*) realloc(arr, max_size * sizeof(int));
        }

        arr[n] = input;
        n++;
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}

