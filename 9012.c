#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX (50)

typedef struct node
{
    
} node;

static char stack[MAX];
static int left = 0;
static int right = 0;

 pop()
{

}

int main()
{
    int T = 0;
    int length = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) 
    {
        scanf("%s", stack);
        length = strlen(stack);
        if (!strcmp(stack[0], ")"))
        {
            printf("NO\n");
            break;
        }
        else 
        {
            for (int idx = 0; idx < length; idx++) 
            {
                if (!strcmp(stack[idx], ")"))
                {
                    right++;
                }
                else if (!strcmp(stack[idx], "("))
                {
                    left++;
                }
            }
            if (right == left)
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
}