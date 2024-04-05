func check(a, b int8) bool {
	x := a - b
	if x < 0 {
		x *= -1
	}
	return x == 32
}

func makeGood(s string) string {
	stack := make([]byte, 0, len(s))

	for i := 0; i < len(s); i++ {
		if len(stack) > 0 && check(int8(stack[len(stack)-1]), int8(s[i])) {
			stack = stack[:len(stack)-1]
		} else {
			stack = append(stack, s[i])
		}
	}
	return string(stack)
}