#include <stdio.h>
#include <string.h>

char str[100000+10];
int change[100000+10];
void InputData(void){
    scanf("%s", str);
}

int main(void){
    int ans = 0;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    int open = 0;
    int close = 0;
    int len = strlen(str);
    int max_len = len;
    int cnt = 0;
    for (int i = 0; i < len; i++)
    {
        if (str[i] == '(') 
        {
            open++;
            cnt++;
        }
        else 
        {
            close++;
            cnt--;
        }
        change[i] = cnt;
        if (cnt < 0)  // close가 더 많을 때
        {
            max_len = i+1;
            break;
        }
    }

    if (close > open)  // 닫는게 더 많을 때
    {
        printf("%d", close);
    }
    else if (open > close)    // 여는게 더 많을 때
    {
        cnt = 0; open = 0; close = 0;
        for (int i = len-1; i >= 0 ; i--)
        {
            if (str[i] == '(')
            {
                close++;
                cnt--;   
            }
            else
            {
                open++;
                cnt++;
            }
            if (cnt < 0)
            {
                break;
            }
        }
        printf("%d", close);
    }
    else
    {
        printf("0");
    }
    return 0;
}