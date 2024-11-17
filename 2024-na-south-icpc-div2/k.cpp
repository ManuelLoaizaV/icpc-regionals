// https://open.kattis.com/contests/nasouth24d2open/problems/optimizedcheating
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

const int MAX_N = 1e5;
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
  Long N, M, K;
  cin >> N >> M >> K;
  map<Long, int> memo;
  Long bob = -1;
  for (int i = 0; i < N; i++) {
    Long p;
    cin >> p;
    if (memo.count(p) == 0) {
      memo[p] = 1;
    } else {
      memo[p]++;
    }
    if (i == K - 1) {
      bob = p;
    }
  }

  if (memo[bob] == 1) {
    cout << 0 << endl;
    return;
  }

  vector<pair<char, int>> operations;
  for (int i = 0; i < M; i++) {
    char c;
    cin >> c;
    int x;
    cin >> x;
    operations.push_back(make_pair(c, x));
  }

  map<Long, Long> d;
  map<Long, pair<Long, int>> parents;

  d[bob] = 0;
  parents[bob] = make_pair(-1LL, -1);

  Long target = -1;
  queue<Long> q;
  q.push(bob);
  while (!q.empty()) {
    Long u = q.front();
    q.pop();
    for (int i = 0; i < M; i++) {
      Long v = 0;
      char c = operations[i].first;
      Long x = operations[i].second;
      if (c == '*') {
        v = u * x;
      } else if (c == '/') {
        v = u / x;
      } else if (c == '+') {
        v = u + x;
      } else if (c == '-') {
        v = u - x;
      }
      if (v >= 0 && d.count(v) == 0) {
        d[v] = d[u] + 1LL;
        parents[v] = make_pair(u, i + 1);
        if (memo.count(v) == 0) {
          target = v;
          break;
        }
        q.push(v);
      }
    }
    if (target != -1) {
      break;
    }
  }

  if (target == -1) {
    cout << -1 << endl;
    return;
  }

  int min_operations = d[target];
  cout << min_operations << endl;
  stack<int> s;
  while (min_operations--) {
    s.push(parents[target].second);
    target = parents[target].first;
  }
  while (!s.empty()) {
    cout << s.top() << endl;
    s.pop();
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