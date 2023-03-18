#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
    char title[50];
    float fGrade = 0;
    char strGrade[2];
    float overall_grade = 0;;
    float cnt = 0;
    for (int i = 0; i < 20; i++)
    {
        scanf("%s %f %s", title, &fGrade, strGrade);
        if (!strcmp(strGrade, "A+"))
        {
            overall_grade += 4.5 * fGrade;
            cnt += fGrade;
        }
        else if (!strcmp(strGrade, "A0"))
        {
            overall_grade += 4.0 * fGrade;
            cnt += fGrade;
        }
        else if (!strcmp(strGrade, "B+"))
        {
            overall_grade += 3.5 * fGrade;
            cnt += fGrade;
        }
        else if (!strcmp(strGrade, "B0"))
        {
            overall_grade += 3.0 * fGrade;
            cnt += fGrade;
        }
        else if (!strcmp(strGrade, "C+"))
        {
            overall_grade += 2.5 * fGrade;
            cnt += fGrade;
        }
        else if (!strcmp(strGrade, "C0"))
        {
            overall_grade += 2.0 * fGrade;
            cnt += fGrade;
        }
        else if (!strcmp(strGrade, "D+"))
        {
            overall_grade += 1.5 * fGrade;
            cnt += fGrade;
        }
        else if (!strcmp(strGrade, "D0"))
        {
            overall_grade += 1.0 * fGrade;
            cnt += fGrade;
        }
        else if (!strcmp(strGrade, "F"))
        {
            cnt += fGrade;
        }
        else
        {
            continue;
        }
    }
    overall_grade = overall_grade / cnt;
    printf("%.6f", overall_grade);
    return 0;
}