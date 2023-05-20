#include <stdio.h>

int main(void)
{
    int a = 0;
    int b = 0;
    int c = 0;
    scanf("%d %d %d", &a, &b, &c);
    if (a == b && b == c && a == 60)
    {
        printf("Equilateral");
    }
    else if ((a + b + c == 180) && (a == b || b == c || a == c))
    {
        printf("Isosceles");
    }
    else if ((a ! = b && b != c && c != a) && (a + b + c == 180))
    {
        printf("Scalene");
    }
    else
    {
        printf("Error");
    }
}