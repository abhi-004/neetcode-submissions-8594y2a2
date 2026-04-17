class Solution {
public:
    bool canEatBananas(vector<int>& piles,int k, int h){
        long long hours=0;
        for (int p: piles){
            hours += p/k + (p%k != 0 ? 1 : 0); 
        }
        return hours <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        while(low < high){
            int mid = low + (high-low)/2;

            if (canEatBananas(piles, mid, h)){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        return low;
    }
};
