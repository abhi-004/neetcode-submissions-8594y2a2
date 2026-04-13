class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size()>s2.size()) { return false; }
        unordered_map<char, int> freq_map_s1;
        unordered_map<char, int> freq_map_s2;
        int k=s1.size();
        for (char c: s1){
            freq_map_s1[c]++; 
        }

        for (int i=0; i<k; i++){
            freq_map_s2[s2[i]]++;
        }

        if (freq_map_s1 == freq_map_s2) { return true; }

        for (int i=k; i<s2.size(); i++){
            freq_map_s2[s2[i]]++;
            freq_map_s2[s2[i-k]]--;

            if (freq_map_s2[s2[i-k]] == 0){
                freq_map_s2.erase(s2[i-k]);
            }

            if (freq_map_s1 == freq_map_s2){
            return true;
            }
        
        
    }
    return false;
    }    

};
