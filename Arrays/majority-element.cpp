// Leetcode 169 : Majority Element
// Boyer-Moore's Voting Algorithm

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate;
        int count = 0;
        for(int i=0; i<nums.size(); i++){
            if(count == 0){
                count++;
                candidate = nums[i];
                
            }
            else if(nums[i]==candidate){
                count++;
            }
            else{
                count--;
            }
        }
        return candidate;
    }
};
