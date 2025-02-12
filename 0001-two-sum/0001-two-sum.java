class Solution {
    public int[] twoSum(int[] nums, int target) {
        int l = nums.length;
        int[] num1 = new int[2]; 

        for (int i = 0; i < l; i++) {
            for (int j = i + 1; j < l; j++) {
                if (nums[i] + nums[j] == target) { 
                    num1[0] = i;
                    num1[1] = j;
                    return num1;
                }
            }
        }

        
        return new int[0];
    }
}
