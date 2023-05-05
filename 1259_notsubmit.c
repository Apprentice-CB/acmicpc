#include <stdio.h>
#include <string.h>

int main(void)
{
    char num[6];
    int left = 0;
    int right = 0;
    while (1)
    {
        scanf("%s", num);
        if (!strcmp(num, "0"))
        {
            return 0;
        }
        left = 0;
        right = strlen(num)-1;   
        
        while (1)
        {  
            if (left >= right)
            {
                printf("yes\n");
                break;
            }
            if (num[left] != num[right])
            {
                printf("no\n");
                break;
            }
            left++;
            right--;
        }
    }
}