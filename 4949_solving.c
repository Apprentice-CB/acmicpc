#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct node
{
    char bracket;
    struct node* next;
} node;

typedef struct stack
{
    struct node* first;
    struct node* last;
} stack;

void initStack(stack* s)
{
    s->first = NULL;
    s->last = NULL;
}

void push(stack* s, char bra)
{
    node* temp = (node*)malloc(sizeof(node));
    temp->bracket = bra;
    if (s->last == NULL)
    {
        s->last = temp;
        s->first = temp;
    }
    else
    {
        temp->next = s->last;
        s->last = temp;
    }
}

char pop(stack* s)
{
    node* temp = s->last;
    char bra = temp->bracket;
    s->last = temp->next;
    free(temp);
    return bra;
}

int main(void)
{
    char str[100];
    scanf("%s", str);
    bool ok = true;
    char temp;
    while (!(strlen(str) == 1 && str[0] == '.'))
    {
        printf("%d\n", strlen(str));
        stack* s = (stack*)malloc(sizeof(stack));
        initStack(s);
        while(1)
        {
            //printf("%d\n", strlen(str));
            for (int i = 0; i < strlen(str); i++)
            {
                if (str[i] == '[')
                {
                    push(s, str[i]);
                    ok = false;
                    //printf("push %c\n", str[i]);
                }
                else if (str[i] == '(')
                {
                    push(s, str[i]);
                    ok = false;
                    //printf("push %c\n", str[i]);
                }
                else if (str[i] == ']')
                {
                    if (s->first == NULL)
                    {
                        ok = false;
                        break;
                    }
                    temp = pop(s);
                    //printf("pop %c\n", temp);
                    if (temp == '[')
                    {
                        ok = true;
                    }
                    else
                    {
                        ok = false;
                    }
                }
                else if (str[i] == ')')
                {
                    if (s->first == NULL)
                    {
                        ok = false;
                        break;
                    }
                    temp = pop(s);
                    //printf("pop %c\n", temp);
                    if (temp == '(')
                    {
                        ok = true;
                    }
                    else
                    {
                        ok = false;
                    }
                }
            }
            if (str[strlen(str)-1] == '.')
            {
                break;
            }
            scanf("%s", str);
        }
        if (ok)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
        scanf("%s", str);
        free(s);
    }    
}