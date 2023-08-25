#include <stdio.h>

int main(void)
{
    int h;
    int m;
    int s;
    scanf("%d:%d:%d", &h, &m, &s);
    int he;
    int me;
    int se;
    scanf("%d:%d:%d", &he, &me, &se);
    int ct_s;
    int et_s;
    ct_s = (ct[0]-'0')*10*3600 + (ct[1]-'0')*3600 + (ct[3]-'0')*10*60 + (ct[4]-'0')*60 + (ct[6]-'0')*10 + (ct[7]-'0');
    et_s = (et[0]-'0')*10*3600 + (et[1]-'0')*3600 + (et[3]-'0')*10*60 + (et[4]-'0')*60 + (et[6]-'0')*10 + (et[7]-'0');
    s = et_s - ct_s;
    h = s / 3600;
    s = s % 3600;
    m = s / 60;
    s = s % 60;
    printf("%02d:%02d:%02d", h, m, s);
}