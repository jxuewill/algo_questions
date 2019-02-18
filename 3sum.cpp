/*Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for (int i  = 0; i < nums.size(); i++){
            int target = nums[i];
            int front = i + 1;
            int back = nums.size() -1;
            while (front < back){
                int sum = nums[front] + nums[back];
                if (sum + target < 0){
                    front ++;
                }
                else if (sum + target > 0){
                    back --;
                }
                else {
                    vector<int> tmp;
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[front]);
                    tmp.push_back(nums[back]);
                    res.emplace_back(tmp);

                    while (front < back && nums[front] == tmp[1]) front ++;
                    while (front < back && nums[back] == tmp[2]) back--;
                }
            }
            while (i + 1 < nums.size() && nums[i+1] == nums[i])
                i++;
        }
        return res;
    };
};
