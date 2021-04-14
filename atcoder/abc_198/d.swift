import Foundation

struct PermutationSequence<Element: Comparable>: Sequence, IteratorProtocol {
    private var nextElements: [Element]?

    init<Elements: Sequence>(elements: Elements) where Elements.Element == Element {
        self.nextElements = Array(elements)
    }

    mutating func next() -> [Element]? {
        defer {
            if let elements = nextElements {
                var i = elements.count - 2
                while i >= 0, elements[i] >= elements[i + 1] {
                    i -= 1
                }
                if i < 0 {
                    nextElements = nil
                } else {
                    var j = elements.count - 1
                    while elements[i] >= elements[j] {
                        j -= 1
                    }
                    nextElements!.swapAt(i, j)
                    nextElements![(i + 1)...].reverse()
                }
            }
        }
        return nextElements
    }
}

extension Sequence where Element: Comparable {
    var permutations: PermutationSequence<Element> {
        PermutationSequence(elements: self)
    }
}

func solve(_ S:[String]) -> [Int] {
    let uniqueCharacters = Set(S.joined())
    if uniqueCharacters.count > 10 {
        return []
    }
    let digits = 0 ..< 10
    let characterToIndex = Dictionary(uniqueKeysWithValues: zip(uniqueCharacters, digits))
    let indices = S.map { $0.map { characterToIndex[$0]! } }
    for sequences in digits.permutations {
        guard indices.allSatisfy({ sequences[$0[0]] != 0 }) else {
            continue
        }
        let numbers = indices.map { $0.reduce(0) { $0 * 10 + sequences[$1] } }
        if numbers[0] + numbers[1] == numbers[2] {
            return numbers
        }
    }
    return []
}

func main() {
    var tokenIndex = 0, tokenBuffer = [String]()
    func readString() -> String {
        if tokenIndex >= tokenBuffer.count {
            tokenIndex = 0
            tokenBuffer = readLine()!.split(separator: " ").map { String($0) }
        }
        defer { tokenIndex += 1 }
        return tokenBuffer[tokenIndex]
    }
    func readInt() -> Int { Int(readString())! }
    func readDouble() -> Double { Double(readString())! }
    var S = [String]()
    for _ in 0..<3 {
        S.append(readString())
    }
    let answer = solve(S)
    if answer.isEmpty {
        print("UNSOLVABLE")
    } else {
        answer.forEach { print($0) }
    }
}

#if DEBUG
let caseNumber = 1
_ = freopen("in_\(caseNumber).txt", "r", stdin)
#endif

main()
