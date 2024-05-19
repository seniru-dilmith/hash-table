#include <iostream>
#include <vector>
#include <string>
#include <cmath>

// Define the initial size of the hash table
const int INITIAL_TABLE_SIZE = 10;
const float LOAD_FACTOR_THRESHOLD = 0.7;
const int TOMBSTONE = -1; // Special marker for deleted elements

enum ProbingType {
    LINEAR,
    QUADRATIC
};

// Define the HashTable class
class HashTable {
private:
    // The hash table is a vector of pairs, each containing a key and a value
    std::vector<std::pair<int, std::string>> table;
    // Count of elements in the hash table
    int elementCount;
    // Type of probing technique to use
    ProbingType probingType;

    // Hash function to compute the index for a given key
    int hashFunction(int key) {
        return key % table.size();
    }

    // Function to perform linear probing
    int linearProbe(int key, int attempt) {
        return (hashFunction(key) + attempt) % table.size();
    }

    // Function to perform quadratic probing
    int quadraticProbe(int key, int attempt) {
        return (hashFunction(key) + attempt * attempt) % table.size();
    }

    // Function to find the appropriate index using the selected probing technique
    int probe(int key, int attempt) {
        if (probingType == LINEAR) {
            return linearProbe(key, attempt);
        } else {
            return quadraticProbe(key, attempt);
        }
    }

    // Function to rehash the table when the load factor is too high
    void rehash() {
        // Save the old table
        std::vector<std::pair<int, std::string>> oldTable = table;
        // Double the size of the new table
        table.resize(table.size() * 2, std::make_pair(0, ""));
        // Reset element count
        elementCount = 0;

        // Reinsert all elements from the old table into the new table
        for (const auto &pair : oldTable) {
            if (pair.first != 0 && pair.first != TOMBSTONE) {
                insert(pair.first, pair.second);
            }
        }
    }

    // Function to check and maintain the load factor
    void checkLoadFactorAndRehash() {
        float loadFactor = static_cast<float>(elementCount) / table.size();
        if (loadFactor > LOAD_FACTOR_THRESHOLD) {
            rehash();
        }
    }

public:
    // Constructor to initialize the hash table with a given probing type
    HashTable(ProbingType type) : elementCount(0), probingType(type) {
        table.resize(INITIAL_TABLE_SIZE, std::make_pair(0, ""));
    }

    // Function to insert a key-value pair into the hash table
    void insert(int key, const std::string &value) {
        int attempt = 0;
        int index;

        // Find an empty or tombstone slot
        do {
            index = probe(key, attempt);
            if (table[index].first == 0 || table[index].first == TOMBSTONE) {
                table[index] = std::make_pair(key, value);
                ++elementCount;
                checkLoadFactorAndRehash();
                return;
            }
            ++attempt;
        } while (attempt < table.size());

        // If we exit the loop, it means the table is full (shouldn't happen if rehash works correctly)
        std::cerr << "Hash table is full. Rehashing did not work as expected." << std::endl;
    }

    // Function to delete a key-value pair from the hash table
    void remove(int key) {
        int attempt = 0;
        int index;

        // Find the slot with the given key
        do {
            index = probe(key, attempt);
            if (table[index].first == key) {
                table[index].first = TOMBSTONE;
                --elementCount;
                return;
            }
            if (table[index].first == 0) break;
            ++attempt;
        } while (attempt < table.size());

        std::cout << "Key not found\n";
    }

    // Function to search for a value by key in the hash table
    std::string search(int key) {
        int attempt = 0;
        int index;

        // Find the slot with the given key
        do {
            index = probe(key, attempt);
            if (table[index].first == key) {
                return table[index].second;
            }
            if (table[index].first == 0) break;
            ++attempt;
        } while (attempt < table.size());

        return "Key not found";
    }

    // Function to display the contents of the hash table
    void display() {
        // Iterate over each index in the table
        for (int i = 0; i < table.size(); ++i) {
            if (table[i].first != 0 && table[i].first != TOMBSTONE) {
                std::cout << "Index " << i << ": [" << table[i].first << ", " << table[i].second << "]\n";
            } else {
                std::cout << "Index " << i << ": [ ]\n";
            }
        }
    }
};

int main() {
    // Create a hash table with linear probing
    HashTable hashTableLinear(LINEAR);

    // Insert some key-value pairs into the hash table
    hashTableLinear.insert(1, "one");
    hashTableLinear.insert(2, "two");
    hashTableLinear.insert(42, "forty-two");
    hashTableLinear.insert(4, "four");
    hashTableLinear.insert(5, "five");
    hashTableLinear.insert(15, "fifteen");
    hashTableLinear.insert(25, "twenty-five");
    hashTableLinear.insert(35, "thirty-five");

    // Display the contents of the hash table
    std::cout << "Linear Probing:\n";
    hashTableLinear.display();

    // Search for a key in the hash table
    std::cout << "Search key 2: " << hashTableLinear.search(2) << std::endl;

    // Delete a key from the hash table
    hashTableLinear.remove(2);

    // Display the contents of the hash table after deletion
    hashTableLinear.display();

    // Create a hash table with quadratic probing
    HashTable hashTableQuadratic(QUADRATIC);

    // Insert some key-value pairs into the hash table
    hashTableQuadratic.insert(1, "one");
    hashTableQuadratic.insert(2, "two");
    hashTableQuadratic.insert(42, "forty-two");
    hashTableQuadratic.insert(4, "four");
    hashTableQuadratic.insert(5, "five");
    hashTableQuadratic.insert(15, "fifteen");
    hashTableQuadratic.insert(25, "twenty-five");
    hashTableQuadratic.insert(35, "thirty-five");

    // Display the contents of the hash table
    std::cout << "Quadratic Probing:\n";
    hashTableQuadratic.display();

    // Search for a key in the hash table
    std::cout << "Search key 2: " << hashTableQuadratic.search(2) << std::endl;

    // Delete a key from the hash table
    hashTableQuadratic.remove(2);

    // Display the contents of the hash table after deletion
    hashTableQuadratic.display();

    return 0;
}
