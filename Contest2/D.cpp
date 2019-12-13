#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

using namespace std;

class DequeEmptyExeption{
};

class myDeque{
private:
    deque<int> myDeq;
public:
    void push_back(int value){
        myDeq.emplace_back(value);
    }
    void push_front(int value){
        myDeq.emplace_front(value);
    }
    void clear(){
        myDeq.clear();
    }
    int size(){
        return myDeq.size();
    }
    int pop_front(){
        if (myDeq.empty()){
            throw DequeEmptyExeption();
        }
        else {
            int value = *(myDeq.begin());
            myDeq.pop_front();
            return value;
        }
    }
    int pop_back(){
        if (myDeq.empty()){
            throw DequeEmptyExeption();
        }
        else {
            int value = *(myDeq.end() - 1);
            myDeq.pop_back();
            return value;
        }
    }
    int front(){
        if (myDeq.empty()){
            throw DequeEmptyExeption();
        }
        else {
            int value = *(myDeq.begin());
            return value;
        }
    }
    int back(){
        if (myDeq.empty()){
            throw DequeEmptyExeption();
        }
        else {
            int value = *(myDeq.end() - 1);
            return value;
        }
    }
};

int main() {
    int requestsAmount;
    cin>>requestsAmount;
    string request;
    myDeque myDeq;
    for (int i = 0; i < requestsAmount; ++i){
        cin>>request;
        if (request == "push_back"){
            int value;
            cin>>value;
            myDeq.push_back(value);
            cout<<"ok\n";
        }
        if (request == "push_front"){
            int value;
            cin>>value;
            myDeq.push_front(value);
            cout<<"ok\n";
        }
        if (request == "back"){
            try{
                cout<<myDeq.back()<<'\n';
            }
            catch (const DequeEmptyExeption &ex){
                cout<<"error\n";
            }
        }
        if (request == "front"){
            try{
                cout<<myDeq.front()<<'\n';
            }
            catch (const DequeEmptyExeption &ex){
                cout<<"error\n";
            }
        }
        if (request == "pop_back"){
            try{
                cout<<myDeq.pop_back()<<'\n';
            }
            catch (const DequeEmptyExeption &ex){
                cout<<"error\n";
            }
        }
        if (request == "pop_front"){
            try{
                cout<<myDeq.pop_front()<<'\n';
            }
            catch (const DequeEmptyExeption &ex){
                cout<<"error\n";
            }
        }
        if (request == "size"){
            cout<<myDeq.size()<<'\n';
        }
        if (request == "clear"){
            myDeq.clear();
            cout<<"ok\n";
        }
    }
}
