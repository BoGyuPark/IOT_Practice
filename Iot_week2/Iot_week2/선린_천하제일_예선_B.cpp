#include<iostream>
using namespace std;
int n, a[100001], ans, cnt;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	int t;
	for (int i = 0; i < 2*n; i++) {
		cin >> t;
		if (a[t - 1] == 0) {
			a[t - 1]++;
			cnt++;
		}
		else cnt--;
		if (ans < cnt) ans = cnt;
	}
	cout << ans;
}