#include<iostream>
using namespace std;
int n, m, a[501][501], Nine;
int FindNine(int num) {
	int cnt = 0;
	while (num!=0) {
		int temp = num % 10;
		if (temp == 9) cnt++;
		num /= 10;
	}
	return cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			Nine += FindNine(a[i][j]);
		}
	}
	int MaxCnt = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt = 0;
		for (int j = 0; j < m; j++) {
			cnt += FindNine(a[i][j]);
		}
		if (MaxCnt < cnt) MaxCnt = cnt;
	}

	for (int i = 0; i < m; i++) {
		cnt = 0;
		for (int j = 0; j < n; j++) {
			cnt += FindNine(a[j][i]);
		}
		if (MaxCnt < cnt) MaxCnt = cnt;
	}
	cout << Nine-MaxCnt;
}