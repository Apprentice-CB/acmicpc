#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX (10000)

int stack[MAX] = {0, };
int count = -1;

void push(int new_data)
{
    count++;
    stack[count] = new_data;
}

int pop()
{
    if (count == -1)
    {
        return -1;
    }
    else
    {
        count--;
        return stack[count+1];
    }
}

int size()
{
    return count+1;
}

int empty()
{
    if (count == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int top()
{
    if (count == -1)
    {
        return -1;
    }
    else
    {
        return stack[count];
    }
}

int main() 
{
    char command[6];
    int N = 0;
    int value = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s", command);
        if (!strcmp(command, "push"))
        {
            scanf("%d", &value);
            push(value);
        }
        else if (!strcmp(command, "pop"))
        {
            printf("%d\n", pop());
        }
        else if (!strcmp(command, "size"))
        {
            printf("%d\n", size());
        }
        else if (!strcmp(command, "empty"))
        {
            printf("%d\n", empty());
        }
        else if (!strcmp(command, "top"))
        {
            printf("%d\n", top());
        }
        else
        {
            /* do nothing */
        }
    }
    return 0;
}