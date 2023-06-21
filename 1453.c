#include <stdio.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int arr[101] = {0, };
    int seat = 0;
    int kick = 0;
    for (int i = 0; i < n; i++)
    {
        //scanf("%d", &arr[i])
        scanf("%d", &seat);
        if (arr[seat] != 0)
        {
            kick++;
        }
        else
        {
            arr[seat]++;
        }
    }
    printf("%d", kick);
}