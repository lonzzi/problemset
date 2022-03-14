package exercise

func FindLUSlength(a string, b string) int {
    if a == b {
		return -1;
	} else {
		return max(len(a), len(b))
	}
}

func max(a, b int) int {
	if a > b {
		return a
	} else {
		return b
	}
}