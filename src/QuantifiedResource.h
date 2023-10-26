#ifndef QUANTIFIEDRESOURCE
#define QUANTIFIEDRESOURCE

#include "Resource.h"

class QuantifiedResource
{
private:
    Resource *resource;
    double quantity;

public:
    QuantifiedResource(Resource *resource, double quantity);
    Resource *getResource();
    double getQuantity();
};

#endif