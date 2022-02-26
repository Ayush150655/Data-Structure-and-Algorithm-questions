class Solution {
public:
    
    void phoneNumber(string digits, vector<string>& ans, string output, string alpha[], int i)
    {
        if(i>=digits.length())
        {
            ans.push_back(output);
            return;
        }
        int no=digits[i]-'0';
        string str=alpha[no];
        for(int j=0;j<str.length();j++)
        {
            output.push_back(str[j]);
            phoneNumber(digits,ans,output,alpha,i+1);
            output.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        string alpha[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        string output;
        int i=0;
        vector<string> ans;
        if(digits.length()==0)
            return ans;
        phoneNumber(digits,ans,output,alpha,i);
        return ans;
    }
};
