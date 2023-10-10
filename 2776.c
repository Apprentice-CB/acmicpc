#include <stdio.h>
#include <stdlib.h>

int T;
int N, M;
int arr1[1000000+10];
int arr2[1000000+10];

void getInput()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr1[i]);
    }
    scanf("%d", &M);
    for (int i = 0; i < M; i++)
    {
        scanf("%d", &arr2[i]);
    }
}

int compare(const void* a, const void* b)
{
    return *(int*)a - *(int*) b;
}

int main(void)
{
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        getInput();
        qsort(arr1, N, sizeof(int), compare);
        
        for (int j = 0; j < M; j++)
        {
            int* find = bsearch(&arr2[j], arr1, N, sizeof(int), compare);
            if (find == NULL) printf("0\n");
            else printf("1\n");
        }
    }
    
    return 0;
}