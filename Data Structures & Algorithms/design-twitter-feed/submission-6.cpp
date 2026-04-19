// Goal:
// Space -> O((N * m) + (N * M) + n)
// n -> number of followeeIds associated with the userId
// m -> max # of tweets by any user
// N -> total number of userIds
// M -> max # of followees for any user.

class Twitter {
private:
    int timeStamp = 0;
    unordered_map<int, vector<pair<int, int>>> user_tweets;
    // userId -> all ids that the user follows
    unordered_map<int, unordered_set<int>> user_follows;
public:
    Twitter() {}
    
    // O(1)
    void postTweet(int userId, int tweetId) {
        this->user_tweets[userId].push_back({timeStamp++, tweetId});
    }

    // O(nlogn)
    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        const auto& followee_list = this->user_follows[userId];
        int followee_cnt = followee_list.size();

        unordered_set<int> contributer_list;

        if (followee_cnt > 10) {
            priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> latest_10;
            for (int followee: followee_list) {
                const auto& followee_tweets = this->user_tweets[followee];
                if (followee_tweets.size()) {
                    latest_10.push(followee_tweets.back());
                }

                if (latest_10.size() >= 10) latest_10.pop();
            }

            for (int followee: followee_list) {
                const auto& followee_tweets = this->user_tweets[followee];
                if (followee_tweets.size() && followee_tweets.back().first < latest_10.top().first) continue;
                contributer_list.insert(followee);
            }
        } else {
            contributer_list = followee_list;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

        for (int followee: contributer_list) {
            if (followee == userId) continue;
            const auto& followee_tweets = this->user_tweets[followee];
            for (int i = followee_tweets.size() - 1; i >= 0 && (followee_tweets.size() - 1 - i < 10); --i) {
                pq.push(followee_tweets[i]);
            }
        }

        // user's own tweets
        const auto& user_own_tweets = this->user_tweets[userId];
        for (int i = user_own_tweets.size() - 1; i >= 0 && (user_own_tweets.size() - 1 - i < 10); --i) {
            pq.push(user_own_tweets[i]);
        }

        for (int i = 0; (i < 10) && pq.size(); ++i) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        return res;
    }
    
    // O(1)
    void follow(int followerId, int followeeId) {
        this->user_follows[followerId].insert(followeeId);
    }
    
    // O(1)
    void unfollow(int followerId, int followeeId) {
        this->user_follows[followerId].erase(followeeId);
    }
};
