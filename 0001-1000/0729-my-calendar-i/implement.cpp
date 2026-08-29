#define pii pair<int, int>
#define fi first
#define se second

class MyCalendar {
public:
    set<pii> event;

    MyCalendar() {
        
    }
    
    bool book(int startTime, int endTime) {
        auto it = event.lower_bound({startTime, startTime});
        if (it == event.end() || ((*it).fi >= endTime && (*it).se != -1)) {
            event.insert({startTime, endTime});
            event.insert({endTime, -1});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */