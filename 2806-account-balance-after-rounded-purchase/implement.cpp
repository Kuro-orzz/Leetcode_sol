class Solution {
public:
    int accountBalanceAfterPurchase(int purchaseAmount) {
        int tmp = (100-purchaseAmount) % 10;
        if(tmp <= 5) return (100-purchaseAmount)/10*10;
        return (100-purchaseAmount)/10*10+10;
    }
};