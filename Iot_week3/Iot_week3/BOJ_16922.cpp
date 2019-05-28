#include<iostream>
using namespace std;
int n, sel[21], a[4] = { 1,5,10,50 }, cnt[1001], ans;
void dfs(int index, int start) {
	if (index == n) {
		int sum = 0;
		for (int j = 0; j < n; j++) sum += sel[j];
		cnt[sum]++;
		return;
	}
	for (int i = start; i < 4; i++) {
		sel[index] = a[i];
		dfs(index + 1, i);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	dfs(0,0);
	for (int i = 0; i < 1001; i++) if (cnt[i] > 0) ans++;
	cout << ans;
}