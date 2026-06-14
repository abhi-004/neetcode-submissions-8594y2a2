class Solution {
public:
    string minWindow(string s, string t) {
        
       int n = s.size();
       int m = t.size();
       int minLength = INT_MAX;
       int startIndex = -1;

       for (int i=0; i<n; i++){
            int charMap[256] = {0};
            int count = 0;

            for (int j=0; j<m; j++)
                charMap[(unsigned char)t[j]]++;
            
            for (int j=i; j<n; j++){
                if (charMap[(unsigned char)s[j]] > 0){
                    count++;
                }
                
                charMap[(unsigned char)s[j]]--;

                if (count == m){
                    if (j-i+1 < minLength){
                        minLength = j-i+1;
                        startIndex = i;
                        break;
                    }
                }
            }
       }
       if (startIndex == -1)
            return "";
            
       return s.substr(startIndex, minLength);

       
    }
};
