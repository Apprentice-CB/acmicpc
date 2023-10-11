#include <stdio.h>

#define MAX_N (100000)

int N, M;
int need[MAX_N+10];
int s, e;

int max(int a, int b)
{
    if (a > b) return a;
    return b;
}

void Input_Data(void) {
    s = 0; e = 0;
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N;i++) {
		scanf("%d", &need[i]);
        s = max(s, need[i]);
        e += need[i];
	}
}

int isPossible(int mid)
{
    int money = mid;
    int cnt = 1;
    for (int i = 0; i < N; i++)
    {
        money = money - need[i];
        if (money <= 0)
        {
            money = mid - need[i];
            cnt++;
        }
    }
    return cnt <= M;
}

int main(void) {
	int sol = -1;

	Input_Data();

	// 여기서부터 작성

    int m;

    while(s <= e)
    {
        m = (s + e) / 2;
        if (isPossible(m)) // 가능하다면 더 작은 값으로
        {
            e = m - 1;
            sol = m;
        }
        else // 불가능하다면 더 큰값으로
        {
            s = m + 1;
        }
    }

	// 출력하는 부분
	printf("%d\n", sol);

	return 0;
}