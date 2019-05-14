#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
int n, a[101][101], Max = -1;
int c[101][101];
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
int ans = 1;
queue<pair<int, int>> q;
void CheckWater(int pivot) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] <= pivot) {
				c[i][j] = true;
			}
		}
	}
}
void CountArea() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c[i][j] == true) continue;
			cnt++;
			q.push({ i,j });
			c[i][j] = true;
			while (!q.empty()) {
				int x = q.front().first, y = q.front().second;
				q.pop();
				for (int z = 0; z < 4; z++) {
					int nx = x + dx[z], ny = y + dy[z];
					if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
					if (c[nx][ny] == true) continue;
					q.push({ nx,ny });
					c[nx][ny] = true;
				}
			}
		}
	}
	//cout << cnt << '\n';
	if (ans < cnt) ans = cnt;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			if (a[i][j] > Max) Max = a[i][j];
		}
	}
	if (Max > 100) Max = 100;
	for (int i = 1; i <= Max; i++) {
		memset(c, 0, sizeof(c));
		CheckWater(i);
		CountArea();
	}
	
	cout << ans;
}