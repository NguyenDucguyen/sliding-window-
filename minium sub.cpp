Cho mảng A[] có N phần tử, bạn hãy tìm ra dãy con các phần tử liên tiếp có tổng tối thiểu bằng K. Nếu có nhiều dãy con thỏa mãn hãy in ra dãy con ngắn nhất xuất hiện đầu tiên, trong trường hợp không tồn tại dãy con thỏa mãn in ra -1.

Đầu vào
• Dòng 1 là N và K

• Dòng 2 gồm N số trong mảng A[]

Giới hạn
• 1<=N<=10^6

• 0<=A[i]<=10^6

• 0<=K<=10^9

Đầu ra
In ra đáp án của bài toán

Ví dụ :
Input 01
Copy
11 7
2 4 0 4 2 3 3 2 0 0 3
Output 01
Copy
4 0 4

#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
	cin.tie() -> sync_with_stdio(0);

	int n, k;
	cin >> n >> k;
	vector <int> a(n);
	for (auto &x : a) cin >> x;

	ll sum = 0;
	int l = 0, ans = 1e9, j = 0;
	for (int r = 0; r < n; ++r) {
		sum += a[r];
		if (sum >= k) {
			while (sum - a[l] >= k) { // thu hep lai cua so
				sum -= a[l];
				++l;
			}

			// cout << l << " " << sum << "\n";
			int cur_len = r - l + 1;
			if (ans > cur_len) {
				ans = cur_len;
				j = l;
			}
		}
	}
	// cout << ans << '\n';
	if (ans == 1e9) {
		cout << "-1\n";
	}
	else {
		for (int i = j; i <= j + ans - 1; ++i) cout << a[i] << " ";
	}

	return 0;
}
