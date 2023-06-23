#include <stdio.h>

int main(void)
{
    char chs[8][8];
    for (int i = 0; i < 8; i++)
    {
        scanf("%s", &chs[i]);
    }

    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if (chs[i][j] == 'F')
            {
                if (i % 2 == 0 && j % 2 == 0)
                {
                    cnt++;
                }
                if (i % 2 == 1 && j % 2 == 1)
                {
                    cnt++;
                }
            }
        }
    }
    printf("%d", cnt);
}