#include <stdio.h>

int main(void)
{
    char arr[5][15] = {0, };
    for (int col = 0; col < 5; col++)
    {
        scanf("%s", arr[col]);
    }

    for (int row = 0; row < 15; row++)
    {
        for (int col = 0; col < 5; col++)
        {
            if (arr[col][row] == 0)
            {
                continue;
            }
            else
            {
                printf("%c", arr[col][row]);
            }
        }
    }
}