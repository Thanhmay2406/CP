#include <bits/stdc++.h>

using namespace std;

#define int long long
#define fi first
#define se second
#define L(i, a, b) for (int i = (a), _b = (b); i <= _b; i++)
#define R(i, a, b) for (int i = (a), _b = (b); i >= _b; i--)
#define rep(i, n) for (int i = 0, _n = (n); i < _n; i++)
#define el '\n'
#define all(x) x.begin(), x.end()

template<class T> bool ckmax(T &a, const T &b) { return a < b ? a = b, true : false; }
template<class T> bool ckmin(T &a, const T &b) { return a > b ? a = b, true : false; }
template<class T> using Heap = priority_queue<T, vector<T>, greater<T>>;

void process();

signed main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int tt = 1;
  // cin >> tt;
  rep(i, tt) process();
  return 0;
}

void process() {
}
