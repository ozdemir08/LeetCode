class Solution {
    public long maxArrayValue(int[] nums) {
        // if nums[i] <= nums[i+1], then great we can grow nums[i+1]
        // if nums[i] > nums[i+1], then focus on the right side of i+1 and
        // make it bigger than nums[i] if possible.
        // We can start from the last.
        // If nums[i+1] >= nums[i], then do the operation.
        // If nums [i+1] < nums[i], then hold the result and continue with the new

        if (nums.length == 0) {
            return 0;
        }

        int result = nums[nums.length - 1];
        int currentMax = nums[nums.length - 1];

        for (int i = nums.length - 2; i >= 0; i--) {
            if (nums[i] <= currentMax) {
                currentMax = currentMax + nums[i];
            } else {
                result = Math.max(result, currentMax);
                currentMax = nums[i];
            }
        }

        result = Math.max(result, currentMax);

        return result;
    }
}