class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        bool flag=true;
        int n=nums.size();
        for(int i=0;i<n-2;i+=3)
        {
            if(nums[i+2]-nums[i]>k)
            {
                flag=false;
                break;
            }
        }
        if(flag==true)
        {
            for(int i=0;i<n-2;i+=3)
            {
                vector<int>temp;
                temp.push_back(nums[i]);
                temp.push_back(nums[i+1]);
                temp.push_back(nums[i+2]);
                res.push_back(temp);
            }
        }
        return res;
    }
};
