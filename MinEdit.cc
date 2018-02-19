#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>

using namespace std;

int  minEdit(string s, string t, int n, int m) {
  int d1, d2, d3, cost;
  int i, j;
  int d[n + 1][m + 1];
  for(i = 0;i <= n;i++) {
      for(j = 0;j <= m;j++) {
      if(s[i - 1]==t[j - 1]) cost = 0;
      else cost=1;

      d1 = d[i][j + 1] + 1;
      d2 = d[i + 1][j] + 1;
      d3 = d[i][j] + cost;
      d[i + 1][j + 1] = min(min(d1, d2), d3);

      if(i > 0 && j > 0 && s[i + 1] == t[j] && s[i] == t[j + 1] ) {
        d[i + 1][j + 1] = min(d[i + 1][j + 1],d[i - 1][j - 1] + cost);
      }
   }
 }
 return d[n+1][m+1];
}

int main(void) {
    string a, b; cin >> a >> b;

    cout << minEdit(a, b, a.length(), b.length()) << endl;

    return 0;
}
