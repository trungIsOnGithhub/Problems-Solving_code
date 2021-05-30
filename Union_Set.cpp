/*****
Pairwise union set(UNIONSET) CodeChef Practice Problems
*****/

#define B bool  //using bool to avoid MLE

#include <iostream>

using namespace std;

int unionWays(B* set1, B* set2, int sum, int K){
    int same=0;
    
    for (int i=0; i<K; ++i){
        if(set1[i]==1 && set2[i]==1){
            same+=1;
        }
    }
    
    return sum-same;
}

void solve(){        //using solve for allocating array on stack.
    int N=0,K=0;
    cin>>N>>K;
        
    int dummy2=0; int count=0; int sum=0;
    int len[N] = {0};
    
    B input[N][K];
    
    for (int i=0; i<N; ++i){
        for (int j=0; j<K; ++j){
            input[i][j]=0;
        }
    }
    
    for(int i=0; i<N; ++i){
        cin>>len[i];
        for(int j=0; j<len[i]; ++j){
            cin>>dummy2;
            input[i][dummy2-1]=1;
        }
    }

    for (int i=0; i<N-1; ++i){
        for (int j=i+1; j<N; ++j){
            sum=len[i]+len[j];
            if (unionWays(input[i],input[j],sum,K)==K){
                count+=1;
            }
        }
    }
    
    cout<<count<<endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T=0;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}