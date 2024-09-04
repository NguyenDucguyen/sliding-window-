Cho dãy số A[] gồm có N phần tử và số nguyên dương k. Hãy tìm dãy con liên tiếp có k phần tử sao cho dãy con đó có tổng các phần tử lớn nhất.

Đầu vào
Dòng đầu tiên là số nguyên N và K.

Dòng tiếp theo gồm N số nguyên A[i]

Giới hạn
1≤ K ≤ N ≤ 10^7

1 ≤ A[i] ≤ 10^9

Đầu ra
Dòng 1 in ra tổng lớn nhất của dãy con K phần tử liền kề.

Dòng 2 in ra dãy con đó, nếu có nhiều dãy con có cùng tổng lớn nhất thì in ra dãy con xuất hiện đầu tiên.

Ví dụ :
Input 01
Copy
59 4
72 39 5 74 29 83 63 67 69 10 50 86 32 66 96 100 47 32 41 96 9 7 58 97 87 26 21 23 100 52 31 76 43 74 17 72 104 40 99 8 16 27 38 78 69 46 16 58 73 52 49 67 62 42 64 28 46 34 83
Output 01
Copy
315
72 104 40 99

#include<bits/stdc++.h>
using namespace std;

int main(){
   int n, k;
   cin >> n >> k;
   long long a[n];
   for(int i = 0; i < n; i++){
      cin >> a[i];
   }
   long long f[n];
   for(int i = 0; i < n; i++){
     if(i == 0)
        f[0] = a[0];
     else
        f[i] = f[i-1] + a[i];
   }
   long long maxsum = 0;
   int l = 0, r = k - 1;
   int start =0;
   while (r < n) {
     long long sum = 0;
     if(l == 0)
        sum += f[r];
     else
        sum += (f[r] - f[l-1]);
     if(sum > maxsum){
        maxsum = sum;
         start = l;
     }
     l++;
     r++;
   }
   cout <<maxsum<<endl;
   for(int i=start;i<start + k;i++){
      cout<<a[i]<<" ";
   }


}
