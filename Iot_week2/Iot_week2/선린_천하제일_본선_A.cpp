#include<iostream>
using namespace std;
int n, sel[9], ans;
void dfs(int index) {
	if (index == n) {
		int value = 0, num = 0;
		for (int j = 0; j < n; j++) {
			value = 10 * value + sel[j];
		}
		int temp = value;
		while (temp != 0) {
			temp /= 10;
			num++;
		}

		if (value != 0 && value % 3 == 0 && num==n) {
			//cout << value << '\n';
			ans++;
		}
		return;
	}
	for (int i = 0; i < 3; i++) {
		sel[index] = i;
		dfs(index + 1);
	}

}
int main() {
	cin >> n;
	dfs(0);
	cout << ans;
}