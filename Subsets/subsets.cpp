class Solution {
public:
    
    void powerSet(vector<int> nums, vector<vector<int>>& ans, vector<int> output, int i)
    {
        //Base Case
        if(i>=nums.size())
        {
            ans.push_back(output);
            return;
        }
        
        //Recursive Call for excluding an element
        powerSet(nums,ans,output,i+1);
        
        //Recursive Call for including an element
        int a = nums[i];
        output.push_back(a);
        powerSet(nums,ans,output,i+1);
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> output;
        int i=0;
        powerSet(nums,ans,output,i);
        return ans;
    }
};
