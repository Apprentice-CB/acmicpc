#include <stdio.h>

int main(void)
{
    int a[3] = {0, };
    scanf("%d %d %d", a, a+1, a+2);
    int temp = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = i + 1; j < 3; j++)
        {
            if (a[i] > a[j])
            {
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }
        }
    }
    while (a[0] + a[1] <= a[2])
    {
        a[2]--;
    }
    printf("%d", a[0] + a[1] + a[2]);
    
}