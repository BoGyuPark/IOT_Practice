#include<iostream>
using namespace std;
int n, a[20001];
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) if (a[i] != i) ans++;
	cout << ans;
}