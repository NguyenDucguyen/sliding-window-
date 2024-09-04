Cho mảng A[] gồm N phần tử và số nguyên K, nhiệm vụ của bạn là in ra số lớn nhất và nhỏ nhất của mọi mảng con cỡ K của mảng A[]

Đầu vào
Dòng đầu tiên là N và K

Dòng thứ 2 gồm N phần tử A[i]

Giới hạn
1<=K<=N<=10^6

0<=A[i]<=10^9

Đầu ra
In ra số lớn nhất và nhỏ nhất của mọi mảng con trên từng dòng.

Ví dụ :
Input 01
Copy
8 2
8 5 8 6 7 6 5 8
Output 01
Copy
5 8
5 8
6 8
6 7
6 7
5 6
5 8

#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

       multiset<int>se;
    for(int i=0;i<k;i++){
        se.insert(a[i]);
    }
    for(int i=k;i<=n;i++){
        cout<<(*se.begin())<<" "<<(*se.rbegin())<<"\n";

     if(i==n) break;
     se.insert(a[i]);
     se.erase(se.lower_bound(a[i-k]));

    }
}
