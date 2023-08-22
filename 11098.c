#include <stdio.h>
#include <string.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int p;
    char name[21];
    char max_name[21];
    int c;
    int max_c = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p);
        c = 0;
        max_c = 0;
        for (int j = 0; j < p; j++)
        {
            scanf("%d %s", &c, name);
            if (c > max_c)
            {
                max_c = c;
                strcpy(max_name, name);
            }
        }
        printf("%s\n", max_name);
    }
}