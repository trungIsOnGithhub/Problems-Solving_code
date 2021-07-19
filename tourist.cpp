#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

// short places[51];
short dummy[51];
string places_names[51];

// void exchange(int idx1, int idx2){
    
//     short temp = places[idx1];
//     places[idx1] = places[idx2];
//     places[idx2] = temp;
// }

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    short T;
    cin>>T;
    
    for(int x=1; x<=T; ++x){
        
        short K,N;
        long long V;
        
        cin>>N>>K>>V;
        for(int i=1; i<=N; ++i){
            
            cin>>places_names[i];
        }
        
        // for(int i=1; i<=50; ++i)
        //     { places[i] = i; }    //mark the places(destinations) with 1,2,3... denotes for there popularity increasing
            
        //ROTATE STRING
        short reps = (V-1)%N;
        
        if( reps!=0 ){
            
            reps = (reps*K)%N;
            // cout<<reps<<'\n';
            
            for(int i=1; i<=(N-reps); ++i){

                dummy[i] = reps+i;
            }
            for(int i=1; i<=reps; ++i){

                dummy[N-reps+i] = i;
            }
            sort(dummy+1,dummy+K+1);
        }
        else{
            
            for(int i=1; i<=K; ++i){
                
                dummy[i] = i;
            }
        }

        
        // for(int i=1; i<=4; ++i){
        //     cout<<dummy[i];
        // }
        // cout<<endl;
        
        cout<<"Case #"<<x+126<<": ";
        
        for(int i=1; i<=K; ++i){
            
            cout<<places_names[dummy[i]];
            if(i!=K)
                { cout<<" "; }
        }
        cout<<'\n';
    }
    
    return 0;
}
