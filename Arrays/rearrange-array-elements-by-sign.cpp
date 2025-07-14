// Leetcode 2149: Rearrange array elements by sign

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int positive = 0;
        int negative = 1;
        int n = nums.size();
        vector<int> answer(n);
        for(int i=0; i<n; i++){
            if(nums[i]>0){
                answer[positive] = nums[i];
                positive+=2;
            }
            else{
                answer[negative] = nums[i];
                negative+=2;
            }
        }
        return answer;
    }
};
