class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> hMap;
        vector<pair<int,int>> pair_map;
        for (int i=0; i<nums.size(); i++){
            hMap[nums[i]]++;
        }

        for (auto &[key,val]: hMap){
            pair_map.push_back({val,key});
        }

        sort(pair_map.rbegin(), pair_map.rend());

        vector<int> out;
        for (int i=0; i<k; i++){
            out.push_back(pair_map[i].second);
        }
    return out;
    }

};
