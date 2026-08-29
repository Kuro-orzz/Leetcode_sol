struct cmp {
    bool operator()(const pair<string, int> &a, const pair<string, int> &b) const {
        if(a.second != b.second) return a.second < b.second;
        return a.first > b.first;
    }
};

class FoodRatings {
public:
    // [cuisine, [food, rating]]
    unordered_map<string, set<pair<string, int>, cmp>> mp;
    // [food, [cuisines, ratings]
    unordered_map<string, pair<string, int>> food_data;

    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i = 0; i < foods.size(); i++) {
            mp[cuisines[i]].insert({foods[i], ratings[i]});
            food_data[foods[i]] = {cuisines[i], ratings[i]};
        }
    }
    
    void changeRating(string food, int newRating) {
        auto [type, oldRating] = food_data[food];
        mp[type].erase({food, oldRating});
        mp[type].insert({food, newRating});
        food_data[food] = {type, newRating};
    }
    
    string highestRated(string cuisine) {
        return mp[cuisine].rbegin()->first;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */