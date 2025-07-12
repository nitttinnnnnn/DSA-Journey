// Leetcode 1 : Two Sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mpp;
        for(int i=0; i<nums.size(); i++){
            int number = nums[i];
            int difference = target - number;
            if(mpp.find(difference) != mpp.end()){
                return {mpp[difference] , i};
            }
            mpp[number] = i;
        }
        return {-1};  
    }
};

