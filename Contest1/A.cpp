#include <iostream>
#include <cstdlib>
#include <math.h>
#include <cstring>

namespace geometry {
    class Vector;

    class AbstractShape;

    class Point;

    class Segment;

    class Ray;

    class Line;

    class Polygon;

    class AbstractShape {
    public:
        virtual int ContainsPoint(const Point &) const = 0;

        virtual int CrossSegment(const Segment &) const = 0;

        virtual void Print() const = 0;

        virtual AbstractShape *Move(const Vector &) = 0;

        virtual AbstractShape *Clone() const = 0;
    };

    class Point : public AbstractShape {

        friend Point operator+(const Point &left, const Point &right) {
            return Point(left.position_x + right.position_x, left.position_y + right.position_y);
        }

        friend Point operator-(const Point &left, const Point &right) {
            return Point(left.position_x - right.position_x, left.position_y - right.position_y);
        }

        friend int operator==(const Point &a, const Point &b) {
            if (a.position_x == b.position_x && a.position_y == b.position_y) {
                return 1;
            }
            return 0;
        }

    public:
        int position_x;
        int position_y;

        Point() : position_x(0), position_y(0) {}

        Point(int X, int Y) : position_x(X), position_y(Y) {}

        void Print() const {
            std::cout << position_x << ' ' << position_y;
        }

        AbstractShape *Clone() const {
            AbstractShape *New = new Point(position_x, position_y);
            return New;
        }

        int ContainsPoint(const Point &A) const {
            if (A.position_x == position_x && A.position_y == position_y) {
                return 1;
            }
            return 0;
        }

        int CrossSegment(const Segment &AB) const;

        AbstractShape *Move(const Vector &AB);
    };


    class Segment : public AbstractShape {
    public:
        Point Begin;
        Point End;
    public:
        Segment(const Point &A, const Point &B) : Begin(A), End(B) {}

        void Print() const {
            std::cout << Begin.position_x << ' ' << Begin.position_y << ' ' << End.position_x << ' ' << End.position_y;
        }

        AbstractShape *Clone() const {
            AbstractShape *New = new Segment(Begin, End);
            return New;
        }

        AbstractShape *Move(const Vector &AB);

        int ContainsPoint(const Point &A) const;

        int CrossSegment(const Segment &AB) const;
    };

    class Line : public AbstractShape {
    public:
	Point Begin;
        Point End;
        Line(const Point &A, const Point &B) : Begin(A), End(B) {}

        void Print() const {
            std::cout << Begin.position_x << ' ' << Begin.position_y << ' ' << End.position_x << ' ' << End.position_y;
        }

        AbstractShape *Clone() const {
            AbstractShape *New = new Line(Begin, End);
            return New;
        }

        AbstractShape *Move(const Vector &AB);

        int ContainsPoint(const Point &A) const;

        int CrossSegment(const Segment &AB) const;
    };

    class Ray : public AbstractShape {
    public:
        Point Begin;
        Point End;
    public:
        Ray(const Point &A, const Point &B) : Begin(A), End(B) {}

        void Print() const {
            std::cout << Begin.position_x << ' ' << Begin.position_y << ' ' << End.position_x << ' ' << End.position_y;
        }

        AbstractShape *Clone() const {
            AbstractShape *New = new Ray(Begin, End);
            return New;
        }

        AbstractShape *Move(const Vector &AB);

        int ContainsPoint(const Point &K) const;

        int CrossSegment(const Segment &AB) const;
    };

    class Polygon : public AbstractShape {
    private:
        Point *Points;
        size_t Angles;
    public:
        Polygon(Point *points, size_t n) {
            Angles = n;
            Points = new Point[Angles];
            for (int i = 0; i < n; ++i) {
                Points[i] = points[i];
            }
        }

        void Print() const {
            std::cout << Angles << '\n';
            for (int i = 0; i < Angles; ++i) {
                std::cout << Points[i].position_x << ' ' << Points[i].position_y << ' ';
            }
        }

