// . = 1
// .. = 2
// ...= 2
// .... = 2
// .....= 2
// ......=4
// .......

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<char> s(n+1);
        for(int i=0;i<n;i++){
            cin>>s[i];
        }
        int res = 0;
        int count = 0;
        for(int i=0;i<=n;i++){
            if(s[i] == '.'){
                count++;
            }else{
                if(count == 2){
                    res += 2;
                }else if(count == 1){
                    res+=1;
                }else if(count>2){
                    res = 2;
                    break;
                }
                count = 0;
            }
        }
        cout<<"\n"<<res<<"\n";

    }
}