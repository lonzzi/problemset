package problems

func TrailingZeroes(n int) (ans int) {
	for n >= 5 {
        ans += n / 5
        n /= 5
	}
	return
}