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

    int len = 0;
    int temp = 0;
    for (int i = 0; i < N; i++)
    {
        if (strcmp(arr[temp].word, arr[i].word))
        {
            printf("%s\n", arr[temp].word);
            temp = i;
        }
    }

}