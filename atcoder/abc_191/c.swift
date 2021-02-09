import Foundation

func solve(_ H:Int, _ W:Int, _ S:[[Character]]) -> Int {
    var ans = 0
    var f = false
    for i in 1..<H {
        for j in 0..<W {
            if !f && S[i - 1][j] != S[i][j] {
                f = true
                ans += 1
            }
            if S[i - 1][j] == S[i][j] {
                f = false
            }
        }
    }
    f = false
    for j in 1..<W {
        for i in 0..<H {
            if !f && S[i][j - 1] != S[i][j] {
                f = true
                ans += 1
            }
            if S[i][j - 1] == S[i][j] {
                f = false
            }
        }
    }
    return ans
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
    let H = Int(nextToken())!, W = Int(nextToken())!
    var S = [[Character]]()
    for _ in 0..<H {
        S.append(Array(nextToken()))
    }
    print(solve(H, W, S))
}

#if DEBUG
let caseNumber = 1
_ = freopen("in_\(caseNumber).txt", "r", stdin)
#endif

main()
