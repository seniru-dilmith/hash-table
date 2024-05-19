
# Hash Table Implementation in C++

This repository contains an implementation of a hash table in C++ with linear and quadratic probing techniques. The implementation includes functionalities to insert, delete, search for elements, and dynamically resize the hash table when the load factor threshold is reached.

## Features

- **Hash Table with Linear Probing**
- **Hash Table with Quadratic Probing**
- **Dynamic Resizing** to maintain efficient operations
- **Insertion, Deletion, and Search** operations

## Getting Started

### Prerequisites

To compile and run this code, you need:

- A C++ compiler (like `g++`)

### Running the Code

1. **Clone the repository:**

    ```sh
    git clone https://github.com/your-username/hash-table-cpp.git
    cd hash-table-cpp
    ```

2. **Compile the code:**

    ```sh
    g++ main.cpp -o hashtable
    ```

3. **Run the executable:**

    ```sh
    ./hashtable
    ```

### Example Usage

The main program demonstrates the usage of the hash table with both linear and quadratic probing techniques. 

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <cmath>

// Include your HashTable class definition here...

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
    std::cout << "Linear Probing:
";
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
    std::cout << "Quadratic Probing:
";
    hashTableQuadratic.display();

    // Search for a key in the hash table
    std::cout << "Search key 2: " << hashTableQuadratic.search(2) << std::endl;

    // Delete a key from the hash table
    hashTableQuadratic.remove(2);

    // Display the contents of the hash table after deletion
    hashTableQuadratic.display();

    return 0;
}
```

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## Contact

If you have any questions, feel free to open an issue or contact me at [your-email@example.com].
