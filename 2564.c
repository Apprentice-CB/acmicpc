#include <stdio.h>

int w, h, n;    // Width, height, 상점 개수
int dir[100+10];    // 블록의 위치
int len[100+10];    // 남,북의 경우 왼쪽으로부터, 동,서의 경우 위쪽 경계로부터
int cur_len;
int cur_dir;
void InputData(void){
    scanf("%d %d", &w, &h);
    scanf("%d", &n);
    for (int i=0; i<=n; i++){
        scanf("%d %d", &dir[i], &len[i]);
        if (i == n)
        {
            cur_dir = dir[i];
            cur_len = len[i];      
        }
    }
}

int absi(int a)
{
    if (a > 0) return a;
    return -a;
}

int main(void){
    int ans = -1;

    InputData();// 입력받는 부분
    // printf("cur_x:%d, cur_y:%d\n", cur_x, cur_y);
    // for (int i = 0; i < n; i++)
    // {
    //     printf("store num:%d, x:%d, y:%d\n", i+1, X[i], Y[i]);
    // }

    int sum = 0;
    int total_len = 2 * (w + h);
    int path;
    for (int i = 0; i < n; i++)
    {
        if (cur_dir == 1)   // 현재 위치가 북일 때
        {
            if (dir[i] == 1) // 북 -> 북
            {
                path = absi(cur_len - len[i]); 
            }
            else if (dir[i] == 2)   // 북 -> 남
            {
                path = cur_len + len[i] + h;
            }
            else if (dir[i] == 3)   // 북 -> 서
            {
                path = cur_len + len[i];
            }
            else if (dir[i] == 4)   // 북 -> 동
            {
                path = w - cur_len + len[i];
            }
        }
        else if (cur_dir == 2)  // 현재 남
        {
            if (dir[i] == 1)    // 남 -> 북
            {
                path = cur_len + len[i] + h;
            }
            else if (dir[i] == 2) // 남 -> 남
            {
                path = absi(cur_len - len[i]);
            }
            else if (dir[i] == 3) // 남 -> 서
            {
                path = cur_len + h - len[i];
            }
            else if (dir[i] == 4) // 남 -> 동
            {
                path = w - cur_len + h - len[i];
            }
        }
        else if (cur_dir == 3) // 현재 서
        {
            if (dir[i] == 1) // 북
            {
                path = cur_len + len[i];
            }
            else if (dir[i] == 2) // 서 -> 남
            {
                path = h - cur_len + len[i];
            }
            else if (dir[i] == 3) // 서 서
            {
                path = absi(cur_len - len[i]);
            }
            else if (dir[i] == 4) // 서 동
            {
                path = cur_len + w + len[i];
            }
        }
        else if (cur_dir == 4) // 현재 동
        {
            if (dir[i] == 1) // 동북
            {
                path = cur_len + w - len[i];
            }
            else if (dir[i] == 2) // 동남
            {
                path = h - cur_len + w - len[i];
            }
            else if (dir[i] == 3) // 동 서
            {
                path = w + cur_len + len[i];
            }
            else if (dir[i] == 4) // 동 동
            {
                path = absi(cur_len - len[i]);
            }
        }


        // printf("%d %d %d %d to %d, %d, path %d, other way %d\n",i+1, cur_x, cur_y, cur_dir, dir[i], len[i], path, total_len - path);
        if (total_len - path >= path)
        {
            sum += path;
        }
        else 
        {
            sum += total_len - path;
        }
        // cur_x = X[i];
        // cur_y = Y[i];
        // cur_dir = dir[i];
    }
    ans = sum;
    printf("%d\n", ans);// 출력하는 부분
    return 0;
}