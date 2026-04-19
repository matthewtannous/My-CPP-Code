#include <iostream>

#include "HashMap.cpp"

int main()
{
    HashMap<std::string, int> myMap;
    myMap.put("apple", 10);
    myMap.put("banana", 20);
    myMap.put("orange", 30);
    myMap.put("lemon", 40);
    // Inserting a new entry with a key that collides with an key lemon
    // This will hash to the same index as "lemon"
    myMap.put("melon", 50); // uses separate chaining
    /*
    "lemon": ASCII values of characters : 'l' (108) + 'e' (101) + 'm'
    (109) + 'o' (111) + 'n' (110) = 539 With a hash table capacity of 100,
    539 % 100 = 39. Thus, "lemon" hashes to index 39.
    "melon" : ASCII values of characters : 'm' (109) + 'e' (101) + 'l'
    (108) + 'o' (111) + 'n' (110) = 539 (same as "lemon") With a hash
    table capacity of 100, 539 % 100 = 39. Thus, "melon" also hashes to
    index 39.
    this will display: Index 39: -> ("lemon", 40) -> ("melon", 50)
    */
    std::cout << "Size of the map: " << myMap.getSize() << std::endl;
    std::cout << "Value associated with 'banana': " << myMap.get("banana")
              << std::endl;
    myMap.erase("apple");
    std::cout << "Size of the map after erasing 'apple': " << myMap.getSize()
              << std::endl;
    // Displaying contents of all indices and show the linked list
    for (size_t i = 0; i < myMap.capacity; ++i)
    {
        std::cout << "Contents of the linked list at index " << i << ": ";
        auto entries = myMap.table[i];
        if (!entries.empty())
            for (const auto &entry : entries)
                std::cout << "(" << entry.key << ", " << entry.value << ") -> ";
        else
            std::cout << "Empty";

        std::cout << std::endl;
    }
    return 0;
}