/*******
CorrectSentence(CORSENT) problems in CodeChef Starter Div 3.
All tests got AC.
*******/

#define sai "NO"
#define dung "YES"
#define  L length()
//Just for the typing convinience 
#include <iostream>
#include <string>

using namespace std;

string solve(string spoken){
    int mod1=0,mod2=0;
    
    for (int i=0; i<spoken.L; ++i){
        if(spoken[i]==' '){
            if(spoken[i+1]>=97 && spoken[i+1]<=109){
                mod1=97; mod2=109;
            }
            else if(spoken[i+1]>=78 && spoken[i+1]<=90){
                mod1=78; mod2=90;
            }
            else{
                return sai;
            }
        }
        else{
            if(spoken[i]<mod1 || spoken[i]>mod2){
                return sai;
            }
        }
    }
        
    return dung;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string spoken = "";
    short T=0,K=0;
    
    cin>>T;
    
    while(T--){
        cin>>K;
        getline(cin,spoken);
        
        cout<<solve(spoken)<<endl;
        
    }
    return 0;
}
.
