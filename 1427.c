#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare (const void* a, const void* b)
{
    int x = *(int*)a;
    int y = *(int*)b;
    return x < y;
}

int main(void)
{
    int input = 0;
    scanf("%d", &input);
    int arr[10] = {0, };
    int length = 0;
    while (input > 0)
    {
        arr[length] = input % 10;
        input = input / 10;
        length++;
    }
    qsort(arr, length, sizeof(int), compare);
    
    for (int i = 0; i < length; i++)
    {
        printf("%d", arr[i]);
    }
}