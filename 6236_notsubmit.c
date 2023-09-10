#include <stdio.h>

#define MAX_N (100000)

int N, M;
int need[MAX_N];

void Input_Data(void) {
	int i;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N;i++) {
		scanf("%d", &need[i]);
	}
}

int isPossible(int K)
{
    int money = K;
    int cnt = 1;
    for (int i = 0; i < N; i++)
    {
        if (money - need[i] >= 0)
        {
            money = money - need[i];
        }
        else
        {
            money = K;
            cnt++;
            // printf("Inchul: %d\n", i);
            if (money - need[i] < 0) return 0;
            money = money - need[i];
        }
        if (cnt > M) return 0;
    }
    // printf("K = %d, possible: %d\n", K, cnt<=M);
    return 1;
}

int main(void) {
	int sol = -1;

	// 입력 받는 부분
	Input_Data();

	// 여기서부터 작성
    int s = 1;
    int e = 1 << 29;
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