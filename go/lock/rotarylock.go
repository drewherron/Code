package main

import "fmt"

//import "math"

//func getMinCodeEntryTime(N int32, M int32, C []int32) int64 {
//
//    // Seconds from 1 to first value
//    var seconds int64 = int64(math.Min(
//            float64(int32(math.Abs(float64(1 - C[0])))),
//            float64(N - int32(math.Abs(float64(1 - C[0]))))))
//        fmt.Printf("seconds: %v\n", seconds)
//
//    // Loop for the rest of the lock
//    for i := 0; i < (len(C) - 1); i++ {
//        distance := int32(math.Abs(float64(C[i+1] - C[i])))
//        seconds += int64(math.Min(
//            float64(distance),
//            float64(N - distance)))
//        fmt.Printf("seconds: %v\n", seconds)
//	  }
//	  return seconds
//}

func getMinCodeEntryTime(N int32, M int32, C []int32) int64 {
  // Seconds from 1 to first value
  var seconds int32 = getDialDistance(1, C[0], N)

  // Loop for the rest of the lock
  for i := 0; i < (len(C) - 1); i++ {
    seconds += getDialDistance(C[i], C[i+1], N)
    }
    return int64(seconds)
}

func getDialDistance(a int32, b int32, N int32) int32 {
  diff := a - b
  if diff < 0 {
    diff = -diff
  }
  if diff > N - diff {
    return N - diff
  }
  return diff
}

// func getDialDistance(a int32, b int32, N int32) int32 {
//     return int32(math.Min(
//             float64(int32(math.Abs(float64(a - b)))),
//             float64(N - int32(math.Abs(float64(a - b)))))
//     )
// }

func main() {
    var N int32 = 10
    var M int32 = 4
    var C []int32 = []int32{9, 4, 4, 8}
    var result int64 = getMinCodeEntryTime(N, M, C)
    fmt.Println(result)
}
