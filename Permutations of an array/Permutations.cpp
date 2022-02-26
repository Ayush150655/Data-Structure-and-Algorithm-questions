class Solution {
private:
     void permu(vector<int> nums, int i, vector<vector<int>>& ans){
        if(i>=nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int j=i;j<nums.size();j++)
        {
            swap(nums[i],nums[j]);
            permu(nums,i+1,ans);
            swap(nums[i],nums[j]);      //backtrack
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int i=0;
        permu(nums,i,ans);
        return ans;
    }
};
