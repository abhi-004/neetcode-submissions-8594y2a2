class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> dict;
        for (string s: strs){
            string sorted_str = s;
            sort(sorted_str.begin(), sorted_str.end());
            dict[sorted_str].push_back(s);
        }
        vector<vector<string>> out;
        for (auto &entry : dict){
            out.push_back(entry.second);
        }

        return out;
    }
    
};
