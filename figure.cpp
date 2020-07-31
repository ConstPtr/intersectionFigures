#include "figure.h"

void figure::addPoint(const double& x, const double& y)
{
    point temp;
    temp._x = x;
    temp._y = y;
    _points.push_back(temp);
}

point figure::getPoint(const int& _numOfElem) const
{
    if(_points.empty())
        throw std::logic_error("No points!");
    if(_points.size() > _numOfElem)
        return _points.at(_numOfElem);
    if(_points.size() == _numOfElem)
        return _points.at(0);
    if(_points.size() < _numOfElem)
        throw std::logic_error("Wrong point number");
}

int figure::numOfLines() const
{
    return _points.size();
}

bool figure::comparePoints(const point& p1, const point& p2, const point& p3, const point& p4) const
{
    if(p1._x == p3._x && p1._y == p3._y ||
       p1._x == p4._x && p1._y == p4._y || 
       p2._x == p3._x && p2._y == p3._y || 
       p2._x == p4._x && p2._y == p4._y)
        return true;
    return false;
}

bool figure::checkPointAndLine(const point& p1, const point& p2, const point& p3) const
{
    auto expr1 = sqrt(pow(p1._x - p3._x, 2) + pow(p1._y - p3._y, 2));
    auto expr2 = sqrt(pow(p2._x - p3._x, 2) + pow(p2._y - p3._y, 2));
    auto expr3 = sqrt(pow(p2._x - p1._x, 2) + pow(p2._y - p1._y, 2));
    if(abs(expr1 + expr2 - expr3) < 0.01)
        return true;
    return false;
}

bool figure::pointsOnLines(const point& p1, const point& p2, const point& p3, const point& p4) const
{
    if(checkPointAndLine(p1, p2, p3) == true || 
       checkPointAndLine(p1, p2, p4) == true || 
       checkPointAndLine(p3, p4, p1) == true || 
       checkPointAndLine(p3, p4, p2) == true)
        return true;
    return false;
}

double figure::crossProduct(const double& x1, const double& y1, const double& x2, const double& y2) const
{
    return x1 * y2 - x2 * y1;
}

bool figure::intersectingLines(const point& p1, const point& p2, const point& p3, const point& p4) const
{
    double vector1 = crossProduct(p4._x - p3._x, p4._y - p3._y, p1._x - p3._x, p1._y - p3._y);
    double vector2 = crossProduct(p4._x - p3._x, p4._y - p3._y, p2._x - p3._x, p2._y - p3._y);
    double vector3 = crossProduct(p2._x - p1._x, p2._y - p1._y, p3._x - p1._x, p3._y - p1._y);
    double vector4 = crossProduct(p2._x - p1._x, p2._y - p1._y, p4._x - p1._x, p4._y - p1._y);
    if((vector1 * vector2) < 0 && (vector3 * vector4) < 0)
        return true;
    return false;
}

bool figure::intersectingFigures(const figure& _figure) const
{
    if(_points.empty())
        throw std::logic_error("No points!");
    bool statusPoints = NULL;
    bool statusLines = NULL;
    bool statusPointsOnLines = NULL;

    for(int i = 0; i < numOfLines();)
    {
        point point1, point2;
        try
        {
            point1 = getPoint(i);
            point2 = getPoint(++i);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            exit(EXIT_FAILURE);
        }
        for(int j = 0; j < _figure.numOfLines();)
        {
            point point3, point4;
            try
            {
                point3 = _figure.getPoint(j);
                point4 = _figure.getPoint(++j);
            }
            catch(const std::exception& e)
            {
                std::cerr << e.what() << '\n';
                exit(EXIT_FAILURE);
            }
            
            statusPointsOnLines = pointsOnLines(point1, point2, point3, point4);
            statusPoints = comparePoints(point1, point2, point3, point4);
            statusLines = intersectingLines(point1, point2, point3, point4);
            if(statusPoints == true || statusLines == true || statusPointsOnLines == true)
                return true;
        }
    }
    return false;
}