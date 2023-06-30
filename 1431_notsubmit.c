#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{
    char serial[51];
    int length;
} node;

int compare(const void* a, const void* b)
{
    node* x = (node*)a;
    node* y = (node*)b;
    if (x->length > y->length)
    {
        return 1;
    }
    else if (x->length < y->length)
    {
        return -1;
    }
    else
    {
        int x_num = 0;
        int y_num = 0;
        for (int i = 0; i < x->length; i++)
        {
            if (isdigit(x->serial[i]))
            {
                x_num += x->serial[i];
            }
            if (isdigit(y->serial[i]))
            {
                y_num += y->serial[i];
            }
        }
        if (x_num > y_num)
        {
            return 1;
        }
        else if (x_num == y_num)
        {
            return strcmp(x->serial, y->serial);
        }
        else 
        {
            return -1;
        }
    }
}

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    node* arr = (node*)malloc(sizeof(node) * N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", arr[i].serial);
        arr[i].length = strlen(arr[i].serial);
    }
    
    qsort(arr, N, sizeof(node), compare);

    for (int i = 0; i < N; i++)
    {
        printf("%s\n", arr[i].serial);
    }

}