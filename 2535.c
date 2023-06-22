#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    int country;
    int number;
    int score;
} node;

int compare(const void* a, const void* b)
{
    return ((node*)a)->score < ((node*)b)->score;
}

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    node* arr = (node*)malloc(sizeof(node)*N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &arr[i].country, &arr[i].number, &arr[i].score);
    }

    qsort(arr, N, sizeof(node), compare);

    int* check = (int*)malloc(sizeof(int)*(N+1));
    memset(check, 0, sizeof(int)*(N+1));
    for (int i = 0, cnt = 0; i < N && cnt < 3; i++)
    {
        if (check[arr[i].country] < 2)
        {
            check[arr[i].country]++;
            printf("%d %d\n", arr[i].country, arr[i].number);
            cnt++;
        }
    }


}