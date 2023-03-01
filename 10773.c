#include <stdio.h>

#define MAX_SIZE (100000)

int current = -1;
int stack[MAX_SIZE];

void push(int data) 
{
    if (current >= MAX_SIZE - 1) 
    {
        return;
    }
    current++;
    stack[current] = data;
}

void pop()
{
    if (current < 0)
    {
        return;
    }
    stack[current] = 0;
    current--;
}

int main ()
{
    int K = 0;
    scanf("%d", &K);
    int sum = 0;
    int temp = 0;
    for (int i = 0; i < K; i++) 
    {
        scanf("%d", &temp);
        if (temp == 0) 
        {
            pop();
        }
        else 
        {
            push(temp);
        }
    }
    for (int i = 0; i <= current; i++)
    {
        sum = sum + stack[i];
    }
    printf("%d", sum);
    return 0;
}