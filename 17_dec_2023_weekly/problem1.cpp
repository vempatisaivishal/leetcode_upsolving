class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int>ans;
        int mis=0;
        int n=grid.size();
        vector<int>ump(n*n,0);
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                ump[grid[i][j]-1]+=1;
            }
        }
        int a,b;
        for(int i=0;i<n*n;i++)
        {
            if(ump[i]==2)
            {
                a=i+1;
            }
            if(ump[i]==0)
            {
                b=i+1;
            }
        }
        ans.push_back(a);
        ans.push_back(b);
        return ans;
    }
};
