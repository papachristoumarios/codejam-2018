#include <cstdio>
#include <vector>
#include <cassert>
#include <cstdlib>
#include <cctype>
#include <algorithm>
using namespace std;
void solve(int);
long readLong() {
	int c; long n;
    n = getchar_unlocked() - '0';
    while (isdigit((c = getchar_unlocked())))
        n = 10*n + c-'0';
    return n;
}


int main() {
  int T;
  scanf("%d", &T);
  for (int t = 1; t <= T; t++) {
    solve(t);
  }

}

void printvec(vector<long> &v){
  for (int i =0; i < (int)v.size(); i++) printf("%ld ", v[i]);
  printf("\n");
}

void solve(int t ) {

  int N; scanf("%d", &N);
  vector<long> artioi;
  vector<long> perritoi;
  long x;
  for (int i = 0; i < N; i++) {
    scanf("%ld", &x);
    if (i % 2 == 0) artioi.push_back(x);
    else perritoi.push_back(x);
  }
  // printvec(artioi);
  // printvec(perritoi);
  sort(artioi.begin(), artioi.end());
  sort(perritoi.begin(), perritoi.end());
  int a = (int) artioi.size();
  int p = (int) perritoi.size();
  // printvec(artioi);
  // printvec(perritoi);
  printf("Case #%d: ", t);

	vector<long> result;
	for (int i = 0; i < max(a, p); i++) {
		if (i < a) result.push_back(artioi[i]);
		if (i < p) result.push_back(perritoi[i]);
	}

	// printvec(result);

	for (int i = 0; i < N - 1; i++) {
		if (result[i] > result[i + 1]) {
			printf("%d\n", i);
			return;
		}
	}

printf("OK\n");

}
