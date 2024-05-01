#include <bits/stdc++.h>
#define lowbit(x) x&-x
using namespace std;

const int maxn = 2e5;
int n, bit[maxn];

void update(int i, int v){
    for (; i <= n; i += lowbit(i))
        bit[i] += v;
}

void update(int l, int r, int v){
    update(l, v);
    update(r+1, -v);
}

int query(int i){
    int sum = 0;
    for (; i > 0; i -= lowbit(i))
        sum += bit[i];

    return sum;
}