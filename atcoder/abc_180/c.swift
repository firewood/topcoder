import Foundation

main()

func main() {
    let n = Int(readLine()!)!
    var results = [Int]()
    var i = 1
    while i * i <= n {
        if (n % i == 0) {
            results.append(i)
            if (i != n / i) {
                results.append(n / i)
            }
        }
        i = i + 1
    }
    results.sort()
    results.forEach {
        print($0)
    }
}
