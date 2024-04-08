func countStudents(students []int, sandwiches []int) int {
    cntS, cntC := 0,0
	for _, val := range students {
		if val == 1 {
			cntS++
		} else {
			cntC++
		}
	}

    for _,val := range sandwiches {
        if val == 0 && cntC == 0 {
            return cntS
        }
        
        if val == 1 && cntS == 0 {
            return cntC
        }
        
        if val == 0 {
            cntC--
        } else {
            cntS--
        }
    }
    return 0
}