class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        vector<int> ans;
        while (!nums.empty()) {
            int x = *min_element(nums.begin(), nums.end());
            auto it = find(nums.begin(), nums.end(), x);
            ans.push_back(x);
            nums.erase(it);
        }
        for(int i=0;i<ans.size();i+=2)
        {
            swap(ans[i],ans[i+1]);
        }
        return ans;
    }
};

