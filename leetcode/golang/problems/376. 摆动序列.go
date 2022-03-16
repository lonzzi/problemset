package problems

// nums = [1,17,5,10,13,15,10,5,16,8]
func WiggleMaxLength(nums []int) (ans int) {
	curDiff, preDiff := 0, 0
	for i := 0; i < len(nums)-1; i++ {
		curDiff = nums[i+1] - nums[i]
		if (curDiff > 0 && preDiff <= 0) || (curDiff < 0 && preDiff >= 0) {
			ans++
			preDiff = curDiff
		}
	}
	return
}