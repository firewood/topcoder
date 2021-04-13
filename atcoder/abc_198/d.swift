import Foundation

extension Sequence {
    func permutations() -> [[Element]] {
        func _permutations<T>(of values: [T], indices: Range<Int>, result: inout [[T]]) {
            if indices.isEmpty {
                result.append(values)
                return
            }
            var values = values
            for i in indices {
                values.swapAt(indices.lowerBound, i)
                _permutations(of: values, indices: (indices.lowerBound + 1) ..< indices.upperBound, result: &result)
            }
        }

        var result: [[Element]] = []
        let values = Array(self)
        _permutations(of: values, indices: values.indices, result: &result)
        return result
    }
}

func solve(_ S:[String]) {
    let (S1, S2, S3) = (S[0], S[1], S[2])
    precondition(1 <= S1.count && S1.count <= 10)
    precondition(1 <= S2.count && S2.count <= 10)
    precondition(1 <= S3.count && S3.count <= 10)

    let existingAlphabets = Array(Set((S1 + S2 + S3).map { String($0) }))
    if existingAlphabets.count > 10 {
        print("UNSOLVABLE")
        return
    }
    var table = Array<String>(repeating: "", count: 128)
    var answer: [Int] = []
    for sequence in ["0", "1", "2", "3", "4", "5", "6", "7", "8", "9"].permutations() {
        for i in 0..<existingAlphabets.count {
            table[Int(existingAlphabets[i].first!.asciiValue!)] = sequence[i]
        }
        let s1String = S1.map { table[Int($0.asciiValue!)] }.joined()
        let s2String = S2.map { table[Int($0.asciiValue!)] }.joined()
        let s3String = S3.map { table[Int($0.asciiValue!)] }.joined()
        if s1String.prefix(1) == "0" || s2String.prefix(1) == "0" || s3String.prefix(1) == "0" {
            continue
        }
        let s1 = Int(s1String)!
        let s2 = Int(s2String)!
        let s3 = Int(s3String)!
        if s1 + s2 == s3 {
            answer = [s1, s2, s3]
            break
        }
    }
    if answer.isEmpty {
        print("UNSOLVABLE")
    } else {
        answer.forEach { print($0) }
    }
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
    var S = [String]()
	for _ in 0..<3 {
		S.append(nextToken())
	}
    solve(S);
}

#if REDIRECT
let testcase = 1
_ = freopen("in_\(testcase).txt", "r", stdin)
#endif

main()
