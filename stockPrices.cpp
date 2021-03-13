//
// Created by Kylian Lee on 2021/03/13.
//

#include <iostream>
#include <vector>
#include <stack>
#include <utility>

using namespace std;

void calcStocksTime(stack<int> stockPrices, vector<pair<int, int>> &temp);
vector<int> solution(vector<int> prices);

vector<int> solution(vector<int> prices){
    int size;
    stack<int> stockPrices;
    vector<pair<int, int>> temp;
    vector<int> answer;

    size = prices.size();

    for(int i = 0; i < size; i++) {
        stockPrices.push(prices[i]);
    }

    calcStocksTime(stockPrices, temp);

    size = temp.size();


    for(int i = size - 1; i >= 0; i--){
        answer.push_back(temp[i].second);
    }

    return answer;
}

void calcStocksTime(stack<int> stockPrices, vector<pair<int, int>> &temp){
    int minPrice = stockPrices.top(), curPrice = minPrice;
    int term = 0, tempTerm = 1;
    int size;

    temp.push_back(make_pair(minPrice, term));
    stockPrices.pop();

    while(!stockPrices.empty()){
        curPrice = stockPrices.top();
        stockPrices.pop();
        term++;

        if(curPrice <= minPrice){
            minPrice = curPrice;
            temp.push_back(make_pair(curPrice, term));
        }
        else {
            size = temp.size();
            for (int i = size - 1; i >= 0; i--) {
                if (curPrice > temp[i].first) {
                    temp.push_back(make_pair(curPrice, tempTerm));
                    break;
                }
                else tempTerm++;
            }
        }

    }

}

int main() {
    vector<int> prices = {4,3,2,5,6,7,4};
    vector<int> answer;

    answer = solution(prices);

    for(int i = 0; i < answer.size(); i++){
        cout << answer[i] << endl;
    }

    return 0;
}

