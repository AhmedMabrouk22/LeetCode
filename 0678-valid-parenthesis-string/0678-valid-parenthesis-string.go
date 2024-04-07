func checkValidString(s string) bool {

	a := []int{}
	b := []int{}

	for i := 0; i < len(s); i++ {
		if s[i] == '*' {
			a = append(a, i)
		} else if s[i] == '(' {
			b = append(b, i)
		} else if s[i] == ')' {
			if len(b) > 0 {
				b = b[:len(b)-1]
			} else if len(a) > 0 {
				a = a[:len(a)-1]
			} else {
				return false
			}
		}

	}

	for len(b) > 0 && len(a) >= len(b) {
		if a[len(a)-1] > b[len(b)-1] {
			a = a[:len(a)-1]
			b = b[:len(b)-1]
		} else {
			return false
		}
	}

	return len(a) >= len(b)
}