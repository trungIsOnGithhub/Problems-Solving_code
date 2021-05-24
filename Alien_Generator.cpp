//2/2 Test Sets
//KickStart Round C 2021 Problems 2.

#include <iostream>
#include <cmath>

using namespace std;

int alien_generator(long long G){
    int maxI=sqrt(2*G),count=1; 
    double K=0.0;
    
    for(int i=1; i<maxI; ++i){
        K=(2.0*G-i*(i+1))/(2*(i+1));
        
        if(K==(long long)K) ++count;
        
    }
    
    return count;
}

int main(){
    int T=0;
    long long G=0;
    cin>>T;
    
    for(int i=1; i<=T; ++i){
        cin>>G;
        cout<<"Case #"<<i<<": "<<alien_generator(G)<<'\n';
    }
    
    return 0;
}