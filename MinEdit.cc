#include <iostream>
#include <algorithm>
#include <utility>
#include <string>
#include <vector>

using namespace std;

int  minEdit(string s, string t, int n, int m) {
  int cost;
  int d[n + 1][m + 1] = {{0}};

    for(int i = 0; i <= n; i++) {
        for(int j = 0; j <= m; j++) {
          if(s[i - 1] == t[j - 1]) cost = 0;
          else cost = 1;

          int d1 = d[i][j + 1] + 1;
          int d2 = d[i + 1][j] + 1;
          int d3 = d[i][j] + cost;

          d[i + 1][j + 1] = min(min(d1, d2), d3);

          if(i > 0 && j > 0 && s[i + 1] == t[j] && s[i] == t[j + 1] ) {
            d[i + 1][j + 1] = min(d[i + 1][j + 1],d[i - 1][j - 1] + cost);
          }
        }
    }

    for(int i = 1; i <= n + 1; i++){
        for(int j = 1; j <= m + 1; j++){
            cout << d[i][j] << " ";
        }
    cout << endl;
 }

 return d[n+1][m+1];
}

int main(void) {
    string a, b; cin >> a >> b;

    cout << minEdit(a, b, a.length(), b.length()) << endl;

    return 0;
}
