class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        hFences.push_back(1);
        hFences.push_back(m);
        vFences.push_back(1);
        vFences.push_back(n);
        sort(hFences.begin(),hFences.end());
        sort(vFences.begin(),vFences.end());
        unordered_set<int>hset;
        int x=hFences.size();
        int y=vFences.size();
        for(int i=0;i<x-1;i++)
        {
            for(int j=i+1;j<x;j++)
            {
                hset.insert(hFences[j]-hFences[i]);
            }
        }
        int ans=-1;
        int mx=0;
        for(int i=0;i<y-1;i++)
        {
            for(int j=i+1;j<y;j++)
            {
                if(hset.count(vFences[j]-vFences[i]))
                {
                    mx=max(mx,vFences[j]-vFences[i]);
                }
            }
        }
        if(mx==0)
        {
            return -1;
        }
        else
        {
        return ((long long)(mx)*(mx))%1000000007;
        }
    }
};
