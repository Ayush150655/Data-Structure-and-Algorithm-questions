#include <bits/stdc++.h>
using namespace std;


class Solution{
    private:
    bool isAllowed(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>>& m)
    {
        if((x>=0 && x<n-1)&&(y>=0 && y<n-1) && visited[x][y]==0 && m[x][y]==1)
        {
            return true;
        }
        else {
            return false;
        }
    }
    
    void solveMaze(vector<vector<int>>& m, int n, vector<string>& ans, int x, int y, vector<vector<int>> visited, string path){
        if(x==n-1 && y==n-1)
        {
            ans.push_back(path);
            return;
        }
        visited[x][y]=1;
        int newx,newy;
        
        //DOWN
        newx=x+1;
        newy=y;
        if(isAllowed(newx,newy,n,visited,m))
        {
            path.push_back('D');
            solveMaze(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        
        //UP
        newx=x-1;
        newy=y;
        if(isAllowed(newx,newy,n,visited,m))
        {
            path.push_back('U');
            solveMaze(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        
        //RIGHT
        newx=x;
        newy=y+1;
        if(isAllowed(newx,newy,n,visited,m))
        {
            path.push_back('R');
            solveMaze(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        
        //LEFT
        newx=x;
        newy=y-1;
        if(isAllowed(newx,newy,n,visited,m))
        {
            path.push_back('L');
            solveMaze(m,n,ans,newx,newy,visited,path);
            path.pop_back();
        }
        
        
        visited[x][y]=0;
    }
    
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        if(m[0][0]==0){
            return ans;
        }
        vector<vector<int>> visited=m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                visited[i][j]=0;
            }
        }
        int srcx=0;
        int srcy=0;
        string path="";
        solveMaze(m,n,ans,srcx,srcy,visited,path);
        sort(ans.begin(),ans.end());
        return ans;
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  
