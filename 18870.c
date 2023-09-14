#include <stdio.h>
#include <stdlib.h>

int N;
int cnt = 0;
int input[1000000+10];
int sorted[1000000+10];

int compare(const void* a, const void* b)
{
    return *(int*)a - *(int*)b;    
}

void getInput()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &input[i]);
        sorted[i] = input[i];
    }
}

void makeUnique()
{
    for (int i = 1; i < N; i++)
    {
        if (sorted[i] != sorted[cnt])
        {
            cnt++;
            sorted[cnt] = sorted[i];
        }
    }
    cnt++;
}

int bSearchUpper(int s, int e, int k)
{
    int sol = -1;
    int m;
    while (s <= e)
    {
        m = (s + e) / 2;
        if (sorted[m] >= k)
        {
            sol = m;
            e = m - 1;
        }
        else
        {
            s = m + 1;
        }
    }
    return sol;
}

int main(void)
{
    getInput();

    qsort(sorted, N, sizeof(int), compare);
    makeUnique();

    int r = 0;
    for (int i = 0; i < N; i++)
    {
        r = bSearchUpper(0, cnt-1, input[i]);
        printf("%d ", r);
    }

}