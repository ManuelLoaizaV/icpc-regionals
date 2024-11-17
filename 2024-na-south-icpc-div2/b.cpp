// https://open.kattis.com/contests/nasouth24d2open/problems/trianglesofasquare
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
  set<pair<int, int>> corners;
  corners.insert(make_pair(0, 0));
  corners.insert(make_pair(0, 2024));
  corners.insert(make_pair(2024, 0));
  corners.insert(make_pair(2024, 2024));

  pair<int, int> p;
  cin >> p.first >> p.second;
  pair<int, int> q;
  cin >> q.first >> q.second;

  int cnt = corners.count(p) + corners.count(q);
  int mn = 2 - cnt;
  cout << mn << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--) Solve();
  return 0;
}