#include<iostream>
#include<cstring>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	int l = 0, r = 0, pivot = 0;
	cin >> s;
	pivot = s.size() - 1;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == '(') pivot = i;
		else if (s[i] == '@' && i < pivot) l++;
		else if (s[i] == '@') r++;
	}
	cout << l << ' ' << r;
}