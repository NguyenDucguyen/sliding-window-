Cho xâu kí tự S, Tèo là một người khá kì quặc, anh ta chỉ thích những thứ không trùng lặp. Vì thế anh ta yêu cầu bạn tìm ra độ dài xâu con dài nhất mà các kí tự trong xâu con đó không có bất cứ một kí tự nào được lặp lại.

Đầu vào
Dòng duy nhất chứa xâu S

Giới hạn
• 1<=len(S)<=10^6

• S chỉ bao gồm chữ cái in thường

Đầu ra
In ra đáp án của bài toán

Ví dụ :
Input 01
Copy
dabacdadbbdd
Output 01
Copy
4

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    string s;
    cin>>s;
    int n = s.size();
    map<char,bool>mp; // so lan xua hien cua ki tu x trong cua so hien tai
    int l=0;
    int ans = 0;
    for(int r=0;r<n;r++){
        if(mp[s[r]] == true){
             while(mp[s[r]] == true){
                mp[s[l]] = false;
                l++;
             }
        }
        mp[s[r]] = true;
        ans = max(ans , r-l+1);
    }
    cout<<ans;


 return 0;
}
