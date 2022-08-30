#include <stdio.h>
#include <stdlib.h>

// Leetcode #1

int* twoSum(int* nums, int nums_size, int target, int* return_size)
{
    int* out_array;

    out_array = (int*) calloc(*return_size, sizeof(int));

    for (int i = 0; i < nums_size; i++)
        for (int j = 0; j < nums_size; j++)
            if (i != j && nums[i] + nums[j] == target)
            {
                out_array[0] = i;
                out_array[1] = j;
                return out_array;
            }
    return out_array;
}

int main()
{
    int* in_array;
    int* return_size;
    int array_size = 0;
    int target = 0;

    printf("\nEnter array size:\n");
    scanf("%d", &array_size);

    in_array = (int*) malloc(array_size * sizeof(int));

    printf("Enter array values:\n");
	for(int i = 0; i < array_size; i++)
		scanf("%d",&in_array[i]); 

    printf("\nEnter target number:\n");
    scanf("%d", &target);

    return_size = (int*) malloc(sizeof(int));
    *return_size = 2;

    int* out_array = twoSum(in_array, array_size, target, return_size);

    printf("\nArray:\n");
    for (int i = 0; i < array_size; i++)
    {
        printf("%d", in_array[i]);
        if (i != array_size - 1)
            printf(",");
    }
    if (out_array[0] == out_array[1])
        printf("\nNo two values sum to %d.\n", target);
    else
        printf("\nSum of elements %d and %d is %d.\n", out_array[0] + 1, out_array[1] + 1, target);
        
    printf("\n");

    free(in_array);
    free(out_array);
}
