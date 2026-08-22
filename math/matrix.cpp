#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll MOD = 1e9 + 7;

struct Matrix {
    int row, col;
    vector<vector<ll>> a;

    Matrix(int row, int col, bool identity = false)
        : row(row), col(col), a(row, vector<ll>(col, 0)) {

        if (identity) {
            for (int i = 0; i < min(row, col); i++)
                a[i][i] = 1;
        }
    }

    vector<ll>& operator[](int i) {
        return a[i];
    }

    const vector<ll>& operator[](int i) const {
        return a[i];
    }

    Matrix operator*(const Matrix& other) const {
        assert(col == other.row);

        Matrix res(row, other.col);

        for (int i = 0; i < row; i++) {
            for (int k = 0; k < col; k++) {
                if (a[i][k] == 0) continue;

                for (int j = 0; j < other.col; j++) {
                    res[i][j] =
                        (res[i][j] + a[i][k] * other[k][j]) % MOD;
                }
            }
        }

        return res;
    }
};

Matrix power(Matrix base, long long exp) {
    assert(base.row == base.col);

    Matrix res(base.row, base.col, true);

    while (exp > 0) {
        if (exp & 1)
            res = res * base;

        base = base * base;
        exp >>= 1;
    }

    return res;
}
