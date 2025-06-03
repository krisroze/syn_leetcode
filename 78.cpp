// leetcode.com/problems/subsets/
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans = {vector<int>()};

        for (int num : nums) {
            int ansSize = ans.size();
            for (int i = 0; i < ansSize; i++) {
                vector<int> a = ans[i];
                a.push_back(num);
                ans.push_back(a);
            }
        }
        return ans;
    }
};