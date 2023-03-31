#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int T = 0;
    scanf("%d", &T);
    int quarter = 0;
    int dime = 0;
    int nickel = 0;
    int penny = 0;
    int pay = 0;
    for (int i = 0; i < T; i++)
    {
        scanf("%d", &pay);
        quarter = pay / 25;
        pay = pay % 25;

        dime = pay / 10;
        pay = pay % 10;

        nickel = pay / 5;
        pay = pay % 5;

        penny = pay;
        printf("%d %d %d %d\n", quarter, dime, nickel, penny);
    }
}