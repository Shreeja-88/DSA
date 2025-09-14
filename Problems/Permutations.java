/*Question -> https://leetcode.com/problems/permutations/description/
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

 */

class Solution {
    public void backtrack(int[] nums, List<Integer> current,boolean[]used,List<List<Integer>> result){
        if(current.size()==nums.length){
            result.add(new ArrayList<>(current));
            return;
        }
        for(int i=0;i<nums.length;i++){
            if (used[i]){
                continue; 
            }

            used[i] = true;
            current.add(nums[i]);

            backtrack(nums, current, used, result);

            current.remove(current.size() - 1);
            used[i] = false;

        }    
    }

    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        backtrack(nums, new ArrayList<>(), new boolean[nums.length],result);
        return result; 
    }
}