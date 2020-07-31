#include <iostream>
#include "figure.h"

int main()
{
    figure f1, f2;
    f1.addPoint(4, 1);
    f1.addPoint(7, 4);
    f1.addPoint(1, 4);

    f2.addPoint(1, 2);
    f2.addPoint(7, 2);
    f2.addPoint(4, 5);

    //f2.addPoint(1, 5);
    //f2.addPoint(7, 5);
    //f2.addPoint(4, 8);

    if(f1.intersectingFigures(f2))
    {
        std::cout << "These figures intersect!" << std::endl;
    }
    else
    {
        std::cout << "These figures do not intersect!" << std::endl;   
    }
    
    return EXIT_SUCCESS;
}