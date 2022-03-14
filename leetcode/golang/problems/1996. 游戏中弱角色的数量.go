package problems

import "sort"

func NumberOfWeakCharacters(properties [][]int) (ans int) {
	sort.Slice(properties, func(i, j int) bool {
		if properties[i][0] == properties[j][0] {
			return properties[i][1] < properties[j][1]
		}
		return properties[i][0] > properties[j][0]
	})
	maxDef := 0
	for _, array := range properties {
		if array[1] < maxDef {
			ans++
		} else {
			maxDef = array[1]
		}
	}
	return
}