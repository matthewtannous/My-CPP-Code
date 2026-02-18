#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

using namespace std;
class FoodRatings
{
  public:
    FoodRatings(vector<string> &foods, vector<string> &cuisines,
                vector<int> &ratings)
    {
        for (int i = 0, s = foods.size(); i < s; i++)
        {
            food_info[foods[i]] = {ratings[i], cuisines[i]};
            foods_by_cuisine[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    }

    void changeRating(string food, int newRating)
    {
        string cuisine = food_info[food].second;
        int oldRating = food_info[food].first;

        foods_by_cuisine[cuisine].erase({-oldRating, food});
        foods_by_cuisine[cuisine].insert({-newRating, food});

        food_info[food].first = newRating;
    }

    string highestRated(string cuisine)
    {
        return foods_by_cuisine[cuisine].begin()->second;
    }

  private:
    unordered_map<string, pair<int, string>> food_info;
    unordered_map<string, set<pair<int, string>>> foods_by_cuisine;
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */