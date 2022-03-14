package problems

import "math"

func FindRestaurant(list1 []string, list2 []string) []string {
	mp := make(map[string]int)

	for i, r := range list1 {
		mp[r] = i
	}

	minIndex := math.MaxInt64
	ans := []string{}
	for i, r := range list2 {
		if j, ok := mp[r]; ok {
			if i+j < minIndex {
				minIndex = i + j
				ans = []string{r}
			} else if i+j == minIndex {
				ans = append(ans, r)
			}
		}
	}

	return ans
}
