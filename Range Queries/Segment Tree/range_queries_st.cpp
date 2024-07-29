#include <bits/stdc++.h>
using namespace std;

struct node {
    int l, r, val;
};



struct seg_tree {
    int n;
    vector<int> v;    
    vector<node> seg;
    
    seg_tree(int l, int r, vector<int> &v) : n(v.size()), v(v){
        seg.resize(n+1);
        build(l, r, 1); // must be 1-based
    }

    void build(int l, int r, int idx) {
        seg[idx].l = l, seg[idx].r = r;
        if (l == r)
            seg[idx].val = v[l];

        else {
            int mid = (l+r) >> 1;
            build(l, mid, (1 << idx));
            build(mid+1, r, (1 << idx)+1);
            seg[idx].val = min(seg[(1 << idx)].val, seg[(1 << idx)+1].val);
        }
    }

    void update(int x, int v, int idx) {
        if (seg[idx].l == x && seg[idx].r == x) {
            seg[idx].val = v;
            return;
        }

        int mid = (seg[idx].l + seg[idx].r) >> 1;
        if (x <= mid) {
            update(x, v, (1 << idx));
        }
        else {
            update(x, v, (1 << idx)+1);
        }
        seg[idx].val = min(seg[(1 << idx)].val, seg[(1 << idx)+1].val);
    }

    int query(int l, int r, int idx) {
        if (seg[idx].l == l && seg[idx].r == r)
            return seg[idx].val;

        int mid = (seg[idx].l + seg[idx].r) >> 1;
        if (r <= mid) {
            return query(l, r, (1 << idx)+1);
        }
        else if (l > mid) {
            return query(l, r, (1 << idx));
        }
        else {
            return min(query(l, mid, (1 << idx)+1), query(mid+1, r, (1 << idx)));
        }
    }
};


