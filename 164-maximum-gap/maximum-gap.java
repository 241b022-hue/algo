class Solution {
    public int maximumGap(int[] nums) {
        if(nums.length >= 2){
        Arrays.sort(nums);
        int maxValue = Integer.MIN_VALUE;
      for(int i = 0; i<nums.length-1; i++){
        if(Math.abs(nums[i] - nums[i+1]) > maxValue){
            maxValue = Math.abs(nums[i] - nums[i+1]);
        }
         
      }
      return maxValue;
    }
    return 0;
    }
}