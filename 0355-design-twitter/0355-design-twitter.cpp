class Twitter {
private:
    unordered_map<int, unordered_set<int>> followMap;
    unordered_map<int, vector<pair<int,int>>> tweetMap;
    int time;

public:
    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        // Ensure self-follow
        followMap[userId].insert(userId);

        // Increment global timestamp
        time++;

        // Store (time, tweetId)
        tweetMap[userId].push_back({time, tweetId});
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followerId != followeeId) {
            followMap[followerId].erase(followeeId);
        }
    }

    vector<int> getNewsFeed(int userId) {

        vector<int> result;

        // Max heap:
        // (time, tweetId, userId, index)
        priority_queue<tuple<int,int,int,int>> pq;

        // Push latest tweet from each followee
        for (auto followee : followMap[userId]) {

            if (!tweetMap[followee].empty()) {

                int idx = tweetMap[followee].size() - 1;

                auto [timeStamp, tweetId] = tweetMap[followee][idx];

                pq.push({timeStamp, tweetId, followee, idx});
            }
        }

        // Extract up to 10 most recent tweets
        while (!pq.empty() && result.size() < 10) {

            auto [timeStamp, tweetId, user, idx] = pq.top();
            pq.pop();

            result.push_back(tweetId);

            // Push previous tweet from same user
            if (idx > 0) {

                auto [newTime, newTweetId] = tweetMap[user][idx - 1];

                pq.push({newTime, newTweetId, user, idx - 1});
            }
        }

        return result;
    }
};