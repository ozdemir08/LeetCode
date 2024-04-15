import java.io.*;
import java.util.Map.Entry;

class SparseVector {
    Map<Integer, Integer> sparseVectorMap;
    int length;

    SparseVector(int[] nums) {
        this.sparseVectorMap = initializeSparseVectorMap(nums);
        this.length = nums.length;
    }

    private static Map<Integer, Integer> initializeSparseVectorMap(int[] nums) {
        Map<Integer, Integer> map = new HashMap<>();
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] != 0) {
                map.put(i, nums[i]);
            }
        }

        return map;
    }

    // Return the dotProduct of two sparse vectors
    public int dotProduct(SparseVector vec) {
        int result = 0;
        for (Entry<Integer, Integer> entry : sparseVectorMap.entrySet()) {
            result = result + entry.getValue() * vec.sparseVectorMap.getOrDefault(entry.getKey(), 0);
        }

        return result;
    }
}

// We can also store the non-null values in a list and iterate over the list
// using two pointers. This approach is more efficient than the one in this
// code.