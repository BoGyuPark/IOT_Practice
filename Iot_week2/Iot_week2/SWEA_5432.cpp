#include<iostream>
#include<cstring>
#include<vector>
#include<stack>
using namespace std;
int T, tc;
string s;
vector<int> lazer;
stack<int> st;
vector<pair<int,int>> start;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> T;
	for (tc = 1; tc <= T; tc++) {
		cin >> s;
		for (int i = 0; i < s.size()-1; i++) {
			if (s[i] == '(' && s[i + 1] == ')') {
				lazer.push_back(i);
				s[i] = '.', s[i + 1] = '.';
			}
		}
		//cout << s << '\n';
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') st.push(i);
			else if (s[i] == ')') {
				//막대기 생성
				start.push_back({ st.top(),i }); 
				//cout << st.top() << ' ' << i << '\n';
				st.pop();
			}
		}
		int ans = 0;
		for (int i = 0; i < start.size(); i++) {
			int cnt = 0;
			for (int j = 0; j < lazer.size(); j++) {
				if (lazer[j] > start[i].first && lazer[j] < start[i].second) cnt++;
			}
			ans += cnt + 1;
		}
		cout << '#' << tc << ' ' << ans << '\n';
		lazer.clear();
		st = stack<int>();
		start.clear();
	}
}