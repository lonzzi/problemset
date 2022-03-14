package problems

import (
	"strings"
	"unicode"
)

func isValid(s string) bool {
	hasHypens := false
	for i, ch := range s {
		if  i < len(s)-1 && unicode.IsDigit(ch) || strings.ContainsRune("!,.", ch) {
			return false
		}
		if ch == '-' {
			if i == 0 || i == len(s)-1 || hasHypens || !unicode.IsLower(rune(s[i-1])) || !unicode.IsLower(rune(s[i+1])) {
				return false
			}
			hasHypens = true
		}
	}
	return true
}

func CountValidWords(sentence string) (ans int) {
	string_slice := strings.Fields(sentence)
	for _, s := range string_slice {
		if isValid(s) {
			ans++
		}
	}
	return
}