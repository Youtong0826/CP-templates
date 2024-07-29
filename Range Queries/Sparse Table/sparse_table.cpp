#include <bits/stdc++.h>
using namespace std;

// dp[i][j] = 由 i 往前跳 2^j-1 的區間值

struct sparse_table {
    int n;
    vector<vector<int>> st;
    sparse_table(vector<int> &v): n(v.size()) {
        int _len = ceil(__lg(n));
        st.assign(n, vector<int>(_len, INT_MAX));
        for (int i = 1; i <= n; i++) {
            st[i][0] = v[i];
        }

        for (int j = 1; j < _len; j++) {
            for (int i = 1; i + (1 << (j-1)) <= n; i++) {
                st[i][j] = min(st[i][j-1], st[i + (1 << (j-1))][j-1]);
            }
        }
    }

    int query(int l, int r) {
        int m = floor(__lg(r - l + 1));
        return min(st[l][m], st[r - (1 << m) + 1][m]);
    }
};