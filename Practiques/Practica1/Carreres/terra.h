#ifndef TERRA_H
#define TERRA_H
#include <objecte.h>

class Terra: public Objecte
{
    void quad( int a, int b, int c, int d );
public:
    Terra();
    void make();
};

#endif // TERRA_H
