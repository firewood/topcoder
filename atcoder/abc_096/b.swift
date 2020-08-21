import Foundation

main()

func main() {
    let abc = readLine()!.split(separator: " ").map { Int($0)! }
    let k = Double(readLine()!)!
    let sorted = abc.sorted()
    let ans = sorted.reduce(sorted.last! * (Int(pow(2.0, k)) - 1), +)
    print(ans)
}
