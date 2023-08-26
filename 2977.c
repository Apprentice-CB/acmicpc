#include <stdio.h>
#define MAXN (100)
int N, M;//재료종류수, 가진돈
int X[MAXN + 10];//1인분당 필요한 양
int Y[MAXN + 10];//주방에 있는 양
int Sm[MAXN + 10];//작은 포장 재료 양
int Pm[MAXN + 10];//작은 포장 가격
int Sv[MAXN + 10];//큰포장 재료 양
int Pv[MAXN + 10];//큰포장 가격

int max(int a, int b) {
    if (a > b) return a;
    return b;
}

int min(int a, int b) {
    if (a > b) return b;
    return a;
}


int CalCost(int idx, int need) {
	int sm = Sm[idx], pm = Pm[idx], sv = Sv[idx], pv = Pv[idx];
	int e = (need + sv - 1) / sv;//큰 포장으로만 구매할 때 개수
	int minv = pv * e;//큰 포장으로 구매할때 가격
	for (int i = 0; i < e; i++) {//큰포장 구매 개수
		int j = (need - sv * i + sm - 1) / sm;
		int cost = pv * i + pm * j;
		if (minv > cost) minv = cost;
	}
	return minv;
}
int isPossible(int m) {
	int sum = M;
	for (int i = 0; i < N; i++) {
        int money = 1 << 30;
		int need = X[i] * m - Y[i];//구매 개수
		if (need <= 0) continue;//0이하면 구매 불필요

        int p_range = need/Sm[i];
        if (need % Sm[i] > 0) p_range++;

        for (int p = 0; p <= p_range; p++)
        {
            int left_need = need - p *Sm[i];
            int q = (left_need <= 0)? 0 : left_need/Sv[i];
            if (left_need > 0 && left_need%Sv[i] > 0) q++;

            money = min(money, p*Pm[i]+q*Pv[i]);
        }

		sum -= money;
		if (sum < 0) return 0;//m인분 불가능
	}
	return 1;//가능
}
int Solve(void) {
	int s, e, sol;
	//1.e 정하기
    for (int i = 0; i <= M/Pm[0]; i++)
    {
        int left_money = M-Pm[0]*i;
        int j = left_money/Pv[0];

        int ingredient = i*Sm[0] + j*Sv[0];
        e = max(e, (ingredient+Y[0])/X[0]);
    }
	//2.s~e 답 찾기 (upper bound)
    sol = -1;
	while (s <= e) {
		int m = (s + e) / 2;
		if (isPossible(m)) {
			sol = m;
			s = m + 1;
		}
		else {
			e = m - 1;
		}
	}
	return sol;
}

void InputData(void) {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d %d %d %d", &X[i], &Y[i], &Sm[i], &Pm[i], &Sv[i], &Pv[i]);
	}
}
int main(void) {
	int ans = -1;
	InputData();

	//여기서부터 작성
	ans = Solve();

	printf("%d\n", ans);
	return 0;
}