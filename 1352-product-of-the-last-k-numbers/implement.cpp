class ProductOfNumbers {
public:
    vector<int> a{0};
    int zeroPos = 0;

    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(a.back() == 0)
            a.push_back(num);
        else
            a.push_back(a.back()*num);
        if(num == 0)
            zeroPos = a.size()-1;    
    }
    
    int getProduct(int k) {
        if(a.size()-1-k < zeroPos)
            return 0;
        return a.back() / max(a[a.size()-1-k], 1);
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */