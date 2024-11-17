// https://open.kattis.com/contests/nasouth24d2open/problems/duelofcards
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
#define debug(x) cerr << "[" << #x << "]: " << x << endl
#else
#define debug(x) 69
#endif

using namespace std;

typedef long long Long;
typedef long double Double;
typedef pair<Long, Long> Pair;

const int N = 1e6;
const Long MOD = 998244353LL;
const Long INF = 1e18;
const Double PI = acos(-1);
const Double EPS = 1e-9;

const char A = 'a';
const char ZERO = '0';
const char ENDL = '\n';

const string YES = "YES";
const string NO = "NO";

int Count(vector<int>& v, vector<int>& w) {
  assert(v.size() == w.size());
  int n = (int)v.size();
  int j = n - 1;
  int cnt = 0;
  for (int i = n - 1; i >= 0; i--) {
    while (j >= 0 && w[j] > v[i]) {
      j--;
    }
    if (j >= 0) {
      cnt++;
      j--;
    }
  }
  return cnt;
}

void Solve(void) {
  int n;
  cin >> n;
  vector<int> v(n);
  vector<bool> used(2 * n + 1, false);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
    used[v[i]] = true;
  }
  sort(v.begin(), v.end());
  vector<int> w;
  for (int i = 1; i <= 2 * n; i++) {
    if (!used[i]) {
      w.push_back(i);
    }
  }
  int mx = Count(v, w);
  int mn = n - Count(w, v);
  cout << mn << ' ' << mx << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--) Solve();
  return 0;
}