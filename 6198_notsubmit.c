#include <stdio.h>

int N;//건물 수
int H[80010];//건물 높이
int sp;
int stk[80010];

void push(int i) {stk[sp++] = i;}
int top() {return stk[sp-1]; }
void pop() { sp--; }
int size() {return sp;}
int empty() {return sp==0;}

void Input_Data(void){
	int i;
	scanf("%d", &N);
	for(i = 0 ; i < N ; i++){
		scanf("%d", &H[i]);
	}
}

int main(void){
	long long ans = 0;
	Input_Data();		//	입력 함수
	
	//	코드를 작성하세요
	for (int i = 0; i < N; i++)
	{
		while (!empty() && H[i] >= top()) // 
		{
			pop();
		}
		ans += (long long)size();
		push(H[i]);
		
	}
	
	
	
	printf("%lld\n", ans);		//	정답 출력
	return 0;
}
