#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
#define MAXN 1000
bool grid[MAXN][3];

void solve(int t) {
  int A;
  cin >> A;
  for (int i = 0; i < MAXN; i++)
    for (int j = 0; j < 3; j++)
      grid[i][j] = false;
  int i = 2, j = 2;
  int x, y;
  while (1 < 2) {
    cout << i << " " <<  j << endl;
    cout.flush();
    cin >> x >> y;
    if (x == 0 && y == 0) return;

    grid[x-1][y-1] = true;
    while (grid[i-2][0] && grid[i-2][1] && grid[i-2][2]) i++;
  }

}


int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) solve(t);
}
