#include <stdio.h>
#include <stdlib.h>

int n;
int arr[100000+10];
int x;

int static compare (const void* first, const void* second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}

int main(void)
{
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    scanf("%d", &x);

    qsort(arr, n, sizeof(int), compare);

    int a = 0;
    int b = n-1;

    while(a < b)
    {
        if (arr[a] + arr[b] > x)
        {
            b--;
        }
        else if (arr[a] + arr[b] < x)
        {
            a++;
        }
        else
        {
            ans++;
            a++;
        }
    }
    printf("%d", ans);
}