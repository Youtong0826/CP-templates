#include <bits/stdc++.h>
#define lowbit(x) x&-x
using namespace std;

const int maxn = 2e5;
int n, bit[maxn], bit2[maxn];

void update(int p, int v){
    for (int i = p; i <= n; i += lowbit(i))
        bit[i] += v, bit2[i] += p*v;
}

void update(int l, int r, int v){
    update(l, v), update(r+1, -v);
}

int query(int p){
    int sum = 0;
    for (int i = p; i > 0; i -= lowbit(i))
        sum += bit[i]*(p+1) - bit2[i];

    return sum;
}