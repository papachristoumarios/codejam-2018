#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <climits>
#include <math.h>
using namespace std;
void solution (long long, string&, int);
void solvesmall(int, string&, int);

int main() {
  int T;
  long long D;
  string s;
  cin >> T;
  for (int t = 1; t <= T; ++t) {
    cin >> D >> s;
    solution(D, s, t);
  }
}



vector<long long> dmg(string &s) {
  int N = (int) s.size();
  vector<long long> result(N, 0);
  long long damage = 0;
  long long status = 1;
  for (unsigned int i = 0; i < N; i++) {
    if (s[i] == 'C') status = 2 * status;
    else damage += status;
    result[i] = damage;
  }
  return result;
}

void rev(string &s) {
  int N = (int) s.size();
  for (unsigned int i = 0; i < N / 2; i++)
    swap(s[i], s[N - i - 1]);

}

int find(string &s, char c) {
  for (int j = 0; j < (int) s.size(); j++) {
    if (s[j] == c) return j;
  }
  return -1;
}

void solution(long long D, string &s, int t) {
  cout << "Case #" << t << ": ";
  int N = (int) s.size();
  int scount = 0, ccount = 0;
  for (int i = 0; i < N; i++) {
    if (s[i] == 'C') ccount++;
    else scount++;
  }

  if (scount > D) {
    cout << "IMPOSSIBLE" << endl;
    return;
  }

  long long damage = 0, status = 1;
  int swaps = 0;
  for (char c : s) {
    if (c == 'S') damage += status;
    else status = status << 1;
  }

  if (damage <= D) {
    cout << "0" << endl;
    return;
  }

  rev(s);

  while (s[0] == 'C') {
    s.erase(s.begin());
    status = status >> 1;
  }

  status = status >> 1;

  while (damage > D) {
    int fc = find(s, 'C');
    if (damage > D + status * fc) {
      damage = damage - status * fc;
      s.erase(s.begin() + fc);
      status = status >> 1;
      swaps += fc;
    }

    else {
      swaps = swaps +  (int) (ceil((damage - D) / ( 1.0 * status )));
      cout << swaps << endl;
      return;
    }

  }




}
