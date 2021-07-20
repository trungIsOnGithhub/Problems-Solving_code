/* LeetCode Biweekly 56 question 3
   Sum Game */
   
class Solution {
  
public:
    bool sumGame(string str) {
        
        int len = str.length();
        
        int half = len/2;
        int left = 0, right = 0;
        int sumleft = 0, sumright = 0;
        
        for(int i = 0; i<half; ++i){
            
            if( str[i]=='?' )   
            { ++left; }
            
            if( str[half+i]=='?' )
            { ++right;  }
            
            if(str[i]!='?')  
                { sumleft+=(str[i]-'0'); }

            if(str[half+i]!='?') 
                { sumright+=(str[half+i]-'0'); }
        }
        
        int diff_sum = sumleft - sumright;     //diff_sum is the difference in sum between left and right at the first time
        int diff_count = right - left;          //diff_count is the difference in the numer of '?' between right and left at the first time
        
        if( diff_count*9 == 2*diff_sum )     
             { return false; }
        
        return true;
        
    }
};
