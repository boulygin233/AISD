#include <string>
#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int main() {
    priority_queue<long long> calculator;
    int numbersAmount;
    cin>>numbersAmount;
    for (int i = 0; i < numbersAmount; ++i){
        int number;
        cin>>number;
        calculator.emplace(-number);
    }
    double finalBill = 0;
    while(calculator.size() > 1){
        long long firstNum = calculator.top();
        calculator.pop();
        long long secondNum = calculator.top();
        calculator.pop();
        long long sum = firstNum + secondNum;
        finalBill += sum * (-0.05);
        calculator.emplace(sum);
    }
    cout.setf(ios::fixed);
    cout.precision(2);
    cout<<finalBill;
}
