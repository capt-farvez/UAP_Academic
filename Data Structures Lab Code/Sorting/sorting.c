#include<stdio.h>
int main()
{
    int i, j, arrSize, key;
    printf("Enter array size : ");
    scanf("%d", &arrSize);
    int arr[arrSize];
    printf("Enter Array Elements : ");
    for (i = 0; i < arrSize; i++)
        scanf("%d", &arr[i]);

    printf("\nBefore Sorting The Array : ");
    for (i = 0; i < arrSize; i++) {
           printf("%d ", arr[i]);
        }
    printf("\nAfter Sorting The Array in Ascending Order : ");
    for (i = 1; i < arrSize; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    for (i = 0; i < arrSize; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
        return 0;
}