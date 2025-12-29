#include <stdio.h>

#define SIZE 10   // Maximum array size and radix base (0–9)

/* Function to find the largest element */
int largest(int arr[], int n)
{
    int large = arr[0], i;
    for (i = 1; i < n; i++)
    {
        if (arr[i] > large)
            large = arr[i];
    }
    return large;
}

/* Function to implement Radix Sort */
void radix_sort(int arr[], int n)
{
    int bucket[SIZE][SIZE];
    int bcount[SIZE];
    int i, j, k, rem;
    int NOD = 0, divisor = 1, large, pass;

    large = largest(arr, n);

    /* Count number of digits */
    while (large > 0)
    {
        NOD++;
        large /= 10;
    }

    /* Perform Radix Sort for each digit */
    for (pass = 0; pass < NOD; pass++)
    {
        /* Initialize bucket count */
        for (i = 0; i < SIZE; i++)
            bcount[i] = 0;

        /* Place elements into buckets */
        for (i = 0; i < n; i++)
        {
            rem = (arr[i] / divisor) % 10;
            bucket[rem][bcount[rem]] = arr[i];
            bcount[rem]++;
        }

        /* Collect elements back to array */
        i = 0;
        for (k = 0; k < SIZE; k++)
        {
            for (j = 0; j < bcount[k]; j++)
            {
                arr[i++] = bucket[k][j];
            }
        }

        divisor *= 10;
    }
}

/* Main function */
int main()
{
    int arr[SIZE], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    if (n > SIZE)
    {
        printf("Maximum allowed size is %d\n", SIZE);
        return 0;
    }

    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    radix_sort(arr, n);

    printf("Sorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}