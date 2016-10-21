#include "vec.h"

double norm(vec v){
    return sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}
