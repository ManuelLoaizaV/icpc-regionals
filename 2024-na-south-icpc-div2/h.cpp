// https://open.kattis.com/contests/nasouth24d2open/problems/herbmixing
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
  Long G, R;
  cin >> G >> R;

  Long mn = min(G, R);
  Long opt = 10LL * mn;
  G -= mn;

  Long cnt = G / 3LL;
  opt += 10LL * cnt;
  G -= 3 * cnt;

  cnt = G / 2LL;
  opt += 3LL * cnt;
  G -= 2 * cnt;

  opt += G;
  G = 0;

  cout << opt << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--) Solve();
  return 0;
}