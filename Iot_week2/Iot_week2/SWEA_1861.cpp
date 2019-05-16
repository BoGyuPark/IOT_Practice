#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;
int T, tc, n, a[1001][1001], c[1001][1001];
//          ©Л,аб,╩С,го
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
queue<pair<int, int>> q;
vector <pair<int, pair <int, int>>> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
				v.push_back({ a[i][j],{i,j} });
			}
		}
		sort(v.begin(), v.end());

		int StartNum = 0, MaxCnt = 0;
		for (int i = 0; i < v.size(); i++) {
			int cnt = 1;
			int row = v[i].second.first, col = v[i].second.second;
			q.push({ row,col });
			c[row][col] = true;
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int z = 0; z < 4; z++) {
					int nx = x + dx[z], ny = y + dy[z];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (c[nx][ny]) continue;
					if (a[nx][ny] == a[x][y] + 1) {
						q.push({ nx,ny });
						c[nx][ny] = true;
						cnt++;
					}
				}
			}
			if (MaxCnt < cnt) {
				MaxCnt = cnt;
				StartNum = a[row][col];
			}
			else if (MaxCnt == cnt) {
				if (StartNum > a[row][col]) StartNum = a[row][col];
			}
		}
		cout << '#' << tc << ' ' << StartNum << ' ' << MaxCnt << '\n';
		memset(a, 0, sizeof(a));
		memset(c, 0, sizeof(c));
		v.clear();
	}
}