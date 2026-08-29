#define pii pair<int, int>
#define fi first
#define se second
#define get(x, i) get<(i)>(x)

class MovieRentingSystem {
public:
    // movie, {price, shop}
    map<int, set<pii>> mp;
    // price, shop, movie
    set<tuple<int, int, int>> rented;
    // {shop, movie}, price
    map<pii, int> get_price;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &it : entries) {
            mp[it[1]].insert({it[2], it[0]});
            get_price[{it[0], it[1]}] = it[2];
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        int cnt = 0;
        for (auto &it : mp[movie]) {
            if (cnt == 5) break;
            res.push_back(it.se);
            cnt++;
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int price = get_price[{shop, movie}];
        rented.insert({price, shop, movie});
        mp[movie].erase({price, shop});
    }
    
    void drop(int shop, int movie) {
        int price = get_price[{shop, movie}];
        rented.erase({price, shop, movie});
        mp[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int cnt = 0;
        for (auto &it : rented) {
            if (cnt == 5) break;
            res.push_back({get(it, 1), get(it, 2)});
            cnt++;
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