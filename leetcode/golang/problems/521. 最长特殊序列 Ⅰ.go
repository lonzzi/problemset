package problems

func FindLUSlength(a string, b string) int {
    if a == b {
		return -1;
	} else {
		return max(len(a), len(b))
	}
}