#ifndef REQUEST
#define REQUEST

#include "Resource.h"

class Request
{
    private:
        Resource* resource;
        double quantity;
    public:
        Request(Resource* resource, double quantity);
        Resource* getResource();
        double getQuantity();
};

#endif