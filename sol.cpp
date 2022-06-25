#include <bits/stdc++.h>

using namespace std;

//int x[8] = {1, 0, -1, 0, 1, 1, -1, -1};
//int y[8] = {0, 1, 0, -1, 1, -1, 1, -1};

//int x[4] = {1, 0, -1, 0};
//int y[4] = {0, 1, 0, -1};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		int a, b;
		cin >> a >> b;
		string s;
		cin >> s;
		int n = s.size();
		int cnt_a = 0;
		int cnt_b = 0;
		for (int i = 0; i < n; i++) {
			cnt_a += (s[i] == '0');
			cnt_b += (s[i] == '1');
		}
		if (cnt_a > a || cnt_b > b) {
			cout << -1 << '\n';
			continue;
		}
		a -= cnt_a;
		b -= cnt_b;
		bool checker = true;
		int rem = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] == '?' || s[n - 1 - i] == '?') {
				if (s[i] == '?' && s[n - 1 - i] == '?') {
					rem++;
				} else {
					char ch = (s[i] != '?' ? s[i] : s[n - 1 - i]);
					s[i] = ch;
					s[n - 1 - i] = ch;
					if (ch == '0') {
						if (a > 0) {
							a--;
						} else {
							checker = false;
							break;
						}
					} else {
						if (b > 0) {
							b--;
						} else {
							checker = false;
							break;
						}
					}
				}
			} else {
				if (s[i] != s[n - 1 - i]) {
					checker = false;
					break;
				}
			}
		}
		if (!checker || (a + b) > rem) {
			cout << -1 << '\n';
			continue;
		}
		//cout << "s = " << s << endl;
		//cout << "a = " << a << endl;
		//cout << "b = " << b << endl;
		//cout << "rem = " << rem << endl << endl;
		for (int i = 0; i < n; i++) {
			if (s[i] == '?') {
				if (n % 2 == 1 && i == n / 2) {
					continue;
				}
				bool possible = true;
				char ch = '?';
				if (a - 2 >= 0) {
					ch = '0';
					a -= 2;
				} else if (b - 2 >= 0) {
					ch = '1';
					b -= 2;
				} else {
					possible = false;
				}
				if (possible) {
					s[i] = ch;
					s[n - 1 - i] = ch;
				} else {
					checker = false;
					break;
				}
			}
		}
		if (a == 1 && b == 0) {
			s[n / 2] = '0';
			a--;
		}
		if (a == 0 && b == 1) {
			s[n / 2] = '1';
			b--;
		}
		if (!checker || a > 0 || b > 0) {
			cout << -1 << '\n';
			continue;
		}
		cout << s << endl;
	}
}
