package problems

import (
	"sort"
)

// words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]

func LongestWord(words []string) string {
	sort.Slice(words, func(i, j int) bool {
		return len(words[i]) < len(words[j]) || (len(words[i]) == len(words[j]) && words[i] > words[j])
	})
	letters := map[string]int{"": 1}
	ans := ""
	for _, word := range words {
		if _, ok := letters[word[:len(word)-1]]; ok {
			ans = word
			letters[word]++
		}
	}
	return ans
}