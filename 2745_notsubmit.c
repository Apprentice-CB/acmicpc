#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    int N = 0;
    char B[37];
    scanf("%s", B);
    scanf("%d", &N);
    long long ans = 0;
    int t = 0;
    for (int i = strlen(B)-1; i >= 0; i--)
    {
        if (B[i] >= 'A' && B[i] <= 'Z')
            ans += (B[i]-'A'+10) * powl(N, strlen(B)-i-1);
        else
            ans += (B[i]-'0') * powl(N, strlen(B)-i-1);
    }
    printf("%lld", ans);
    return 0;
}