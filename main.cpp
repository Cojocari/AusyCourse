#include <iostream>
#include "headers/min.h"
#include "headers/max.h"

int main()
{
    int n1, n2, n3;
    float f1, f2, f3;
    std::string type;
    std::string selection;
    bool done = false;
    std::cout << "Select type float or int ";
    std::cin >> type;
    while(!done)
    {
        if(!type.compare("int"))
        {
            std::cout << "First number : ";
            std::cin >> n1;
            std::cout << "Second number : ";
            std::cin >> n2;
            std::cout << "Third number : ";
            std::cin >> n3;
            done = true;
        }
        else if(!type.compare("float"))
        {
            std::cout << "First number : ";
            std::cin >> f1;
            std::cout << "Second number : ";
            std::cin >> f2;
            std::cout << "Third number : ";
            std::cin >> f3;
            done = true;
        }
        else{
            std::cout << "Wrong arg.\n Select again type int or float : ";
            std::cin >> selection;
        }
    }

    std::cout << "Select min or max ";
    std::cin >> selection;

    done = false;
    while(!done)
    {
        if(!selection.compare("min"))
        {
            Min n;
            if(!type.compare("int"))
            {   
                std::cout << n.getMin(n1,n2,n3) << std::endl;
            }
            else
            {
               std::cout << n.getMin(f1,f2,f3) << std::endl; 
            }
            done = true;
        }
        else if(!selection.compare("max"))
        {
            Max m;
            if(!type.compare("int"))
            {  
                std::cout << m.getMax(n1,n2,n3) << std::endl;
            }
            else
            {
                std::cout << m.getMax(f1,f2,f3) << std::endl;
            }
            done = true;
        }
        else
        {
            std::cout << "Wrong arg.\n Select again min or max : ";
            std::cin >> selection;
        }
    }
    return 0;
}