#include <stdio.h>

int main(void)
{
    int T = 0;
    int k = 0;
    int y = 0;
    int k_in = 0;
    int y_in = 0;
    scanf("%d", &T);
    for (int j = 0; j < T; j++) 
    {
        for (int i = 0; i < 9; i++)
        {
            scanf("%d %d", &y_in, &k_in);
            k += k_in;
            y += y_in;
        }
    
        if (k > y)
        {
            printf("Korea");
        }
        else if (k < y)
        {
            printf("Yonsei");
        }
        else
        {
            printf("Draw");
        }
    }
    return 0;
}