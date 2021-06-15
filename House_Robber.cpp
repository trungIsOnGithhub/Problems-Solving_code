    int rob(vector<int> nums){
        int numsSize = nums.size();
        
        //Leetcode Practice Question: House Robber.
        //68/68 tests AC.
        //The input code has been provided for you.
        if(numsSize == 1) return nums[0];
        if(numsSize == 2) return (nums[1]>nums[0])? nums[1] : nums[0];
        
        int max_rob=0,temp=0;
        
        //dynamic programming approach
        for(int i=2; i<numsSize; ++i){
            for(int j=i-2; j>=0; --j){
                temp = max(nums[i]+nums[j],nums[i-1]); 
                if (temp>max_rob)
                    {max_rob=temp;}
            }
            
            nums[i] = max_rob;
        }

        return max_rob;
    }
