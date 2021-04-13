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

func solve(_ S:[String]) -> [Int] {
    let uniqueCharacters = Set(S[0] + S[1] + S[2])
    if uniqueCharacters.count > 10 {
        return []
    }
    let sequences = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
    let table = Dictionary(uniqueKeysWithValues: zip(uniqueCharacters, sequences))
    let S1 = S[0].map { table[$0]! }
    let S2 = S[1].map { table[$0]! }
    let S3 = S[2].map { table[$0]! }
    for sequences in sequences.permutations() {
        if sequences[S1[0]] == 0 || sequences[S2[0]] == 0 || sequences[S3[0]] == 0 {
            continue
        }
        let n1 = S1.reduce(0) { $0 * 10 + sequences[$1] }
        let n2 = S2.reduce(0) { $0 * 10 + sequences[$1] }
        let n3 = S3.reduce(0) { $0 * 10 + sequences[$1] }
        if n1 + n2 == n3 {
            return [n1, n2, n3]
        }
    }
    return []
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
    let answer = solve(S)
    if answer.isEmpty {
        print("UNSOLVABLE")
    } else {
        answer.forEach { print($0) }
    }
}

#if REDIRECT
let testcase = 5
_ = freopen("in_\(testcase).txt", "r", stdin)
#endif

main()
