#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Point {
public:
    long long position_x, position_y;

    Point(long long x, long long y) : position_x(x), position_y(y) {}

    ~Point() = default;
};

bool PointComparator(Point A, Point B) {
    return A.position_x < B.position_x || (A.position_x == B.position_x && A.position_y < B.position_y);
}

void ConvexHullBuilder(vector<Point> &points) {
    if (points.size() == 1) {
        return;
    }
    sort(points.begin(), points.end(), &PointComparator);
    Point p1 = points[0], p2 = points.back();
    vector<Point> PointsUp, PointsDown;
    PointsUp.push_back(p1);
    PointsDown.push_back(p1);
    for (size_t i = 1; i < points.size(); ++i) {
        if (i == points.size() - 1 || (p1.position_x * (points[i].position_y - p2.position_y) +
                                       points[i].position_x * (p2.position_y - p1.position_y) +
                                       p2.position_x * (p1.position_y - points[i].position_y) < 0)) {
            while (PointsUp.size() >= 2 && (PointsUp[PointsUp.size() - 2].position_x *
                                            (PointsUp[PointsUp.size() - 1].position_y - points[i].position_y) +
                                            PointsUp[PointsUp.size() - 1].position_x *
                                            (points[i].position_y - PointsUp[PointsUp.size() - 2].position_y) +
                                            points[i].position_x * (PointsUp[PointsUp.size() - 2].position_y -
                                                                    PointsUp[PointsUp.size() - 1].position_y) >= 0)) {
                PointsUp.pop_back();
            }
            PointsUp.push_back(points[i]);
        }
        if (i == points.size() - 1 || (p1.position_x * (points[i].position_y - p2.position_y) +
                                       points[i].position_x * (p2.position_y - p1.position_y) +
                                       p2.position_x * (p1.position_y - points[i].position_y) > 0)) {
            while (PointsDown.size() >= 2 &&
                   (PointsDown[PointsDown.size() - 2].position_x *
                    (PointsDown[PointsDown.size() - 1].position_y - points[i].position_y) +
                    PointsDown[PointsDown.size() - 1].position_x *
                    (points[i].position_y - PointsDown[PointsDown.size() - 2].position_y) +
                    points[i].position_x *
                    (PointsDown[PointsDown.size() - 2].position_y - PointsDown[PointsDown.size() - 1].position_y) <=
                    0)) {
                PointsDown.pop_back();
            }
            PointsDown.push_back(points[i]);
        }
    }
    points.clear();
    for (int i = 0; i < PointsUp.size(); ++i) {
        points.push_back(PointsUp[i]);
    }
    for (int i = PointsDown.size() - 2; i > 0; --i) {
        points.push_back(PointsDown[i]);
    }
}

int main() {
    vector<Point> points;
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        long long x, y;
        cin >> x >> y;
        points.push_back(Point(x, y));
    }
    ConvexHullBuilder(points);
    int size = points.size();
    if (size == 2 && points[0].position_x == points[1].position_x && points[0].position_y == points[1].position_y) {
        cout << 1 << '\n';
        cout << points[0].position_x << ' ' << points[0].position_y << '\n';
    } else {
        cout << size << '\n';
        for (int i = 0; i < size; ++i) {
            cout << points[i].position_x << ' ' << points[i].position_y << '\n';
        }
    }
    long long area = 0;
    for (int i = 0; i < size; ++i) {
        area += points[i].position_x * points[(i + 1) % size].position_y -
                points[(i + 1) % size].position_x * points[i].position_y;
    }
    area = abs(area);
    if (area % 2 == 0) {
        cout << area / 2 << ".0";
    } else {
        cout << area / 2 << ".5";
    }
}
