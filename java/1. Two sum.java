class Solution {
    public static int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> numberToPosition = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (numberToPosition.containsKey(target - nums[i])) {
                int position = numberToPosition.get(target - nums[i]);
                return new int[] { position, i };
            }

            numberToPosition.put(nums[i], i);
        }

        return new int[] { -1, -1 };
    }
}