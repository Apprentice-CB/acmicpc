#include <stdio.h>

int main(void)
{
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;
    int arr[5] = {0, };
    int max_i;
    int max_s = 0;
    for (int i = 0; i < 5; i++)
    {
        scanf("%d %d %d %d", &a, &b, &c, &d);
        arr[i] = a + b + c + d;
        if (max_s < arr[i])
        {
            max_s = arr[i];
            max_i = i+1;
        }
    }
    printf("%d %d\n", max_i, max_s);
}