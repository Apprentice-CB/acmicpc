#include <stdio.h>
#include <string.h>

int main(void)
{
    int N;
    char order[1000001];
    scanf("%d", &N);
    scanf("%s", order);
    char an;
    char anm1;
    for (int i = N-1; i >= 1; i--)
    {
        an = order[i];
        anm1 = order[i-1];
        switch (an)
        {
            case 'A':
                switch (anm1)
                {
                    case 'A':
                        order[i-1] = 'A';
                        break;
                    case 'G':
                        order[i-1] = 'C';
                        break;
                    case 'C':
                        order[i-1] = 'A';
                        break;
                    case 'T':
                        order[i-1] = 'G';
                        break;
                }
                break;
            case 'G':
                switch (anm1)
                {
                    case 'A':
                        order[i-1] = 'C';
                        break;
                    case 'G':
                        order[i-1] = 'G';
                        break;
                    case 'C':
                        order[i-1] = 'T';
                        break;
                    case 'T':
                        order[i-1] = 'A';
                        break;
                }            
                break;
            case 'C':
                switch (anm1)
                {
                    case 'A':
                        order[i-1] = 'A';
                        break;
                    case 'G':
                        order[i-1] = 'T';
                        break;
                    case 'C':
                        order[i-1] = 'C';
                        break;
                    case 'T':
                        order[i-1] = 'G';
                        break;
                }            
                break;
            case 'T':
                switch (anm1)
                {
                    case 'A':
                        order[i-1] = 'G';
                        break;
                    case 'G':
                        order[i-1] = 'A';
                        break;
                    case 'C':
                        order[i-1] = 'G';
                        break;
                    case 'T':
                        order[i-1] = 'T';
                        break;
                }            
                break;
        }
    }
    printf("%c", order[0]);
}