        AbstractShape *Clone() const {
            AbstractShape *New = new Polygon(Points, Angles);
            return New;
        }

        AbstractShape *Move(const Vector &AB);

        int ContainsPoint(const Point &A) const;

        int CrossSegment(const Segment &AB) const;
    };

    class Vector {
    public:
        Point value;

        Vector() : value(0, 0) {}

        Vector(double x, double y) : value(x, y) {}

        Vector(const Point &A) {
            value = A;
        }

        Vector(const Point &A, const Point &B) {
            value = B - A;
        }

        Vector(const Vector &AB) {
            value.position_x = AB.value.position_x;
            value.position_y = AB.value.position_y;
        }

        Vector &operator=(const Vector &AB) {
            value.position_x = AB.value.position_x;
            value.position_y = AB.value.position_y;
        }

        int GetX() const {
            return value.position_x;
        }

        int GetY() const {
            return value.position_y;
        }

        friend double VectorPr(const Vector &Value1, const Vector &Value2) {
            return (Value1.value.position_x * Value2.value.position_y -
                    Value1.value.position_y * Value2.value.position_x);
        }

        friend Vector operator+(const Vector &AB, const Vector &CD) {
            Vector New;
            New.value = AB.value + CD.value;
            return New;
        }
    };

    AbstractShape *Point::Move(const Vector &AB) {
        position_x += AB.GetX();
        position_y += AB.GetY();
        return this;
    }

    AbstractShape *Segment::Move(const Vector &AB) {
        Begin = Begin + AB.value;
        End = End + AB.value;
        return this;
    }

    AbstractShape *Line::Move(const Vector &AB) {
        Begin = Begin + AB.value;
        End = End + AB.value;
        return this;
    }

    AbstractShape *Ray::Move(const Vector &AB) {
        Begin = Begin + AB.value;
        End = End + AB.value;
        return this;
    }

    AbstractShape *Polygon::Move(const Vector &AB) {
        Point Moving(AB.value);
        for (int i = 0; i < Angles; ++i) {
            Points[i] = Points[i] + Moving;
        }
        return this;
    }

