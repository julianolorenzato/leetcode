// https://leetcode.com/problems/best-time-to-buy-and-sell-stock

int maxProfit(int* prices, int pricesSize){
    int max_profit = 0, min_price = prices[0];
    
    // for(int i = 0; i < pricesSize; i++) {
    //     for(int j = i + 1; j < pricesSize; j++) {
    //         if((prices[j] - prices[i]) > profit) {
    //             profit = prices[j] - prices[i];
    //         }
    //     }
    // }

    for (int i = 0; i < pricesSize; i++) {
        if(prices[i] < min_price) {
            min_price = prices[i];
        }

        int profit = prices[i] - min_price;

        if(profit > max_profit) {
            max_profit = profit;
        }
    }

    return max_profit;
}