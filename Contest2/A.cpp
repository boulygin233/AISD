#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Participant{
    int participantNumber;
    int numberOfSolvedProblems;
    int timePenalty;
};

bool cmp (const Participant& p1, const Participant& p2){
    if (p1.numberOfSolvedProblems > p2.numberOfSolvedProblems){
        return true;
    }
    else if (p1.numberOfSolvedProblems == p2.numberOfSolvedProblems) {
        if (p1.timePenalty < p2.timePenalty) {
            return true;
        } else if (p1.timePenalty == p2.timePenalty) {
            return p1.participantNumber < p2.participantNumber;
        } else {
            return false;
        }
    }
    else {
        return false;
    }
}
int main() {
    vector<Participant> tableOfParticipants;
    int numberOfParticipants;
    cin>>numberOfParticipants;
    for (int i = 0; i < numberOfParticipants; ++i) {
        Participant New;
        New.participantNumber = i + 1;
        cin>>New.numberOfSolvedProblems>>New.timePenalty;
        tableOfParticipants.push_back(New);
    }
    sort(tableOfParticipants.begin(), tableOfParticipants.end(), cmp);
    for (int i = 0; i < numberOfParticipants; ++i) {
        cout<<tableOfParticipants[i].participantNumber<<' ';
    }
}
