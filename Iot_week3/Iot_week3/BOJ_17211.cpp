#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int n, m, ex, ey, c[51][51], dist[7][7];	//start, end
int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };
char a[51][51];
int sel[6], check[6];
queue<pair<int, int>> q;
vector<pair<int, int >> v;
void findChar(char c, int flag) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == c) {
				v.push_back({ i,j });
				if(flag) return;
			}
		}
	}
}
void bfs(int sx, int sy, int start) {
	memset(c, -1, sizeof(c));
	q.push({ sx,sy });
	c[sx][sy] = 0;
	while (!q.empty()) {
		int x = q.front().first, y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i], ny = y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (c[nx][ny] != -1) continue;
			if (a[nx][ny] != '#') {
				q.push({ nx,ny });
				c[nx][ny] = c[x][y] + 1;
			}
		}
	}
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first, y = v[i].second;
		if (x == sx && y == sy) continue;
		dist[start][i] = c[x][y];
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> m >> n;
	int sx = 0, sy = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'S') v.push_back({ i,j });
		}
	}
	findChar('X', 0);	findChar('E', 1);
	
	int dis = 0;
	int temp[10] = { 0, };
	for (int i = 0; i < v.size(); i++) {
		bfs(v[i].first, v[i].second, i);
	}
	int ObjectCnt = v.size() - 2;
	for (int i = 0; i < ObjectCnt; i++) temp[i] = i + 1;
	
	int ans = 2147483647;
	do {
		dis = 0;
		int s = 0, e = ObjectCnt + 1;
		for (int i = 0; i < ObjectCnt; i++) {
			dis += dist[s][temp[i]];
			s = temp[i];
		}
		dis += dist[s][e];
		if (dis < ans) ans = dis;
	} while (next_permutation(temp, temp + ObjectCnt));
	cout << ans;
}