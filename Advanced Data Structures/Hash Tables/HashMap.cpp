/*
This code is based on hashing with separate chaining. Calculation in the hash
function is based on the ASCII code of the character in the key
*/

#include <iostream>
#include <list>

// K for key and V for value
template <typename K, typename V> class HashMap
{
private:
    // Define the structure of a key-value pair
    struct Entry
    {
        K key;
        V value;
    };
    /*
    Hash function to determine the index of a key in the table.
    In the provided hash function, the index calculation is based on the sum of
    the ASCII values of the characters in the key, followed by taking the
    modulus of the capacity of the hash table.
    */
    size_t hash(const K &key) const
    {
        size_t hashValue = 0;
        for (char c : key)
            // using the ASCII code for each character
            hashValue += c;

        // capacity is initialized by the constructor and set to 100.
        return hashValue % capacity;
    }

public:
    // Define the hash table as an array of linked lists
    // table is the name of the hash table
    // list table will be used for the separate chaining
    std::list<Entry> *table;
    // the number of buckets (linked lists) in the hash table.
    size_t capacity;
    // number of key-value pairs currently stored in the hash map.
    size_t size;
    // Constructor
    HashMap(size_t initialSize = 100)
        : table(new std::list<Entry>[initialSize]), capacity(initialSize),
          size(0)
    {}

    // Function to insert or update a key-value pair
    void put(const K &key, const V &value)
    {
        /*
        Get the hash index for the key (CALL THE HASH FUNCTION hash())
        for example, this will take thekey banana and get its
        index based on the hash function.
        */
        size_t index = hash(key);

        /*
        Iterate through the linked list at the hash index.
        auto keyword allows the compiler to determine automatically the
        type of a variable. Examples
            auto x = 10; Here, x will be deduced as int
            auto y = 3.14 Here, y will be deduced as double
        */
        for (auto &entry : table[index])
        {
            // If key already exists in the list
            if (entry.key == key)
            {
                // Update value if key already exists (avoid duplicate)
                entry.value = value;
                return; // exit the function
            }
        }
        // If key doesn't exist in the list at the hash index
        // Insert a new entry to the list
        table[index].push_back({key, value});
        size++; // Increment the size of the map
        // push_back is used to insert the entry
    }

    // Function to retrieve the value associated with a key
    V get(const K &key) const
    {
        // Get the hash index for the key (CALL THE HASH FUNCTION hash())
        size_t index = hash(key);
        // after getting the index
        for (const auto &entry : table[index])
        {
            if (entry.key == key)
            {
                return entry.value; // Return value if key exists
            }
        }
        throw std::out_of_range("Key not found");
    }

    // Function to remove a key - value pair from the map
    void erase(const K &key)
    {
        // Get the hash index for the key (CALL THE HASH FUNCTION hash())
        size_t index = hash(key);
        // Once the index is obtained, table[index] gives us access to the
        // linked list (std::list) at that index in the hash table.
        auto &entries = table[index];
        // Initialize iterator (it) to the starting point of the search inthe
        // linked list.
        auto it = entries.begin();
        // Iterate through the linked list
        // entries.end(): represents the end point of the search.
        while (it != entries.end())
        {
            // If key matches, erase the entry and decrement size
            if (it->key == key)
            {
                it = entries.erase(it);
                size--;
                return; // Exit the function after erasing the key
            }
            // Move to the next element
            ++it;
        }
    }
    // Function to check if the map is empty
    bool empty() const { return size == 0; }
    // Function to get the number of entries in the map
    size_t getSize() const { return size; }
};
