import Foundation
prefix operator *
prefix func * <T> (a: [T]) -> (T, T) {return (a[0], a[1])}
prefix func * <T> (a: [T]) -> (T, T, T) {return (a[0], a[1], a[2])}

#if DEBUG
print("DEBUG")
_ = freopen("in_a.txt", "r", stdin)
#endif

let (a, b, c) = *readLine()!.split(separator: " ").map({Int($0)!}).sorted()
let ans = a == b ? c : a
print("\(ans)")
