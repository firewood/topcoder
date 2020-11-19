import Foundation

main()

func main() {
    let n = readLine()!
    let sum = n.reduce(0) { $0 + Int(String($1))! }
    let ans = sum % 9 == 0 ? "Yes" : "No"
    print(ans)
}
