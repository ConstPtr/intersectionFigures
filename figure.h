#pragma once
#include <iostream>
#include <vector>
#include <cmath>

struct point
{
    double _x;
    double _y;
};

class figure
{
    private:
        std::vector<point> _points;

        point getPoint(const int& _numOfElem) const;
        int numOfLines() const;
        bool comparePoints(const point& p1, const point& p2, const point& p3, const point& p4) const;
        bool checkPointAndLine(const point& p1, const point& p2, const point& p3) const;
        bool pointsOnLines(const point& p1, const point& p2, const point& p3, const point& p4) const;
        double crossProduct(const double& x1, const double& y1, const double& x2, const double& y2) const;
        bool intersectingLines(const point& p1, const point& p2, const point& p3, const point& p4) const;
    public:
        void addPoint(const double& x, const double& y);
        bool intersectingFigures(const figure& _figure) const;
};