#include <stdio.h>

int input[100010];
int stk[100010];
char stk_b[200020];
int k = 1;
int wp_b = 0;
int wp = 0;

void push(int in)
{
    stk[wp++] = in;
}

int pop(void)
{
    wp--;
    return stk[wp];
}

int main(void)
{
    int n = 0;
    int cur;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &input[i]);
        while(input[i] >= k)
        {
            push(k);
            stk_b[wp_b++] = '+';
            k++;
        }
        cur = pop();
            
        if (cur == input[i])
        {
            stk_b[wp_b++] = '-';
        }   
        else
        {
            printf("NO\n");
            return 0;
        }
    }
    
    for (int i = 0; i < 2*n; i++)
    {
        printf("%c\n", stk_b[i]);
    }
}