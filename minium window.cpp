Cho 2 xâu kí tự S và T, nhiệm vụ của bạn là tìm xâu con ngắn nhất của S chứa đầy đủ mọi kí tự của xâu T. Ví dụ S = ADOBECODEBANCC, T = CABC thì xâu con BANCC là xâu con ngắn nhất của S chứa đầy đủ mọi kí tự của T

Đầu vào
• Dòng 1 là xâu S

• Dòng 2 là xâu T

Giới hạn
• 1<=len(T),len(S)<=10^6

• S, T chỉ chứa các kí tự in thường

Đầu ra
In ra xâu con nhỏ nhất thỏa mãn và xuất hiện đầu tiên nếu có nhiều xâu thỏa mãn. Nếu không tồn tại đáp án in ra -1

Ví dụ :
Input 01
Copy
dbcddbaaccacb
ab
Output 01
Copy
ba

#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie() -> sync_with_stdio(0);

	string s, t;
	cin >> s >> t;
	int n = s.size();
	int m = t.size();

	map <char, int> cT, cS; // cT(x) : so luong ky tu x nam trong T, S
	for (auto &x : t) cT[x]++;

	int l = 0, ans = 1e9, j = 0;
	int cnt = 0; // So luong ky tu cua T nam trong cua so hien tai
	for (int r = 0; r < n; ++r) {
		cS[s[r]]++;

		if (cS[s[r]] <= cT[s[r]]) ++cnt;

		if (cnt == m) { // Neu nhu cua so hien tai chua du ky tu, ta se thu hep lai
			// neu nhu S chua nhieu ky tu x hon so lan xuat hien cua x trong T
			// hoac ky tu x khong xuat hien trong T
			while ((cS[s[l]] > cT[s[l]]) || (cT[s[l]] == 0)) {
				if (cS[s[l]] > cT[s[l]])
					--cS[s[l]];
				++l;
			}

			int cur_len = r - l + 1;
			if (ans > cur_len) {
				ans = cur_len;
				j = l;
			}
		}
	}

	if (ans == 1e9)
		cout << "-1\n";
	else {
		// r - l + 1 = ans -> r = ans + l - 1;
		for (int i = j; i <= ans + j - 1; ++i)
			cout << s[i];
	}

	return 0;
}
