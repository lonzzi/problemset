package problems

import "sort"

func SubsetsWithDup(nums []int) [][]int {
	sort.Ints(nums)
	ans := [][]int{}
	ans = append(ans, []int{})
	array := []int{}
	var dfs func(int)
	dfs = func(startIndex int) {
		if len(array) == len(nums) {
			return
		}
		for i := startIndex; i < len(nums); i++ {
			if i > startIndex && nums[i] == nums[i-1] {
				continue
			}
			array = append(array, nums[i])
			temp := make([]int, len(array))
			copy(temp, array)
			ans = append(ans, temp)
			dfs(i+1)
			array = array[:len(array)-1]
		}
	}
	dfs(0)

	return ans
}