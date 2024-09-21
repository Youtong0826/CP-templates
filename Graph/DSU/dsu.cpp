#include <bits/stdc++.h>
using namespace std;

struct dsu {
    int _n;
    vector<int> boss;
    dsu(int n): _n(n) {
        boss.resize(n);
        for (int i = 1; i <= n; i++)
            boss[i] = i;
    }

    int find(int x) {
        return x == boss[x]? x: find(boss[x]);
    }

    void merge(int a, int b) {
        a = find(a), b = find(b);
        boss[b] = a;
    }
};