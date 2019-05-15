#include<iostream>
using namespace std;
int money, n, map[101], index, d;
char dir;
double b, r, g;
// 0 : ÆÄ, 1: »¡, 2: ÃÊ
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> money >> n;
	for (int i = 0; i < n; i++) {
		cin >> index >> dir;
		if (dir == 'R') d = 1;
		else d = -1;
		index += d;
		int cnt = 0;
		while (index>=1 && index<=100) {
			map[index]++;
			map[index] %= 3;
			index += d;
		}
	}
	
	for (int i = 1; i <= 100; i++) {
		if (map[i] == 0) b++;
		else if (map[i] == 1) r++;
		else g++;
	}

	cout << fixed;
	cout.precision(2);
	cout << b/100*money << ' ' << r / 100 * money << ' ' << g / 100 * money;
}