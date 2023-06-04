#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int s1 = 0;
    int s2 = 0;
    int s3 = 0;
    scanf("%d %d %d", &s1, &s2, &s3);
    //int* arr = (int*)malloc(sizeof(int) * (s1+s2+s3+1));
    int arr[81] = {0, };
    for (int fidx = 1; fidx <= s1; fidx++)
    {
        for (int sidx = 1; sidx <= s2; sidx++)
        {
            for (int tidx = 1; tidx <= s3; tidx++)
            {
                arr[fidx+sidx+tidx]++;
            }
        }
    }
    int max = 0;
    int ans = 0;
    for (int i = 0; i <= 80; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
            ans = i;
        }
    }
    printf("%d", ans);
}