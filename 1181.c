#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node
{
    char word[51];
    int len;
} node;

int compare(const void* x, const void* y)
{
    node* a = (node*)x;
    node* b = (node*)y;
    //return ((node*)a)->len > ((node*)b)->len;
    return a->len > b->len ? 1: a->len < b->len ? -1 : strcmp(a->word, b->word);
}

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    node* arr = (node*)malloc(sizeof(node)*N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", arr[i].word);
        arr[i].len = strlen(arr[i].word);
    }

    qsort(arr, N, sizeof(node), compare);

    printf("%s\n", arr[0].word);
    for (int i = 1; i < N; i++)
    {
        if (strcmp(arr[i-1].word, arr[i].word))
        {
            printf("%s\n", arr[i].word);
        }
    }

}