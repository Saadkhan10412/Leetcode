class Solution {
private:
    int f(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if(ind==nums.size()) return 0;
        if(dp[ind][prev+1]!=1e9) return dp[ind][prev+1];
        int notTake=f(ind+1,prev,nums,dp);
        int take=-1e9;
        if(prev==-1 || nums[ind]>nums[prev]) {
            take =1+f(ind+1,ind,nums,dp);
        }
        return dp[ind][prev+1]=max(take, notTake);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(nums.size()+1,1e9));
        return f(0,-1,nums,dp);
    }
};