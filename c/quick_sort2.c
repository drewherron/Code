#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define pause 5000000

void clearScreen() {
    printf("\033[2J\033[1;1H");
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[low];
    int lf = low + 1;
    int rf = high;
    
    while (lf <= rf) {
        clearScreen();
        printf("Partition with low: %d and high: %d.\n", low, high);
        for (int i = low; i <= high; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
        for (int i = low; i <= high; i++) {
            if (i == lf) {
                printf("^ ");
            } else if (i == rf) {
                printf("^");
                break;
            } else {
                printf("  ");
            }
        }
        printf("\n");
        for (int i = low; i <= high; i++) {
            if (i == lf) {
                printf("lf");
            } else if (i == rf) {
                printf("rf");
                break;
            } else {
                printf("  ");
            }
        }
        printf("\npivot: %d, lf: %d, rf: %d\n", pivot, lf, rf);

        if (arr[lf] <= pivot && lf <= rf) {
            printf("Comparing %d <= %d, incrementing lf.\n", arr[lf], pivot);
            usleep(pause);
            lf++;
        } else if (arr[rf] >= pivot && lf <= rf) {
            printf("Comparing %d >= %d, decrementing rf.\n", arr[rf], pivot);
            usleep(pause);
            rf--;
        } else if (lf < rf) {
            swap(&arr[lf], &arr[rf]);
            printf("Swapping %d and %d.\n", arr[lf], arr[rf]);
            usleep(pause);
        }
    }
    printf("Old low: %d and old rf: %d.\n", arr[low], arr[rf]);
    swap(&arr[low], &arr[rf]);
    printf("New low: %d and new rf: %d.\n", arr[low], arr[rf]);
    usleep(pause);

    return rf;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high);
        usleep(pause);
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

    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
