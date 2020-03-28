#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
 
using namespace std;
 
struct q {
  int x;
  int y;
  int c;
  q* next = nullptr;
};
 
void rec(int xx, int yy, int cc, int a[][100], int f[][100], pair<int, int> pr[][100], int n, int m, int oldx, int oldy) {
  if (xx < 0 || yy < 0 || xx >= n || yy >= m) return;
  if (a[xx][yy] == 1|| f[xx][yy] <= cc) return;
 
  q* temp = new q;
  temp->x = xx;
  temp->y = yy;
  temp->c = cc;
  q* qq = new q;
  qq->next = temp;
 
  pr[xx][yy].first = oldx;
  pr[xx][yy].second = oldy;
  f[xx][yy] = cc;
  rec(temp->x+1, temp->y, temp->c+1, a, f, pr, n, m, xx, yy);
  rec(temp->x-1, temp->y, temp->c+1, a, f, pr, n, m, xx, yy);
  rec(temp->x, temp->y+1, temp->c+1, a, f, pr, n, m, xx, yy);
  rec(temp->x, temp->y-1, temp->c+1, a, f, pr, n, m, xx, yy);
}
 
int main() {
  int n, m, x1, y1, x2, y2, q1, q2;
  cin >> n >> m;
  int f[100][100], a[100][100];
 
  pair<int, int> pr[100][100];
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
      f[i][j] = (1e9);
    }
  }
  cin >> x1 >> y1;
  cin >> x2 >> y2;
 
  rec(x1, y1, 0, a, f, pr, n, m, -1, -1);
 
  if (f[x2][y2] == (1e9)) {
    cout << -1;
    return 0;
  }
 
  vector<pair<int, int>> res;
  int xx = x2, yy = y2;
  while (xx != -1 && yy !=-1) {
    res.push_back({xx,yy});
    int xxx = pr[xx][yy].first;
    int yyy = pr[xx][yy].second;
    xx = xxx;
    yy = yyy;
  }
  reverse(res.begin(), res.end());
 
  for (auto i : res) {
    cout << i.first << " " << i.second << endl;
  }
  cout << f[x2][y2] << endl;
}
