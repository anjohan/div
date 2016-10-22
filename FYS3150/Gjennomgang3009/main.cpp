#include "vec3.h"
#include <cstdio>

int main(int argc, char *argv[]){
    vec3 a;
    printf("%.3f\n",a.x());
    vec3 b(1,2,3);
    printf("%.3f\n",b.x());
    printf("%.3f\n",b(2));
    a += b;
    vec3 c = a + b;
    printf("%.3f\n",c(1));
    return 0;
}
