#include <iostream>
#include <map>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;

class MovieRentingSystem
{
  private:
    // Access to 5 cheapest, have movie be the key
    map<int, set<pair<int, int>>>
        available_movies; // key: movie , pair.1 = price,, pair.2 = shop

    // Access to each shop, Have shop be the key
    map<pair<int, int>, int>
        movie_price; // key.1: shop , key.2 = movie, int= price

    // Access all rented movies in order, put them in a set
    set<tuple<int, int, int>> rented; // price, shop, movie

  public:
    MovieRentingSystem(int n, vector<vector<int>> &entries)
    {
        int movie, shop, price;
        for (auto entry : entries)
        {
            price = entry[2];
            movie = entry[1];
            shop = entry[0];

            available_movies[movie].insert({price, shop});

            movie_price[{shop, movie}] = price;
        }
    }

    vector<int> search(int movie)
    {
        int i = 0;
        vector<int> movies;
        for (auto entry : available_movies[movie])
        {
            if (i == 5)
                break;

            movies.push_back(entry.second);
            i++;
        }
        return movies;
    }

    void rent(int shop, int movie)
    {
        int price = movie_price[{shop, movie}];

        rented.insert({price, shop, movie});

        available_movies[movie].erase({price, shop});
    }

    void drop(int shop, int movie)
    {
        int price = movie_price[{shop, movie}];

        rented.erase({price, shop, movie});

        available_movies[movie].insert({price, shop});
    }

    vector<vector<int>> report()
    {
        vector<vector<int>> res;
        int count = 0;
        for (auto entry : rented)
        {
            if (count++ == 5)
                break;

            res.push_back({get<1>(entry), get<2>(entry)});
        }

        return res;
    }
};

/**
 * Your MovieRentingSystem object will be instantiated and called as such:
 * MovieRentingSystem* obj = new MovieRentingSystem(n, entries);
 * vector<int> param_1 = obj->search(movie);
 * obj->rent(shop,movie);
 * obj->drop(shop,movie);
 * vector<vector<int>> param_4 = obj->report();
 */