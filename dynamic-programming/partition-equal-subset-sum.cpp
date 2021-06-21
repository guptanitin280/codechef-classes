//link:- https://leetcode.com/problems/partition-equal-subset-sum/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int S=0;
        for(auto &c:nums){
            S+=c;
        }
        if(S&1){
            return false;
        }
        bool dp[n][S/2+1];
        memset(dp,false,sizeof dp);
        dp[0][0]=true;
        if(nums[0]<=S/2)
            dp[0][nums[0]]=true;
        for(int i=1;i<n;i++){
            for(int j=0;j<=S/2;j++){
                dp[i][j]|=dp[i-1][j];
                if(j>=nums[i])
                    dp[i][j]|=dp[i-1][j-nums[i]];
            }
        }
        return dp[n-1][S/2];
    }
};