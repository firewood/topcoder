// Google Code Jam 2017 Qualification Round
// Problem B. Tidy Numbers

func readInt() -> Int {
  return Int(readLine() ?? "") ?? 0
}

func solve(n: Int) -> Int {
  var d = 1, r = n
  while (d <= r) {
    let a = (r / d) % 10, b = (r / d / 10) % 10
    if (a < b) {
      let c = r - (r % (d * 10))
      r = c - 1
    }
    d *= 10
  }
  return r
}

let T = readInt()
for t in 1...T {
  let ans = solve(n: readInt())
  print("Case #\(t): \(ans)")
}
