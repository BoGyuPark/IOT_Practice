#include<iostream>
#include<cstring>
using namespace std;
int T, tc, n, m;
char a[51][51];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n >> m;
		for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
		
		//0행~x행까지
		//x + 1행 ~y행까지
		//y + 1행 ~n - 1행까지
		int cnt = 0, ans = 2147483647;
		for (int x = 0; x < n - 2; x++) {
			for (int y = x + 1; y < n - 1; y++) {
				cnt = 0;
				//화이트
				for (int i = 0; i <= x; i++) {
					for (int j = 0; j < m; j++) {
						if (a[i][j] != 'W') cnt++;
					}
				}
				//블루
				for (int i = x + 1; i <= y; i++) {
					for (int j = 0; j < m; j++) {
						if (a[i][j] != 'B') cnt++;
					}
				}
				//레드
				for (int i = y + 1; i <= n - 1; i++) {
					for (int j = 0; j < m; j++) {
						if (a[i][j] != 'R') cnt++;
					}
				}
				if (ans > cnt) ans = cnt;
			}
		}
		cout << '#' << tc << ' ' << ans << '\n';
	}
}