    int Point::CrossSegment(const Segment &AB) const {
        Point A = AB.Begin;
        Point B = AB.End;
        Point C(position_x, position_y);
        if (A.position_x == B.position_x) {
            if ((C.position_x == A.position_x) && ((C.position_y >= A.position_y && B.position_y >= C.position_y) ||
                                                   (C.position_y <= A.position_y && B.position_y <= C.position_y))) {
                return 1;
            } else {
                return 0;
            }
        } else if (A.position_y == B.position_y) {
            if ((C.position_y == A.position_y) && ((C.position_x >= A.position_x && B.position_x >= C.position_x) ||
                                                   (C.position_x <= A.position_x && B.position_x <= C.position_x))) {
                return 1;
            } else {
                return 0;
            }
        } else if ((C.position_x - A.position_x) * (B.position_y - A.position_y) ==
                   (C.position_y - A.position_y) * (B.position_x - A.position_x)) {
            if ((C.position_x >= A.position_x && B.position_x >= C.position_x) ||
                (C.position_x <= A.position_x && B.position_x <= C.position_x)) {
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    }

    int SegmentIntersection(Point &A, Point &B, Point &C, Point &D) {
        if ((A.position_x <= B.position_x && A.position_x <= C.position_x && C.position_x <= B.position_x) ||
            (A.position_x <= B.position_x && A.position_x <= D.position_x && D.position_x <= B.position_x) ||
            (A.position_x >= B.position_x && A.position_x >= C.position_x && C.position_x >= B.position_x) ||
            (A.position_x >= B.position_x && A.position_x >= D.position_x && D.position_x >= B.position_x) ||
            (C.position_x <= D.position_x && C.position_x <= A.position_x && A.position_x <= D.position_x) ||
            (C.position_x <= D.position_x && C.position_x <= B.position_x && B.position_x <= D.position_x) ||
            (C.position_x >= D.position_x && C.position_x >= A.position_x && A.position_x >= D.position_x) ||
            (C.position_x >= D.position_x && C.position_x >= B.position_x && B.position_x >= D.position_x)) {
            if ((A.position_y <= B.position_y && A.position_y <= C.position_y && C.position_y <= B.position_y) ||
                (A.position_y <= B.position_y && A.position_y <= D.position_y && D.position_y <= B.position_y) ||
                (A.position_y >= B.position_y && A.position_y >= C.position_y && C.position_y >= B.position_y) ||
                (A.position_y >= B.position_y && A.position_y >= D.position_y && D.position_y >= B.position_y) ||
                (C.position_y <= D.position_y && C.position_y <= A.position_y && A.position_y <= D.position_y) ||
                (C.position_y <= D.position_y && C.position_y <= B.position_y && B.position_y <= D.position_y) ||
                (C.position_y >= D.position_y && C.position_y >= A.position_y && A.position_y >= D.position_y) ||
                (C.position_y >= D.position_y && C.position_y >= B.position_y && B.position_y >= D.position_y)) {
                return 1;
            }
            return 0;
        }
        return 0;
    }

    int Segment::ContainsPoint(const Point &A) const {
        return A.CrossSegment(*this);
    }

    int Segment::CrossSegment(const Segment &AB) const {
        Point K, L, M, N;
        K = Begin;
        L = End;
        M = AB.Begin;
        N = AB.End;
        Vector KL(L - K), KM(M - K), KN(N - K), MN(N - M), ML(L - M), MK(K - M);
        if (K == M || K == N || L == M || L == N) {
            return 1;
        } else if (VectorPr(KM, KL) * VectorPr(KN, KL) <= 0 &&
                   VectorPr(MK, MN) * VectorPr(ML, MN) <= 0 &&
                   SegmentIntersection(K, L, M, N)) {
            return 1;
        }
        return 0;
    }

    int Line::ContainsPoint(const Point &A) const {
        Point M, K, L;
        M = A;
        K = Begin;
        L = End;
        if (M.position_x == L.position_x) {
            if (M.position_x == K.position_x) {
                return 1;
            }
            return 0;
        } else if (K.position_y == L.position_y) {
            if (M.position_y == K.position_y) {
                return 1;
            }
            return 0;

        } else if ((M.position_x - K.position_x) * (L.position_y - K.position_y) ==
                   (M.position_y - K.position_y) * (L.position_x - K.position_x)) {
            return 1;
        }
        return 0;
    }

    int Line::CrossSegment(const Segment &AB) const {
        Point K, L, M, N;
        K = Begin;
        L = End;
        M = AB.Begin;
        N = AB.End;
        Vector KL(L - K), KM(M - K), KN(N - K), MN(N - M), ML(L - M), MK(K - M);
        if (K == M || K == N || L == M || L == N) {
            return 1;
        } else if (ContainsPoint(M) || ContainsPoint(N)) {
            return 1;
        } else if (VectorPr(KM, KL) * VectorPr(KN, KL) <= 0 &&
                   VectorPr(MK, MN) * VectorPr(ML, MN) <= 0) {
            return 1;
        }
        return 0;
    }

    int Ray::ContainsPoint(const Point &A) const {
        Point M, K, L;
        M = A;
        K = Begin;
        L = End;
        if (K.position_x == L.position_x) {
            if ((M.position_x == K.position_x) && ((M.position_y >= K.position_y && K.position_y <= L.position_y) ||
                                                   (M.position_y <= K.position_y && K.position_y >= L.position_y))) {
                return 1;
            }
            return 0;

        } else if (K.position_y == L.position_y) {
            if ((M.position_y == K.position_y) && ((M.position_x >= K.position_x && K.position_x <= L.position_x) ||
                                                   (M.position_x <= K.position_x && K.position_x >= L.position_x))) {
                return 1;
            }
            return 0;

        } else if ((M.position_x - K.position_x) * (L.position_y - K.position_y) ==
                   (M.position_y - K.position_y) * (L.position_x - K.position_x)) {
            if ((M.position_x >= K.position_x && L.position_x >= K.position_x) ||
                (M.position_x <= K.position_x && L.position_x <= K.position_x)) {
                return 1;
            }
            return 0;
        }
        return 0;
    }

    int Ray::CrossSegment(const Segment &AB) const {
        Point K, L, M, N;
        K = Begin;
        L = End;
        M = AB.Begin;
        N = AB.End;
        Vector KL(L - K), KM(M - K), KN(N - K), MN(N - M), ML(L - M), MK(K - M);
        if (K == M || K == N || L == M || L == N) {
            return 1;
        } else if (ContainsPoint(M) || ContainsPoint(N)) {
            return 1;
        } else if (VectorPr(KM, KL) * VectorPr(KN, KL) <= 0 &&
                   VectorPr(MK, MN) * VectorPr(ML, MN) <= 0 &&
                   ((K.position_x <= L.position_x && K.position_x <= M.position_x) ||
                    (K.position_x <= L.position_x && K.position_x <= N.position_x) ||
                    (K.position_x >= L.position_x && M.position_x >= L.position_x) ||
                    (K.position_x >= L.position_x && N.position_x >= L.position_x))) {
            return 1;
        }
        return 0;
    }

    int Polygon::ContainsPoint(const Point &A) const {
        return 1;
    }

    int Polygon::CrossSegment(const Segment &AB) const {
        Segment Seg(AB);
        for (int i = 0; i < Angles; ++i) {
            Seg = Segment(Points[i], Points[(i + 1) % Angles]);
            if (Seg.CrossSegment(AB)) {
                return 1;
            }
        }
        return 0;
    }

}


void CheckFunctions(const geometry::AbstractShape *shape, const geometry::Point &A, const geometry::Point &B) {
    if (shape->ContainsPoint(A)) {
        std::cout << "Given shape contains point A" << std::endl;
    } else {
        std::cout << "Given shape do not contains point A" << std::endl;
    }

    geometry::Segment AB(A, B);
    if (shape->CrossSegment(AB)) {
        std::cout << "Given shape crosses segment AB" << std::endl;
    } else {
        std::cout << "Given shape do not crosses segment AB" << std::endl;
    }

    geometry::Vector ab(A, B);
    geometry::AbstractShape *clonedShape = shape->Clone();
    clonedShape->Move(ab)->Print();
    std::cout << '\n';
    delete clonedShape;
}

int main() {

    geometry::AbstractShape *shape;
    char command[10];
    std::cin >> command;
    if (!strcmp(command, "point")) {
        int x, y;
        std::cin >> x >> y;
        shape = new geometry::Point(x, y);
    } else if (!strcmp(command, "segment")) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        shape = new geometry::Segment(geometry::Point(x1, y1), geometry::Point(x2, y2));
    } else if (!strcmp(command, "ray")) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        shape = new geometry::Ray(geometry::Point(x1, y1), geometry::Point(x2, y2));
    } else if (!strcmp(command, "line")) {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        shape = new geometry::Line(geometry::Point(x1, y1), geometry::Point(x2, y2));
    } else if (!strcmp(command, "polygon")) {
        size_t n_points;
        std::cin >> n_points;
        geometry::Point *points = new geometry::Point[n_points];
        for (size_t i = 0; i < n_points; ++i) {
            int x, y;
            std::cin >> x >> y;
            points[i] = geometry::Point(x, y);
        }
        shape = new geometry::Polygon(points, n_points);
        delete[] points;
    } else {
        std::cerr << "Undefined command" << std::endl;
        return 1;
    }

    int ax, ay, bx, by;
    std::cin >> ax >> ay >> bx >> by;
    geometry::Point A(ax, ay), B(bx, by);

    CheckFunctions(shape, A, B);

    return 0;
}
