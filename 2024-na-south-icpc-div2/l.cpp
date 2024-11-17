// https://open.kattis.com/contests/nasouth24d2open/problems/pianissimo
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

void Solve(void) {
  map<string, int> h;
  h["ppp"] = 0;
  h["pp"] = 1;
  h["p"] = 2;
  h["mp"] = 3;
  h["mf"] = 4;
  h["f"] = 5;
  h["ff"] = 6;
  h["fff"] = 7;

  int n, m;
  cin >> n >> m;

  vector<int> p(n);
  for (int i = 0; i < n; i++) cin >> p[i];
  
  int prev = 0;
  vector<int> w(n);
  for (int j = 0; j <= m; j++) {
    int i = n;
    string d;
    if (j < m) {
      cin >> i;
      i--;
      cin >> d;
    }
    for (int k = prev; k < i; k++) {
      w[k] = w[prev];
    }
    if (j < m) {
      w[i] = h[d];
      prev = i;
    }
  }

  vector<vector<int>> weights(8);
  for (int i = 0; i < n; i++) {
    weights[w[i]].push_back(p[i]);
  }
  for (int i = 0; i < 8; i++) {
    sort(weights[i].begin(), weights[i].end());
  }

  Long cnt = 0LL;
  for (int i = n - 1; i >= 0; i--) {
    for (int j = w[i] + 1; j < 8; j++) {
      Long x = upper_bound(weights[j].begin(), weights[j].end(), p[i]) - weights[j].begin();
      cnt += x;
    }
  }

  cout << cnt << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--) Solve();
  return 0;
}