// https://open.kattis.com/contests/nasouth24d2open/problems/welcomesign
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
  Long R, C;
  cin >> R >> C;
  int n_unbalanced = 0;
  while (R--) {
    string row(C, '.');
    string s;
    cin >> s;
    int n = (int)s.size();
    int rem = C - n;
    int r = rem / 2;
    int l = rem - r;
    if (l != r) {
      if (n_unbalanced % 2 == 0) {
        if (l > r) {
          swap(l, r);
        }
      } else {
        if (r > l) {
          swap(l, r);
        }
      }
      n_unbalanced++;
    }
    for (int i = 0; i < n; i++) {
      row[l + i] = s[i];
    }
    cout << row << endl;
  }
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--) Solve();
  return 0;
}