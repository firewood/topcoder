import Foundation

main()

func main() {
    guard let s = readLine() else {
        return
    }
    let ans = s.components(separatedBy: "S").map { $0.count }.max()
    print(ans!)
}
