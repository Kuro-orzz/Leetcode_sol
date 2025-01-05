struct User {
    int userId, taskId, priority;

    User(int userId, int taskId, int priority) {
        this->userId = userId;
        this->taskId = taskId;
        this->priority = priority;
    }
};

struct cmp {
    bool operator()(User a, User b){
        if(a.priority != b.priority)
            return a.priority < b.priority;
        return a.taskId < b.taskId;
    }
};

class TaskManager {
public:
    priority_queue<User, vector<User>, cmp> pq;
    unordered_map<int, int> k, val;
    multiset<tuple<int, int, int>> rm;

    TaskManager(vector<vector<int>>& tasks) {
        for(int i = 0; i < tasks.size(); i++){
            User a(tasks[i][0], tasks[i][1], tasks[i][2]);
            k[tasks[i][1]] = tasks[i][0];
            val[tasks[i][1]] = tasks[i][2];
            pq.push(a);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        User a(userId, taskId, priority);
        k[taskId] = userId;
        val[taskId] = priority;
        pq.push(a);
    }
    
    void edit(int taskId, int newPriority) {
        rmv(taskId);
        User a(k[taskId], taskId, newPriority);
        val[taskId] = newPriority;
        pq.push(a);
    }
    
    void rmv(int taskId) {
        rm.insert({k[taskId], taskId, val[taskId]});
    }
    
    int execTop() {
        if(pq.empty()) return -1;
        User a = pq.top();
        while(rm.count({a.userId, a.taskId, a.priority})){
            pq.pop();
            auto it = rm.find({a.userId, a.taskId, a.priority});
            rm.erase(it);
            if(pq.empty()) return -1;
            a = pq.top();
        }
        pq.pop();
        return a.userId;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */