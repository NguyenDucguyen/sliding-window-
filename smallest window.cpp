Cho xâu S chỉ gồm chữ cái in thường, nhiệm vụ của bạn là tìm chiều dài của xâu con liên tiếp nhỏ nhất có chứa đầy đủ các kí tự khác nhau của S.

Ví dụ S = abcaaaabcad thì xâu con bcad có độ dài nhỏ nhất và chứa đầy đủ các kí tự khác nhau của S.

Đầu vào
Dòng duy nhất chứa xâu S

Giới hạn
1<=len(S)<=10^6

Đầu ra
In ra độ dài xâu con nhỏ nhất tìm được

Ví dụ :
Input 01
Copy
28teeeeeechhhh
Output 01
Copy
11

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    string s;
    cin>>s;
    int n = s.size();
    map<char,int>mp; // so lan xua hien cua ki tu x trong cua so hien tai
    int cnt =0; //so luong ki tu khac nhau cua so hien tai

    int dis_cnt = 0; //so luong ki tu khac nhau cua thang s
    set<int>se;
    for(auto x :s){
       se.insert(x);
    }
    dis_cnt = se.size();
    int l=0;
    int ans = n;
    for(int r=0;r<n;r++){
        mp[s[r]] ++;
        if(mp[s[r]] == 1) ++cnt;
        if(cnt == dis_cnt){ //co the thu hep lai cua so
            while(mp[s[l]] > 1){
                if(mp[s[l]]>1) mp[s[l]] --;
                l++;
            }
            ans = min(ans,r-l+1);
        }
    }
    cout<<ans;


 return 0;
}
