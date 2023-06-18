#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int* arr = (int*)malloc(sizeof(int)*(n+1));
    int k = 0;
    for (int i = 1; i < n+1; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 1; i < n+1; i++)
    {
        for (int j = 0; j < arr[i]; j++)
        {
            printf("=");
        }
        printf("\n");
    }
}