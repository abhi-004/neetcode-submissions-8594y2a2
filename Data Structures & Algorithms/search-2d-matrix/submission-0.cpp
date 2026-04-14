class Solution {
public:
    bool binary_search(vector<int> arr, int target){
        int low = 0;
        int high = arr.size()-1;
        
        while (low <= high){
            int mid = low + (high-low)/2;

            if (arr[mid] == target) { return true; }
            else if (arr[mid] < target){ low = mid+1; }
            else {high = mid-1;}
        }
        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int matrix_low = 0;
        int matrix_high = matrix.size() - 1;
         
        while (matrix_low <= matrix_high){
            int matrix_mid = matrix_low + (matrix_high - matrix_low)/2;
            vector<int> row = matrix[matrix_mid];
            int array_length = row.size();

            if (row[0] == target || row[array_length-1] == target){
                return true;
            }
            else if (row[0] < target && row[array_length-1] < target){
                matrix_low = matrix_mid + 1;
            }

            else if (row[0] < target && row[array_length-1] > target){
                return binary_search(row, target);
            }

            else if (row[0] > target && row[array_length-1] > target){
                matrix_high = matrix_mid - 1;
            }
        }
        return false;
    }
};
