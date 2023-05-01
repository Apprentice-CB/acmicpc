#include <stdio.h>
#include <string.h>

int recursion(const char *s, int l, int r, int* cnt){
    if(l >= r) 
    {
        return 1;
    }
    else if(s[l] != s[r]) 
    {
        return 0;
    }
    else 
    {
        cnt[0]++;
        return recursion(s, l+1, r-1, cnt);
    }
}

int isPalindrome(const char *s, int* cnt){
    int a = *cnt;
    cnt[0]++;
    return recursion(s, 0, strlen(s)-1, cnt);
}

int main(){
    int n = 0;
    scanf("%d", &n);
    int cnt = 0;
    int result = 0;
    char s[1000];
    for (int i = 0; i < n; i++)
    {
        cnt = 0;
        scanf("%s", s);
        result = isPalindrome(s, &cnt);
        printf("%d %d\n", result, cnt);
    }

}