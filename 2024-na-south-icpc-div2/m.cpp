// https://open.kattis.com/contests/nasouth24d2open/problems/memoriesofpassportstamps
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
  Long n, k;
  cin >> n >> k;
  vector<Long> p(n);
  for (int i = 0; i < n; i++) cin >> p[i];

  Long L = 0LL;
  Long R = *max_element(p.begin(), p.end());
  while (R - L > 1) {
    Long M = (L + R) / 2;
    Long cnt = 0;
    for (int i = 0; i < n; i++) {
      cnt += (p[i] + M - 1) / M;
      if (cnt > k) break;
    }
    if (cnt > k) {
      L = M;
    } else {
      R = M;
    }
  }
  cout << R << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--) Solve();
  return 0;
}