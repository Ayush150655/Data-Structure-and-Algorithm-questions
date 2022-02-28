#include<bits/stdc++.h>
using namespace std;


void findSeq(string str, vector<string>& ans, string s, int i)
{
    if(i>=str.length())
    {
        if(s.length()>0)
        	ans.push_back(s);
        return;
    }
    //exclude
    findSeq(str,ans,s,i+1);
    
    //include
    char ch=str[i];
    s.push_back(ch);
    findSeq(str,ans,s,i+1);
}

vector<string> subsequences(string str){
	
    vector<string> ans;
    string s="";
    int i=0;
    findSeq(str, ans, s, i);
    return ans;
	
}

int main()
{
    string str;
    cout<<"Enter a string : ";
    cin>>str;
    vector<string> res;
    res = subsequences(str);
    for(int i=0;i<res.size();i++)
        cout<<res[i]<<" ";
    return 0;
}
