class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0;
        int j = numbers.size()-1;
        vector<int> output;
        while(i<j){
            int sum = numbers[i] + numbers[j];
            if (sum == target){
                output.push_back(i+1);
                output.push_back(j+1);
                return output;
        }
            else if (sum > target){
                j=j-1;
            }
            else if (sum < target){
                i=i+1;
            }
               
            }

    return output;
    }
};
