#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char input[9];
    int N = 0;
    scanf("%d", &N);
    char *A;
    char *B;
    int x = 0;
    int y = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%s", input);
        if (!strcmp(input, "P=NP"))
        {
            printf("skipped\n");
        }
        else
        {
            A = strtok(input, "+");
            B = A + strlen(A) + 1;
            x = atoi(A);
            y = atoi(B);
            printf("%d\n", x+y);
        }
    }
}