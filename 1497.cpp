// https://leetcode.com/problems/perfect-squares/
class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> remainderVec(k, 0);

        for (int num : arr) {
            int remainder = ((num % k) + k) % k;
            remainderVec[remainder]++;
        }

        for (int i = 0; i <= k / 2; i++) {
            if (i == 0) {
                if (remainderVec[i] % 2 != 0) return false;
            } else {
                if (remainderVec[i] != remainderVec[k - i]) return false;
            }
        }

        return true;
    }
};