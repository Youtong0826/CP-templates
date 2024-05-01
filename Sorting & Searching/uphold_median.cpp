#include <bits/stdc++.h>
using namespace std;
multiset<int> r, l;

void ins(int val){
    if (val < *l.rbegin()){
        l.insert(val);
        if (l.size() > r.size() + 1){
            r.insert(*l.rbegin());
            l.erase(l.find(*l.rbegin()));
        }
    }
    else{
        r.insert(val);
        if (r.size() > l.size() + 1){
            l.insert(*r.begin());
            r.erase(r.find(*r.begin()));
        }
    }
}

void era(int val){
    if (r.find(val) != r.end())
        r.erase(r.find(val));

    else
        l.erase(l.find(val));

    if (r.empty()){
        r.insert(*l.rbegin());
        l.erase(l.find(*l.rbegin()));
    }

    if (l.empty()){
        l.insert(*r.begin());
        r.erase(r.find(*r.begin()));
    }
}