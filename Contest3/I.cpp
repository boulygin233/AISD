#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using std::vector;
using std::cin;
using std::cout;
using std::stack;
using std::queue;

class Node {
private:
    int num;
    int color;
    int prev;
    vector<int> neighbours;
public:
    Node() {
        static int k = 0;
        color = 0;
        num = k;
        prev = num;
        ++k;
    }

    int get_color() {
        return color;
    }

    int get_num() {
        return num;
    }

    int get_prev() {
        return prev;
    }

    void set_color(int new_color) {
        color = new_color;
    }

    void set_prev(int new_prev) {
        prev = new_prev;
    }


    void add_neighbour(int neighbour) {
        neighbours.emplace_back(neighbour);
    }

    std::vector<int> get_neighbours() {
        return neighbours;
    }
};

void BFS(int start, int finish, vector<int> &nums) {
    queue<int> current_nums;
    nums[start] = start;
    current_nums.push(start);
    while (!current_nums.empty()) {
        int cur_num = current_nums.front();
        current_nums.pop();
        int first_dig = cur_num / 1000;
        int fourth_dig = cur_num % 10;
        if (fourth_dig > 1){
            if (nums[cur_num - 1] == 0) {
                nums[cur_num - 1] = cur_num;
                current_nums.emplace(cur_num - 1);
                if (cur_num - 1 == finish){
                    return;
                }
            }
        }
        if (first_dig < 9){
            if (nums[cur_num + 1000] == 0) {
                nums[cur_num + 1000] = cur_num;
                current_nums.emplace(cur_num + 1000);
                if (cur_num + 1000 == finish){
                    return;
                }
            }
        }
        if (nums[cur_num / 10 + fourth_dig * 1000] == 0){
            nums[cur_num / 10 + fourth_dig * 1000] = cur_num;
            current_nums.emplace(cur_num / 10 + fourth_dig * 1000);
            if (cur_num / 10 + fourth_dig * 1000 == finish) {
                return;
            }
        }
        if (nums[(cur_num * 10 + first_dig) % 10000] == 0) {
            nums[(cur_num * 10 + first_dig) % 10000] = cur_num;
            current_nums.emplace((cur_num * 10 + first_dig) % 10000);
            if ((cur_num * 10 + first_dig) % 10000 == finish) {
                return;
            }
        }
    }
}

int main() {
    int start, finish;
    cin >> start >> finish;
    vector<int> nums(10000, 0);
    BFS(start, finish, nums);
    stack<int>way;
    int curr = finish;
    way.emplace(curr);
    while (nums[curr] != curr) {
        way.emplace(nums[curr]);
        curr = nums[curr];
    }
    while (!way.empty()){
        cout<<way.top()<<'\n';
        way.pop();
    }
}
