#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int N;

void InputData(void){
	scanf("%d", &N);
}

int max_num(int N)
{
    int temp = N;
    int result = 0;
    int arr[4];
    for (int i = 0; i < 4; i++)
    {
        arr[i] = temp % 10;
        temp = temp / 10;
    }
    int swap_temp = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = i+1; j < 4; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        result += arr[i] * (int)pow(10, i);
    }
    return result;
}

int min_num(int N)
{
    int temp = N;
    int result = 0;
    int arr[4];
    for (int i = 0; i < 4; i++)
    {
        arr[i] = temp % 10;
        temp = temp / 10;
    }
    int swap_temp = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = i+1; j < 4; j++)
        {
            if (arr[i] < arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    for (int i = 0; i < 4; i++)
    {
        result += arr[i] * (int)pow(10, i);
    }
    return result;
}

int main(void){
	int ans = 0;
    int T = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++)
    {
        InputData();// 입력받는 부분

        int maxn = 0;
        int minn = 0;
        while (1)
        {
            if (N == 6174)
            {
                break;
            }
            
            maxn = max_num(N);
            minn = min_num(N);
            N = maxn - minn;
            ans++;
        }

        printf("%d\n", ans);// 출력하는 부분
        ans = 0;
    }
    return 0;
}