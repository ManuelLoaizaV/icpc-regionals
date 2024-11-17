// https://open.kattis.com/contests/nasouth24d2open/problems/whichoneislarger
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

vector<Double> Split(string s) {
  int p = 0;
  while (s[p] != '.') p++;
  string left = s.substr(0, p);
  string right = s.substr(p + 1);
  vector<Double> halves = {stold(left), stold(right)};
  return halves;
}

bool Less(string s, string t) {
  vector<Double> a = Split(s);
  vector<Double> b = Split(t);
  return a < b;
}

void Solve(void) {
  pair<Double, string> s;
  cin >> s.second;
  s.first = stold(s.second);

  pair<Double, string> t;
  cin >> t.second;
  t.first = stold(t.second);

  if (t.first < s.first) {
    swap(s, t);
  }

  // s.first < t.first
  if (Less(s.second, t.second)) {
    cout << t.second << endl;
  } else {
    cout << -1 << endl;
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