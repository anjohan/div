#include <cstdio>
#include "vec3.h"

int main(){
    vec3 a(1,2,3);
    printf("a: "); a.print();
    printf("a*0.01: "); (a*0.01).print();
}
