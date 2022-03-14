package problems

import "sort"

func FindContentChildren(g []int, s []int) (ans int) {
	sort.Ints(g)
	sort.Ints(s)

	p, q := 0, 0

	for i := 0; p < len(g) && q < len(s); i++ {
		if g[p] <= s[q] {
			ans++; p++; q++
		} else {
			q++
		}
	}

	return
}