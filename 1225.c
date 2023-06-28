#include <stdio.h>
#include <string.h>

int main(void)
{
    char A[10001];
    char B[10001];
    scanf("%s %s", A, B);
    long long int sum = 0;
    for (int aidx = 0; aidx < strlen(A); aidx++)
    {
        for (int bidx = 0; bidx < strlen(B); bidx++)
        {
            sum += (A[aidx]-48) * (B[bidx]-48);
        }
    }
    printf("%lld", sum);
}