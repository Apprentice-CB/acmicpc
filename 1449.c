#include <stdio.h>
#include <stdlib.h>
int arr[1001] = {0, };
int tape[1001] = {0, };

int compare(const void *a, const void *b)
{   
    int num1 = *(int*)a;
    int num2 = *(int*)b;
    if (num1 < num2)
    {
        return -1;
    }
    else if (num1 > num2)
    {
        return 1;
    }
    return 0;
}

int main(void)
{
    int N = 0;
    int L = 0;
    scanf("%d %d", &N, &L);
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }

    qsort(arr, N, sizeof(int), compare);
    int cnt = 0;
    
    for (int i = 0; i < N; i++)
    {
        if (tape[arr[i]] == 0)
        {
            for (int j = 0; j < L; j++)
            {
                tape[arr[i]+j] = 1;
            }
            cnt++;
        }
    }
    printf("%d", cnt);
}