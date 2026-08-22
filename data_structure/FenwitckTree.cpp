#include <bits/stdc++.h>

using namespace std;

struct Fenwick {
    int n;
    vector<long long> bit;

    Fenwick(int n) : n(n), bit(n + 1, 0) {}

    void add(int idx, long long val) {
        for (; idx <= n; idx += idx & -idx)
            bit[idx] += val;
    }

    long long sum(int idx) {
        long long res = 0;

        for (; idx > 0; idx -= idx & -idx)
            res += bit[idx];

        return res;
    }

    long long query(int l, int r) {
        return sum(r) - sum(l - 1);
    }
};
