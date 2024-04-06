func minRemoveToMakeValid(s string) string {
	stack := []int{}
	vis := make([]bool, len(s))
	for i := 0; i < len(s); i++ {
		if s[i] == '(' {
			stack = append(stack, i)
		} else if s[i] == ')' {
			if len(stack) > 0 {
				stack = stack[:len(stack)-1]
			} else {
				vis[i] = true
			}
		}
	}

	for len(stack) > 0 {
		vis[stack[len(stack)-1]] = true
		stack = stack[0 : len(stack)-1]
	}

	res := []byte{}
	for i := 0; i < len(s); i++ {
		if !vis[i] {
			res = append(res, s[i])
		}
	}
	return string(res)
}