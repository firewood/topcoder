import Foundation

private final class LinkedList<T> {
    class Node {
        var prev: Node!
        var next: Node!
        var value: T?

        init() {
            prev = self
            next = self
        }
    }

    private var top: Node! = Node()

    init() {}

    func append(_ node: Node) {
        node.prev = top.prev
        node.next = top
        top.prev.next = node
        top.prev = node
    }

    func remove(_ node: Node) {
        node.prev.next = node.next
        node.next.prev = node.prev
    }

    func getOldestNode() -> Node? {
        return top.next
    }

    #if DEBUG
        func dumpAllNodes() {
            print("Stored nodes:")
            var node = getOldestNode()
            while let value = node?.value {
                print("  value: \(value)")
                node = node?.next
            }
        }
    #endif
}

public class LRUCache<Key, Value> where Key: Hashable {
    var capacity: Int! = 100
    private typealias KeyValueList = LinkedList<(key: Key, value: Value)>
    private var nodeList = KeyValueList()
    private var nodeMap = [Key: KeyValueList.Node]()

    public init(capacity: Int) {
        self.capacity = capacity
    }

    private func append(key: Key, value: Value) {
        let node = KeyValueList.Node()
        node.value = (key: key, value: value)
        nodeList.append(node)
        nodeMap[key] = node
    }

    public func set(key: Key, value: Value) {
        if get(key) != nil {
            return
        }
        if nodeMap.count >= capacity, let node = nodeList.getOldestNode() {
            nodeList.remove(node)
            nodeMap.removeValue(forKey: node.value!.key)
        }
        append(key: key, value: value)
    }

    public func get(_ key: Key) -> Value? {
        guard let node = nodeMap[key] else {
            return nil
        }
        nodeList.remove(node)
        nodeList.append(node)
        return node.value?.value
    }

    #if DEBUG
        public func dump() {
            nodeList.dumpAllNodes()
        }
    #endif
}
