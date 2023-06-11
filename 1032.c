#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    int N = 0;
    char input[50];
    char ans[50];
    scanf("%d", &N);
    scanf("%s", input);
    memcpy(ans, input, sizeof(char) * strlen(input));
    for (int i = 0; i < N-1; i++)
    {
        scanf("%s", input);
        for (int j = 0; j < strlen(input); j++)
        {
            if (input[j] != ans[j])
            {
                ans[j] = '?';
            }
        }
    }
    for (int i = 0; i < strlen(input); i++)
    {
        printf("%c", ans[i]);
    }
}