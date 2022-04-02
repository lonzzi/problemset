package problems

func a() {
	for i := 0; i < 10; i++ {
		temp := i
		go func() {
			println(temp)
		}()
	}
}
