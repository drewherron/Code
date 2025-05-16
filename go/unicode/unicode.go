package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

// Convert a byte to a string of bits
func byteToBits(b byte) string {
	bits := ""
	for i := 7; i >= 0; i-- {
		if (b & (1 << i)) != 0 {
			bits += "1"
		} else {
			bits += "0"
		}
	}
	return bits
}

func main() {
	scanner := bufio.NewScanner(os.Stdin)

	for {
		// Print prompt
		fmt.Print("> ")

		// Read input
		scanner.Scan()
		input := scanner.Text()

		// Check for exit command
		if strings.ToLower(input) == "x" {
			break
		}

		// Convert string to bits and print
		var bitsOutput strings.Builder
		for i, b := range []byte(input) {
			bitsOutput.WriteString(byteToBits(b))

			// Add space after every 8 bits for legibility
			if i < len(input)-1 {
				bitsOutput.WriteString(" ")
			}
		}

		fmt.Println(bitsOutput.String())
	}
}
