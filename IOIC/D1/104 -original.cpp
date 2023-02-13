#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.tie(nullptr)->sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n);
  bool flag = false;
  for (int &ai : a) {
    cin >> ai;
    if (-7122 <= ai < 0) {
      ai = -7122;
    }
    flag |= ai == -7122;
  }
  if (flag) {
    for (int &ai : a)
      ai *= -1;
    // am i wrong? ...%>  <%
    sort(a.begin(), a.end());
  }
  for (int ai : a)
    cout << ai << '\n';
  return 0;
}