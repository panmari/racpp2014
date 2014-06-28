#include <iostream>
#include "vector3f.h"
#include <boost/numeric/ublas/io.hpp>
#include "mandelbrot.h"
#include "core_utils.h"

//using namespace std;

int main()
{
    Vector3f v1;
    v1 = Vector3f(1,1,1);
    Vector3f v2 = Vector3f(1,1,1);
    std::cout << v1 + v2 << std::endl;
}

