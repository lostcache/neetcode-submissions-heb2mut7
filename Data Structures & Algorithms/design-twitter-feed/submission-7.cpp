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

    using Entry = tuple<int, int, int, int>; // {timestamp, tweet_id, user_id, tweet_idx}

public:
    Twitter() {}

    // O(1)
    void postTweet(int userId, int tweetId) {
        this->user_tweets[userId].push_back({timeStamp++, tweetId});
    }

    // O(n log n)
    vector<int> getNewsFeed(int userId) {
        vector<int> res;

        const auto& followee_list = this->user_follows[userId];
        int followee_cnt = followee_list.size();

        // max-heap for merge: pop most recent tweet first
        priority_queue<Entry> latest_tweets;

        auto push_user = [&](int uid) {
            const auto& tweets = this->user_tweets[uid];
            if (tweets.empty()) return;
            int idx = tweets.size() - 1;
            latest_tweets.push({tweets[idx].first, tweets[idx].second, uid, idx});
        };

        if (followee_cnt > 10) {
            // min-heap to keep top-10 most recent entry points across followees
            priority_queue<Entry, vector<Entry>, greater<Entry>> top10;
            for (int followee: followee_list) {
                if (followee == userId) continue;
                const auto& tweets = this->user_tweets[followee];
                if (tweets.empty()) continue;
                top10.push({tweets.back().first, tweets.back().second, followee, (int)tweets.size() - 1});
                if (top10.size() > 10) top10.pop();
            }
            while (!top10.empty()) {
                latest_tweets.push(top10.top());
                top10.pop();
            }
        } else {
            for (int followee: followee_list) {
                if (followee == userId) continue;
                push_user(followee);
            }
        }

        // own tweets
        push_user(userId);

        while (res.size() < 10 && !latest_tweets.empty()) {
            auto [timestamp, tweet_id, uid, tweet_idx] = latest_tweets.top();
            latest_tweets.pop();
            res.push_back(tweet_id);
            if (tweet_idx - 1 >= 0) {
                const auto& [prev_ts, prev_tid] = this->user_tweets[uid][tweet_idx - 1];
                latest_tweets.push({prev_ts, prev_tid, uid, tweet_idx - 1});
            }
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