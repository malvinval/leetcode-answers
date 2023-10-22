package main

import (
	"fmt"
	"strconv"
)

/*
	Given an integer n, return a string array answer (1-indexed) where:

	answer[i] == "FizzBuzz" if i is divisible by 3 and 5.
	answer[i] == "Fizz" if i is divisible by 3.
	answer[i] == "Buzz" if i is divisible by 5.
	answer[i] == i (as a string) if none of the above conditions are true.


	Example 1:

	Input: n = 3
	Output: ["1","2","Fizz"]

	Example 2:

	Input: n = 5
	Output: ["1","2","Fizz","4","Buzz"]

	Example 3:

	Input: n = 15
	Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
*/

// Note: Jangan gunakan slice untuk menampung datanya. Misal kita menggunakan slice, kita harus specify length dan capacity.
// Jika slice tidak ada nilai inisialisasi, maka otomatis diisi string kosong sebanyak kapasitas. Hal itu akan mempersulit
// proses appending data baru karena data baru diappend dengan kumpulan string kosong.

// Gunakan saja array biasa. Walaupun tidak ada nilai inisialisasi, tidak ada difill dengan data string kosong.
// Array tersebut akan benar-benar kosong sehingga proses appending berjalan baik.

func fizzBuzz(n int) []string {
	var arr []string

	for i := 1; i <= n; i++ {
		if i%3 == 0 && i%5 == 0 {
			arr = append(arr, "FizzBuzz")
		} else if i%3 == 0 {
			arr = append(arr, "Fizz")
		} else if i%5 == 0 {
			arr = append(arr, "Buzz")
		} else {
			arr = append(arr, strconv.Itoa(i))
		}
	}

	return arr
}

func main() {
	arr := fizzBuzz(5)

	for i := 0; i < len(arr); i++ {
		fmt.Println(arr[i])
	}
}
