# Hash Table Implementation in C++

This repository contains an implementation of a hash table in C++ that supports open addressing with both linear probing and quadratic probing techniques for collision resolution. It also includes dynamic resizing based on a load factor to maintain efficient performance.

## Features

- **Open Addressing**: Uses both linear probing and quadratic probing for collision resolution.
- **Dynamic Resizing**: Automatically resizes the table when the load factor exceeds a predefined threshold.
- **Basic Operations**: Supports insertion, deletion, and search operations.
- **Load Factor Management**: Ensures efficient performance by maintaining an optimal load factor.

## Hash Table Class Overview

### Data Members

- `table`: A vector of pairs to store key-value pairs directly.
- `elementCount`: Tracks the number of elements in the table.
- `probingType`: Determines whether to use linear probing or quadratic probing.

### Methods

- **Private Methods**:
  - `hashFunction(int key)`: Computes the index for a given key.
  - `linearProbe(int key, int attempt)`: Computes the index using linear probing.
  - `quadraticProbe(int key, int attempt)`: Computes the index using quadratic probing.
  - `probe(int key, int attempt)`: Uses the selected probing method to compute the index.
  - `rehash()`: Resizes the table and reinserts all elements.
  - `checkLoadFactorAndRehash()`: Checks the load factor and triggers rehashing if necessary.

- **Public Methods**:
  - `HashTable(ProbingType type)`: Constructor initializes the table and sets the probing type.
  - `insert(int key, const std::string &value)`: Inserts a key-value pair and handles collisions using the selected probing method.
  - `remove(int key)`: Marks the key as deleted using a tombstone.
  - `search(int key)`: Searches for a key using the selected probing method.
  - `display()`: Prints the contents of the hash table.
