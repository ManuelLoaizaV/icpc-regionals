// https://open.kattis.com/contests/nasouth24d2open/problems/officebuilding
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

void RotateClockwise(vector<string>& plan) {
  int S = plan.size();
  int T = plan[0].size();

  vector<string> rotated(T, string(S, '.'));

  for (int i = 0; i < S; i++) {
    for (int j = 0; j < T; j++) {
      rotated[j][S - i - 1] = plan[i][j];
    }
  }

  plan = rotated;
}


int GetMin(const vector<vector<int>>& g, const vector<string>& p) {
  int R = (int)g.size();
  int C = (int)g[0].size();

  int S = (int)p.size();
  int T = (int)p[0].size();

  int mn = INT_MAX;
  for (int i = 0; i + S <= R; i++) {
    for (int j = 0; j + T <= C; j++) {
      int cost = 0;
      for (int a = 0; a < S; a++) {
        for (int b = 0; b < T; b++) {
          if (p[a][b] == '#') {
            cost += g[i + a][j + b];
          }
        }
      }
      mn = min(mn, cost);
    }
  }
  return mn;
}

void Solve(void) {
  int R, C;
  cin >> R >> C;

  int sum = 0;
  vector<vector<int>> grid(R, vector<int>(C));
  for (int i = 0; i < R; i++) {
    for (int j = 0; j < C; j++) {
      cin >> grid[i][j];
      sum += grid[i][j];
    }
  }

  int S, T;
  cin >> S >> T;
  vector<string> plan(S);
  for (int i = 0; i < S; i++) {
    cin >> plan[i];
  }

  int mn = INT_MAX;
  for (int i = 0; i < 4; i++) {
    if (i > 0) {
      RotateClockwise(plan);
    }
    mn = min(mn, GetMin(grid, plan));
  }
  int mx = sum - mn;
  cout << mx << endl;
}

int main(void) {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int t = 1;
  // cin >> t;
  while (t--) Solve();
  return 0;
}