#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Twitter
{

  public:
    Twitter() {}

    void postTweet(int userId, int tweetId)
    {
        // Insert at end
        tweets.emplace_back(userId, tweetId);
    }

    vector<int> getNewsFeed(int userId)
    {
        vector<int> tweetIds;

        for (int i = tweets.size() - 1, count = 0; i >= 0 && count < 10; i--)
        {
            if (tweets[i].first == userId ||
                following[userId].contains(tweets[i].first))
            {
                tweetIds.emplace_back(tweets[i].second);
                count++;
            }
        }
        return tweetIds;
    }

    void follow(int followerId, int followeeId)
    {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        following[followerId].erase(followeeId);
    }

  private:
    unordered_map<int, unordered_set<int>> following;
    vector<pair<int, int>> tweets;
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */