#include <iostream>
#include <map>
#include <set>

int MAX = 20000000;

using namespace std;

class Comp{
public:
    bool operator()(pair<int, int> pair1, pair<int, int> pair2){
        return (pair1.first < pair2.first) || (pair1.first == pair2.first && pair1.second > pair2.second);
    }
};

class Radio{
private:
    map<int, pair<int, int>> tracksScore;
    set<pair<int, int>, Comp> scoreSet;
    int maxTrackID;
public:
    Radio() : maxTrackID(1) {};
    int push(int trackID, int score, int newScore = 0) {
        if (score != 0 || newScore == -1) {
            if (tracksScore[trackID].second) {
                scoreSet.erase({tracksScore[trackID].first, trackID});
            }
            if (newScore == -1){
                tracksScore[trackID].first = newScore;
            }
            else {
                tracksScore[trackID].first += score;
            }
            tracksScore[trackID].second = 1;
            scoreSet.insert({tracksScore[trackID].first, trackID});
        }
        else {
            if (!tracksScore[trackID].second){
                tracksScore[trackID].second = 1;
                scoreSet.insert({tracksScore[trackID].first, trackID});
            }
        }
        return tracksScore[trackID].first;
    }
    void get() {
        if ((tracksScore.size() == 0 || scoreSet.begin()->first <= 0) && scoreSet.size() < MAX){
            while (tracksScore[maxTrackID].first != 0 && maxTrackID < MAX) {
                ++maxTrackID;
            }
            push(maxTrackID, 0);
        }
        int resultID = scoreSet.rbegin()->second;
        int resultScore = scoreSet.rbegin()->first;
        cout << resultID << ' ' << resultScore << '\n';
        push(resultID, 0, -1);
    }
};



int main() {
    string command, ip;
    int trackID, time;
    int score;
    Radio radio;
    map<string, pair<long long, bool>> userLastVoteTime;
    for (int i = 0; command != "EXIT"; ++i){
        cin >> command;
        if (command == "VOTE"){
            cin >> ip >> trackID >> score >> time;
            int result;
            if (userLastVoteTime[ip].second == 0 || userLastVoteTime[ip].first + 600 <= time){
                result = radio.push(trackID, score);
                userLastVoteTime[ip].first = time;
                userLastVoteTime[ip].second = 1;
            }
            else{
                result = radio.push(trackID, 0);
            }
            cout << result << '\n';
        }
        if (command == "GET"){
            radio.get();
        }
    }
    cout << "OK";
}
