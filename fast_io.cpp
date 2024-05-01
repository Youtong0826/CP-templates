#include <bits/stdc++.h>
using namespace std;

static char buf1[100000],*p1=buf1,*p2=buf1;
char getc(){
    return p1==p2&&(p2=(p1=buf1)+fread(buf1,1,100000,stdin),p1==p2)?EOF:*p1++;
}

char buf2[100000],*pp=buf2;
void putc(const char c){
    if(pp-buf2==100000) fwrite(buf2,1,100000,stdout),pp=buf2;
    *pp++=c;
}

long long readint(){
    long long a = 0;
    char c = '0';
    while (c >= '0' && c <= '9'){
        a = (a << 3) + (a << 1) + c - '0';
        c = getchar();
    }
    return a;
}

void writeint(long long d){
    if (d == 0){
        putchar(48);
        return;
    }
    
    int len = 0;
    char n[20];

    while (d > 0){
        n[len] = d % 10 + 48;
        len++;
        d /= 10;
    }

    for (int i = len - 1; i >= 0; i--)
        putchar(n[i]);
}