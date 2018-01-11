# Solution

## Function 1

暴力搜索，进行循环查找，复杂度O(n^2)

```
    public int[] twoSum2(int[] nums, int target) {
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (nums[j] == target - nums[i]) {
                    return new int[] {i,j};
                }
            }
        }

        throw new IllegalArgumentException("Nothing");
    }
```