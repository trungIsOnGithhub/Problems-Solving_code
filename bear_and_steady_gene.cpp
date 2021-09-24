#include <iostream>
#include <map>
#include <string>

using namespace std;

/*Bear and steady gene. Practice problem on HackerRank
* 11/11 testcase passed
* Two-pointers technique */

//https://www.hackerrank.com/challenges/bear-and-steady-gene/problem

/*Two pointers("start" and "end", each denotes start and end of substring to be modified) starting from zero index.
* Keep a map(table) for the frequency of each letter in string gene. Every time the pointer move, the ffrequency will be decreased for increased
* to match with the purpose of the running pointer.
* In each iteration:
*   -At first, move the "end" pointer to the position where the whole substring from that position to the end is "steady"
*   -After that, move the "start" pointer to the position where the whole substring from that position back to the 0-indexed is "steady"
*   -Check if "end-start+1" is smaller than current result or not. If yes, assign the current 'ret' with "end-start+1"
* TIME COMPLEXITY: O(N), SPACE COMPLEXITY O(1).  
*/

int main(){
    //Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    string str="";
    int len = 0, ret = 0;
    
    map<char,int> count;      //count the number of appreance for A,T,C,G in the gene string. You can use array of 4.
    
    cin>>len;
    cin>>str;
    
    int steady = len/4;
    for(int i=0; i<len; ++i){
        ++count[str[i]];      
    }
    
    //BASE CASE
    if(count['A']==steady && count['T']==steady && count['G']==steady && count['C']==steady){ 
        ret = 0;
    }
    else{
        int start=0, end=0;
        ret = len;
        
        while(true){
            while(count['A']>steady  || count['T']>steady || count['G']>steady || count['C']>steady){
                --count[str[end]];
                if (end>=len-1)    //OUTER LOOP CONDITION
                    {break;}
                ++end;
            }
            
            if(end>=len-1)  //OUTER LOOP CONDITION
                {break;}
            
            while(count['A']<=steady && count['T']<=steady && count['G']<=steady && count['C']<=steady){
                ++count[str[start]];
                ++start;
            }
            
            if ((end-start+1)<ret)
                {ret = end-start+1;}
        }
    }
    cout<<ret;
    
    return 0;
}
