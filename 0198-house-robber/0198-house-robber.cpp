class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        int a=nums[0];
        if(nums.size()==1){
            return a;
        }
        int b=max(nums[1],nums[0]);
        for(int i=2;i<nums.size();i++){
            int temp=b;
            b=max((nums[i]+a),b);
            a=temp;
        }
        return max(a,b);
    }
};