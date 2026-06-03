#include "bits/stdc++.h"

using namespace std;

struct matrix {
  int n, m, mod;
  vector<vector<long long>> arr;
  
  matrix(const int &n, const int &m, const int &mod): n(n), m(m), mod(mod) {
    arr.assign(n + 1, vector<long long>(m + 1, 0LL));
  }

  matrix (const int &n, const int &m) {
    arr.assign(n + 1, vector<long long>(m + 1, 1LL));
  }

  matrix operator* (const matrix &other) {
    matrix ans(n, other.m, mod);

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= other.m; j++) {
        for (int k = 1; k <= m; k++) {
          ans.arr[i][j] = ( ans.arr[i][j] + (arr[i][k] % mod * other.arr[k][j] % mod) % mod ) % mod;
        }
      }
    }

    return ans;
  }

  matrix binpow(matrix a, int b) {
    matrix ans(a.n, a.m);

    while(b) {
      if (b & 1) {
        ans = ans * a;
      }
      a = a * a;
      b /= 2;
    }
    
    return ans;
  }
};
