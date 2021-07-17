#include <iostream>

//random on codechef

using namespace std;

int main() {
    
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int N;
	cin>>N;
	
	int store[N+1][3];
	
	for(int i=1; i<=N; ++i){
	    
	    cin>>store[i][0];
	}
	
	/* store[i][0] for the input numbers
	   store[i][1] is used to store the "safe" earn for next, otherwise store[i][2] for the "unsafe"
	   "safe" for the next means it can take the next value for consider next time, which you cannot do with "unsafe" */
	
	//set up the initial value
	store[1][1] = 0;
	store[1][2] = store[1][0];
	
	store[2][1] = store[2][0];
	store[2][2] = store[2][0] + store[1][0];
	
	store[3][1] = store[1][0] + store[3][0];
	store[3][2] = store[2][0] + store[3][0];
	
	for(int i=4; i<=N; ++i){  //start with 4 and proceed to the final postion. Finding all the "safe" and "unsafe" for each.
	    
	    store[i][1] = store[i][0] + max(max(store[i-3][2],store[i-2][1]),store[i-2][2]);
	    store[i][2] = store[i][0] + store[i-1][1];
	}
	
	cout<<max(store[N-1][2],max(store[N][1],store[N][2]));   //compared between the "safe" and "unsafe" at the final postion.
	
	return 0;
}
