class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if (k<2) { return nums; }
        int max = nums[0];
        vector<int> out;
        for (int i=1; i<k; i++){
            if (nums[i] > max){
                max = nums[i];
            }
        }

        out.push_back(max);

        for (int i=k; i<nums.size(); i++){
            if (nums[i-k] == max){
                max = nums[i-k+1];

                for (int j=i-k+1; j<=i; j++){
                    if (nums[j] > max ){
                        max = nums[j];
                    }
                }
            }
            else if(nums[i] > max){
                max = nums[i];
            }
            
        out.push_back(max);
        }
    return out;
    }
};
