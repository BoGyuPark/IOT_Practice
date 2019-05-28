#include<iostream>
#include<vector>
using namespace std;
int MaxRow, MaxCol, n, cur_row, cur_col;
int sel[2], c[101];
vector<pair<int, int>> v;
void dfs(int index,int start) {
	if (index == 2) {
		for (int j = 0; j < 2; j++) cout << sel[j] << ' ';
		cout << '\n';
		return;
	}
	for (int i = start; i < n; i++) {
		if (c[i] == true) continue;
		c[i] = true;
		sel[index] = i;
		dfs(index + 1,i);
		c[i] = false;
	}
}
int main() {
	cin >> MaxRow >> MaxCol >> n;
	for (int i = 0; i < n; i++) {
		cin >> cur_row >> cur_col;
		v.push_back({ cur_row, cur_col });
	}
	dfs(0,0);

}