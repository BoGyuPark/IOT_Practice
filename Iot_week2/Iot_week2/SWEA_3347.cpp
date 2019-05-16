#include<iostream>
#include<cstring>
using namespace std;
int T, tc, n, m, a[1001], b[1001], c[1001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) cin >> a[i];
		for (int i = 0; i < m; i++) cin >> b[i];

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (b[i] >= a[j]) {
					c[j]++;
					break;
				}
			}
		}
		int ans = 0, value = 0;
		for (int j = 0; j < n; j++) {
			if (value < c[j]) {
				value = c[j];
				ans = j + 1;
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
		memset(c, 0, sizeof(c));
	}
}