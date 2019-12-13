#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    map<string, string> dict;
    string word;
    string newMean;
    string meaning;
    int status = 0;
    while (cin>>word){
        if (status == 0) {
            newMean = word;
            status = 1;
            char y;
            cin>>y;
        } else {
            meaning = word;
            if (*(meaning.end() - 1) == ','){
                meaning.erase(meaning.end() - 1);
                auto iter = dict.find(meaning);
                if (iter == dict.end()){
                    dict[meaning] += " - " + newMean;
                }
                else {
                    dict[meaning] +=", " + newMean;
                }
            }
            else {
                auto iter = dict.find(meaning);
                if (iter == dict.end()){
                    dict[meaning] += " - " + newMean;
                }
                else {
                    dict[meaning] +=", " + newMean;
                }
                status = 0;
            }
        }
    }
    /*int x;
    cin>>x;
    for (int i = 0; i < x; ++i){
        if (status == 0) {
            cin>>word;
            status = 1;
            char y;
            cin>>y;
        } else {
            cin>>meaning;
            if (*(meaning.end() - 1) == ','){
                meaning.erase(meaning.end() - 1);
                auto iter = dict.find(meaning);
                if (iter == dict.end()){
                    dict[meaning] += " - " + word;
                }
                else {
                    dict[meaning] +=", " + word;
                }
            }
            else {
                auto iter = dict.find(meaning);
                if (iter == dict.end()){
                    dict[meaning] += " - " + word;
                }
                else {
                    dict[meaning] +=", " + word;
                }
                status = 0;
            }
        }
    }*/
    cout<<dict.size()<<'\n';
    for (auto iter = dict.begin(); iter != dict.end(); ++iter){
        cout<<(*iter).first<<(*iter).second<<'\n';
    }
}
