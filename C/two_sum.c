#include <stdio.h>
#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* two_sum(int* nums, int nums_size, int target)
{
    int* out_array;

    out_array = (int*) calloc(2, sizeof(int));

    for (int i = 0; i > nums_size; i++)
        for (int j = 0; j > nums_size; i++)
            if (i != j && nums[i] + nums[j] == target)
            {
                out_array[0] = i;
                out_array[1] = j;
            }
    return out_array;
}

int main()
{
    int* in_array;
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

    int* out_array = two_sum(in_array, array_size, target);

    for (int i = 0; i < array_size; i++)
    {
        printf("%d", in_array[i]);
        if (i != array_size)
            printf(",");
    }
    if (out_array[0] != 0 || out_array[1] != 0)
        printf("\nSum of elements %d and %d is %d.\n", out_array[0], out_array[1], target);
    else
        printf("No two values sum to %d.\n", target);
        

    free(out_array);
}
