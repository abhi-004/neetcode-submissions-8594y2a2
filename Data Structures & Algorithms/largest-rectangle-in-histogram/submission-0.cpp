class Solution {
public:
    vector<int> nextSmallestElement(vector<int> heights, int n){
        vector<int> output(n);
        stack<int> stk;
        for (int i=n-1; i>=0; i--){
            while(!stk.empty() && heights[stk.top()] >= heights[i]){
                stk.pop();
            }

            if (stk.empty()) 
                output[i] = n;
            else
                output[i] = stk.top();

            stk.push(i);

        }
        return output;
    }

    vector<int> prevSmallestElement(vector<int> heights, int n){
        vector<int> output;
        stack<int> stk;

        for (int i=0; i<n; i++){
            while(!stk.empty() && heights[stk.top()] >= heights[i])
                stk.pop();

            if (stk.empty()) 
                output.push_back(-1);
            else
                output.push_back(stk.top());
            
            stk.push(i);
        }
        return output;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nse = nextSmallestElement(heights, n);
        cout << "nse : " << endl;
        for (int x : nse) cout << x << " " << endl;
        vector<int> pse = prevSmallestElement(heights, n);
        cout << "pse : " << endl;
        for (int y : pse) cout << y << " " << endl;
        int maxi = INT_MIN;

        for (int i=0; i<n; i++){
            maxi = max(maxi, heights[i] * (nse[i]-pse[i]-1));
        }
        
        return maxi;
    }
};
