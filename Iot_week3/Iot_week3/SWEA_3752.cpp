#include<iostream>
#include<cstring>
using namespace std;
int T, tc, n, a[101], cnt[10001];
int main() {
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		int ans = 0, max = 0;
		cin >> n;
		cnt[0]++;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			int newValue = a[i];
			max += newValue;
			//이전에 값에 새로운값을 더한다.
			for (int j = max; j >= 0; j--) {
				if (cnt[j] > 0) {
					int preValue = j;
					cnt[preValue + newValue]++;
				}
			}
			cnt[newValue]++;
		}
		for (int i = 0; i < 10001; i++) if (cnt[i] > 0) ans++;
		
		cout << '#' << tc << ' ' << ans << '\n';
		memset(cnt, 0, sizeof(cnt));
		memset(a, 0, sizeof(a));
	}
}