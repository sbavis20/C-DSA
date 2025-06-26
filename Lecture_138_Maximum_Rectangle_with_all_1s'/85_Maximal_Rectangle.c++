class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxi = INT_MIN;

        vector<int>histogram(matrix[0].size(),0);

        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<histogram.size();j++){
                if(matrix[i][j]=='1'){
                    histogram[j]++;
                }else{
                    histogram[j]=0;
                }
            }
            maxi =max(maxi,largestArea(histogram));
        }
        return maxi;
    }
};
