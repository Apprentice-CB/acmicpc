#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[10];
    int age = 0;
    int mom = 0;
    while(1)
    {
        scanf("%s %d %d", name, &age, &mom);
        if (!strcmp(name, "#") && age == 0 && mom == 0)
        {
            return 0;
        }
        if (age > 17 || mom >= 80)
        {
            printf("%s Senior\n", name);
        }
        else
        {
            printf("%s Junior\n", name);
        }
    }
}