#include <stdio.h>
#include <string.h>

int main(void)
{
    char A[7];
    char B[7];
    scanf("%s %s", A, B);
    int sum = 0;
    for (int aidx = 0; aidx < strlen(A); aidx++)
    {
        for (int bidx = 0; bidx < strlen(B); bidx++)
        {
            sum += (A[aidx]-48) * (B[bidx]-48);
        }
    }
    printf("%d", sum);
}