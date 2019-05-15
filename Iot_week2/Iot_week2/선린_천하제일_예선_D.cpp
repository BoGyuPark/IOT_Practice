#include<iostream>
using namespace std;
int n, q, a[1000];
int s1, e1, s2, e2;
long long ans;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	for (int i = 0; i < n; i++) cin >> a[i];
	int state = 0;
	for (int i = 0; i < q; i++) {
		cin >> state;
		long long sum = 0;
		ans = 0;
		if (state == 1) {
			cin >> s1 >> e1;
			for (int t = s1 - 1; t <= e1 - 1; t++) sum += a[t];
			ans = sum;
			cout << ans << '\n';
			swap(a[s1 - 1], a[e1 - 1]);
		}
		else {
			cin >> s1 >> e1 >> s2 >> e2;
			for (int t = s1 - 1; t <= e1 - 1; t++) sum += a[t];
			ans = sum; sum = 0;
			for (int t = s2 - 1; t <= e2 - 1; t++) sum += a[t];
			ans -= sum;
			cout << ans << '\n';
		}
	}
}