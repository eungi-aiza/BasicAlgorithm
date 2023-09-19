#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

const int TABLE_SIZE = 1000;

class HashMap {
    struct Node {
        std::string key;
        int value;
        Node(const std::string& k, int v) : key(k), value(v) {}
    };

    std::vector<std::vector<Node>> table;

    int hashFunc(const std::string& key) const {
        int sum = 0;
        for (char c : key) {
            sum += c;
        }
        return sum % TABLE_SIZE;
    }

public:
    HashMap() {
        table.resize(TABLE_SIZE);
    }

    void insert(const std::string& key, int value) {
        int hashValue = hashFunc(key);
        table[hashValue].emplace_back(key, value);
    }

    bool get(const std::string& key, int& value) const {
        int hashValue = hashFunc(key);
        for (const auto& node : table[hashValue]) {
            if (node.key == key) {
                value = node.value;
                return true;
            }
        }
        return false;
    }

    void remove(const std::string& key) {
        int hashValue = hashFunc(key);
        table[hashValue].erase(
            std::remove_if(table[hashValue].begin(), table[hashValue].end(),
                [&key](const Node& node) { return node.key == key; }),
            table[hashValue].end()
        );
    }
};

int main() {
    HashMap map;
    map.insert("one", 1);
    map.insert("two", 2);
    map.insert("three", 5);
    int value;
    if (map.get("one", value)) {
        std::cout << "one: " << value << std::endl;
    }
    map.remove("one");
    if (!map.get("one", value)) {
        std::cout << "one not found" << std::endl;
    }
    return 0;
}