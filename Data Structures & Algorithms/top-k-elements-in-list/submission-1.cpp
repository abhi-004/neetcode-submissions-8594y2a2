class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hMap;
        vector<pair<int,int>> vec;
        vector<int> out;
        for(int i=0; i<nums.size(); i++){
            hMap[nums[i]]++;
        }   
        for (auto& [num, count] : hMap) {
            vec.push_back({count, num}); 
        }

        sort(vec.rbegin(), vec.rend()); 
        for (int i = 0; i < k; i++) {
            out.push_back(vec[i].second); 
        }
        return out;
        }

};
