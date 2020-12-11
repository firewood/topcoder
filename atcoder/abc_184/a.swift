import Foundation

func solve(_ a:Int, _ b:Int, _ c:Int, _ d:Int) {
    let ans = a * d - b * c
    print(ans)
}

func main() {
    var tokenIndex = 0
    var tokenBuffer = [String]()
    func nextToken() -> String {
        if tokenIndex >= tokenBuffer.count {
            tokenIndex = 0
            tokenBuffer = readLine()!.split(separator: " ").map { String($0) }
        }
        tokenIndex += 1
        return tokenBuffer[tokenIndex - 1]
    }
    let a = Int(nextToken())!
    let b = Int(nextToken())!
    let c = Int(nextToken())!
    let d = Int(nextToken())!
    solve(a, b, c, d)
}

#if DEBUG
let caseNumber = 1
_ = freopen("in_\(caseNumber).txt", "r", stdin)
#endif

main()
