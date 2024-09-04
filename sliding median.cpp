Cho mảng A[] gồm N phần tử và số nguyên K, bạn hãy tìm median của mọi dãy con liên tiếp cỡ K của mảng A[].

Đầu vào
Dòng 1 là N và K

Dòng 2 gồm N số trong mảng A[]

Giới hạn
• 1<=K<=N<=2.10^5

• 1<=A[i]<=10^9

Đầu ra
In ra N - K + 1 median của các dãy con

Ví dụ :
Input 01
Copy
8 2
7 6 6 2 9 6 2 7
Output 01
Copy
6 6 2 2 6 2 2

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    int n,k;
    cin>>n>>k;
    ll a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    multiset<ll> se;
    for(int i= 0;i<k;i++){
        se.insert(a[i]);
    }
    auto j = next(se.begin(),(k-1)/2);
    for(int i=k;i<=n;i++){
        cout<< *j<<" ";;
        if(i==n) break;
        se.insert(a[i]);
        if(a[i]<*j) --j;
        if(a[i-k]<= *j) ++j;
        se.erase(se.lower_bound(a[i-k]));
    }
    return 0;
}
