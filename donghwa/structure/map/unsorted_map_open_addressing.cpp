#include <iostream>
#include <string>
#include <vector>

const int TABLE_SIZE = 1000;

class HashMap {
    struct Node {
        std::string key;
        int value;
        bool deleted;
        Node(const std::string& k, int v) : key(k), value(v), deleted(false) {}
    };

    std::vector<Node*> table;

    int hashFunc(const std::string& key, int attempt) const {
        int sum = 0;
        for (char c : key) {
            sum += c;
        }
        return (sum + attempt) % TABLE_SIZE;
    }

public:
    HashMap() : table(TABLE_SIZE, nullptr) {}

    void insert(const std::string& key, int value) {
        int attempt = 0;
        while (true) {
            int idx = hashFunc(key, attempt);
            if (!table[idx] || table[idx]->deleted) {
                table[idx] = new Node(key, value);
                return;
            }
            attempt++;
        }
    }

    bool get(const std::string& key, int& value) const {
        int attempt = 0;
        while (true) {
            int idx = hashFunc(key, attempt);
            if (!table[idx]) return false;
            if (table[idx]->key == key && !table[idx]->deleted) {
                value = table[idx]->value;
                return true;
            }
            attempt++;
        }
    }

    void remove(const std::string& key) {
        int attempt = 0;
        while (true) {
            int idx = hashFunc(key, attempt);
            if (!table[idx]) return;
            if (table[idx]->key == key && !table[idx]->deleted) {
                table[idx]->deleted = true;
                return;
            }
            attempt++;
        }
    }
};

int main() {
    HashMap map;
    map.insert("one", 1);
    map.insert("two", 2);
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