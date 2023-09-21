#include <stdio.h>
#include <string.h>

char str[100000 + 10];//쇠막대기와 레이저의 배치를 나타내는 괄호 표현 문자열

void InputData(void){
	scanf("%s", str);
}

int main() {
	int ans = 0;
	InputData();//입력
	
	int cur = 0;
	for (int i = 0; i < strlen(str)-1; i++)
	{
	    if ((str[i] == '(') && (str[i+1] == ')')) // Laser case
	    {
	        ans += cur;
	    }
	    else if ((str[i] == '(') && (str[i+1] == '(')) // new stick
	    {
	        cur++;
	    }
	    else if ((str[i] == ')') && (str[i+1] == ')')) // stick done
	    {
	        cur--;
	        ans++;
	    }
	}
	
	
	printf("%d\n", ans);//출력
	return 0;
}