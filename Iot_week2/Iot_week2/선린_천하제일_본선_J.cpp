#include<iostream>
using namespace std;
int n, a[30001], cnt, ans;
int main() {
	cin >> n;
	int max = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (max < a[i]) {
			cnt = 0;
			max = a[i];
		}
		else {
			cnt++;
			if (cnt > ans) ans = cnt;
		}
	}
	/*for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		cnt = 0;
		for (int j = i + 1; j < n; j++) {
			if (a[i] > a[j]) cnt++;
			else break;
		}
		if (cnt > ans) ans = cnt;
	}*/
	cout << ans;
}