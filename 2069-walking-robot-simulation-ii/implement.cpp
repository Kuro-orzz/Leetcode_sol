class Robot {
public:
    int width, height;
    string direction[4] = {"North", "East", "South", "West"};
    int curDir = 1;
    vector<int> curPos = {0, 0};

    Robot(int width, int height) {
        this->width = width;
        this->height = height;
    }
    
    void step(int num) {
        if (num >= 2 * (width + height - 2)) {
            if (curPos == vector<int>{0, 0}) curDir = 2;
            else if (curPos == vector<int>{width-1, 0}) curDir = 1;
            else if (curPos == vector<int>{width-1, height-1}) curDir = 0;
            else if (curPos == vector<int>{0, height-1}) curDir = 3;
            num %= (2 * (width + height - 2));
        }
        while (num) {
            if (curDir == 0) {
                int validMove = min(num, height - curPos[1] - 1);
                num -= validMove;
                curPos[1] += validMove;
            } else if (curDir == 1) {
                int validMove = min(num, width - curPos[0] - 1);
                num -= validMove;
                curPos[0] += validMove;
            } else if (curDir == 2) {
                int validMove = min(num, curPos[1]);
                num -= validMove;
                curPos[1] -= validMove;
            } else if (curDir == 3) {
                int validMove = min(num, curPos[0]);
                num -= validMove;
                curPos[0] -= validMove;
            }
            if (!num) break;
            if (curDir == 0 || curDir == 2) {
                if (!curPos[1] || curPos[1] == height - 1) curDir = (curDir + 3) % 4;
            } else {
                if (!curPos[0] || curPos[0] == width - 1) curDir = (curDir + 3) % 4;
            }
        }
    }
    
    vector<int> getPos() {
        return curPos;
    }
    
    string getDir() {
        return direction[curDir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */