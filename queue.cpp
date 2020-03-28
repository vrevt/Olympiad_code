#include <bits/stdc++.h>
 
using namespace std;
 
 
pair <int, int> k[100000];
int q1, q2, n, m, x, y, xx, yy, flag, c[1000];
int res[1000][1000], a[1000][1000];
 
void add(int x, int y, int cc) {
    if (x < 1 || x > n || y < 1 || y > m) return;
    cout << x << " " << y << " " << cc << endl;
    if (res[x][y] <= cc) return;
    res[x][y] = cc;
    k[q1].first = x;
    k[q1].second = y;
    c[q1] = cc;
    q1++;
}
 
int main() {
 
    flag = 0;
    cin >> n >> m;
    for (int i = 0; i <= n; i++) for (int j = 0; j <= m; j++) res[i][j] = 2121313;
 
    int a[n + 1][m + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    cin >> x >> y;
    cin >> xx >> yy;
 
    q1 = q2 = 0;
    add(x, y, a[x][y]);
    while (q1 != q2) {
        if (flag) break;
 
        x = k[q2].first;
        y = k[q2].second;
 
        add(x + 1, y, c[q2] + a[x+1][y]);
        add(x - 1, y, c[q2] + a[x-1][y]);
        add(x, y - 1, c[q2] + a[x][y-1]);
        add(x, y + 1, c[q2] + a[x][y+1]);
        q2++;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n ; j++) cout << res[i][j] <<" ";
        cout << endl;
    }
}
 
