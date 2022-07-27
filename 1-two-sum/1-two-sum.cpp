class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        int i = 0 ;
        int j = copy.size()-1;
        while(copy[i]+copy[j]!=target){
            if(copy[i]+copy[j]<target){
                i++;
            }
            else{
                j--;
            }
        }
        vector<int>indices;
        for(int c = 0 ; c < nums.size() ; c++){
            if(copy[i]==nums[c]){
                indices.push_back(c);
            }
            else if(copy[j]==nums[c]){
                indices.push_back(c);
            }
        }
        return indices;
    }
};