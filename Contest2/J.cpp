#include <iostream>
#include <map>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    map <string, int> clients;
    int requestAmount;
    cin>>requestAmount;
    for (int i = 0; i < requestAmount; ++i){
        int operation;
        cin>>operation;
        string name;
        cin>>name;
        if (operation == 1){
            int money;
            cin>>money;
            clients[name] += money;
        }
        else {
            auto iter = clients.find(name);
            if (iter == clients.end()){
                cout<<"ERROR\n";
            }
            else{
                cout<<clients[name]<<'\n';
            }
        }
    }
}
