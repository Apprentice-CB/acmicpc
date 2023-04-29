#include <stdio.h>

int main(void)
{
    int N = 0;
    int r = 0;
    int e = 0;
    int c = 0;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d %d", &r, &e, &c);
        if (r < e - c)
        {
            printf("advertise\n");
        }
        else if (r == e-c)
        {
            printf("dose not matter\n");
        }
        else
        {
            printf("do not advertise\n");
        }
    }
}