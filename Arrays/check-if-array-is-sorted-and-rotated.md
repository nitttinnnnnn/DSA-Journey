## Leetcode 1752 : Check if the array is sorted and rotated

Check if the array is non-decreasing (sorted) but possibly rotated by k places

    * The code simulates traversing the array twice (from i = 1 to 2n) using modulo operator:
    * Checks the condition : nums[(i-1)%n] <= nums[i%n] i.e compares consecutive elements in a circular way.
    * If the current element is greater than or equal to the previous, it's still part of a sorted streak → increase len.
    * If not, reset len to 0.
    * If you get a continuous len == n-1, it means you've found a full sorted rotation — return true.
