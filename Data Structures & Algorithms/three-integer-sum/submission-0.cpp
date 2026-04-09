class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> out;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size(); i++){
            if (i>0 && nums[i-1] == nums[i]) continue;
            int target = -nums[i];

            int left=i+1;
            int right=nums.size()-1;
            while(left<right){
                vector<int> triplet;
                int sum = nums[left] + nums[right];
                if (sum == target){
                    triplet.push_back(nums[i]);
                    triplet.push_back(nums[left]);
                    triplet.push_back(nums[right]);
                    out.push_back(triplet);
                    left++;
                    right--;
                    while (left < right && nums[left-1]==nums[left]) left++;
                    while (left < right && nums[right]==nums[right+1]) right--;
                }
                else if (sum < target){
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return out;
    }
};
