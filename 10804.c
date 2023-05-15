#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int arr[20];
    for (int i = 0; i < 20; i++)
    {
        arr[i] = i+1;
    }

    int a = 0;
    int b = 0;
    int temp = 0;
    for (int i = 0; i < 10; i++)
    {
        scanf("%d %d", &a, &b);
        for (int j = 0; j < (b-a+1)/2; j++)
        {
            temp = arr[a-1+j];
            arr[a-1+j] = arr[b-1-j];
            arr[b-1-j] = temp;
        }
    }

    for (int i = 0; i < 20; i++)
    {
        printf("%d ", arr[i]);
    }

}
