#include <bits/stdc++.h>


//HackerRank Problem Solving
// 27/27 tests AC.
using namespace std;

//Using dynamic programming
int abbreviation(string a, string b) {
    
    int la = a.length()+1;
    int lb = b.length()+1;
    
    int dp[la][lb];
    
    memset(dp,0,sizeof(dp));
    //set all to 0s
    
    dp[0][0]=1;
    
    //small cases, if(lower) ==1
    for (int i=1; i<la; ++i){
        if (islower(a[i-1])){
            dp[i][0]=1;
        }
        else if (isupper(a[i-1])){
            break;
        }
    }
    
    //Carry forward the array
    for (int i=1; i<la; ++i){
        for (int j=1; j<lb; ++j){
            /*if (dp[i-1][j-1]==0){
                dp[i][j]=0;
            }*/
            if (isupper(a[i-1])){
                if (a[i-1]==b[j-1]  && dp[i-1][j-1]==1){
                    dp[i][j]=1;
                }
                else{      //include the above case
                    dp[i][j]=0;
                }
            }
            else{
                if ((a[i-1]-32)==b[j-1] && dp[i-1][j-1]==1){
                    dp[i][j]=1;
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
    }
    
    return dp[la-1][lb-1];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int T;
    string a,b;
    cin>>T;
    while(T--){
        cin>>a;
        cin>>b;
        if (abbreviation(a,b)==1){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
    }
    
    return 0;
}
