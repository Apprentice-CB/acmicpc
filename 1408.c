#include <stdio.h>

int main(void)
{
    int h,m,s;
 
    scanf("%d:%d:%d", &h, &m, &s);
 
    int cT = s + m * 60 + h * 3600;
    h = m = s = 0;
    scanf("%d:%d:%d", &h, &m, &s);
    int sT = s + m * 60 + h * 3600;
 
    if (cT > sT)
        sT += 24 * 60 * 60;
 
    int sol = sT - cT;
 
    h = sol / 3600,    sol %= 3600;
    m = sol / 60,    sol %= 60;
    s = sol;
 
    printf("%02d:%02d:%02d",h,m,s);
    return 0;
}