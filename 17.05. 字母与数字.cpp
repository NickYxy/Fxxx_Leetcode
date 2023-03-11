class Solution {
public:
    vector<string> findLongestSubarray(vector<string>& array) {
        int n = array.size();
        int maxlen = 0, start = -1, sum = 0;
        unordered_map<int, int> mp;
        mp[0] = -1;
        for (int i = 0; i < n; i ++) {
            if (isalpha(array[i][0])) {
                sum ++;
            } else {
                sum --;
            }

            if (mp.count(sum) == 0) {
                mp[sum] = i;
            } else {
                if (maxlen < (i - mp[sum])) {
                    maxlen = i - mp[sum];
                    start = mp[sum] + 1;
                }
            }
        }

        if (maxlen == 0) return {};
        return vector<string>(array.begin() + start, array.begin() + start + maxlen);
    }
};