package problems

import (
	"sort"
)

func CanReorderDoubled(arr []int) bool {
	sort.Slice(arr, func(i, j int) bool {
		return abs(arr[i]) < abs(arr[j])
	})
	cnt := map[int]int{}
	for _, v := range arr {
		cnt[v]++
	}
	if cnt[0] % 2 != 0 {
		return false
	}
	for _, v := range arr {
		if _, ok := cnt[2*v]; ok && cnt[v] != 0 {
			cnt[v]--; cnt[2*v]--
		}
	}
	for _, v :=range cnt {
		if v != 0 {
			return false
		}
	}

	return true
}

func abs(i int) int {
	if i < 0 {
		return -i
	}
	return i
}