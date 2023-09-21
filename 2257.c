#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int stack[101];
char str[101];
int sp;

int main(void)
{
    scanf("%s", str);
    int len = strlen(str);
    int i = 0;
    int sum = 0;
    while (1)
    {
        if (i >= len) 
        {
            // printf("i:%d, len:%d\n", i, len);
            break;    // 종료 조건
        }
        if (str[i] == '(') // Depth가 생길 떄
        {
            sp++;
        }
        else if (str[i] == ')') // Depth 낮아질 때
        {
            if ('1' <= str[i+1] && str[i+1] <= '9')
            {
                stack[sp] *= (str[i+1]-'0');
            }
            stack[sp-1] += stack[sp];
            stack[sp] = 0;
            sp--;
        }
        else if (str[i] == 'H')
        {
            if ('1' <= str[i+1] && str[i+1] <= '9')
            {
                stack[sp] += 1 * (str[i+1]-'0');
            }
            else
                stack[sp] += 1;
        }
        else if (str[i] == 'C')
        {
            if ('1' <= str[i+1] && str[i+1] <= '9')
            {
                stack[sp] += 12 * (str[i+1] - '0');
            }
            else
                stack[sp] += 12;
        }
        else if (str[i] == 'O')
        {
            if ('1' <= str[i+1] && str[i+1] <= '9')
            {
                stack[sp] += 16 * (str[i+1] - '0');
            }
            else
            {
                stack[sp] += 16;
            }
        }
        // for (int j = 0; j <= sp; j++)
        // {
        //     printf("%d ", stack[j]);
        // } printf("\n");
        i++;
    }
    printf("%d\n", stack[0]);
}