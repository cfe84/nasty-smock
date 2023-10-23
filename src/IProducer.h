#ifndef IPRODUCER
#define IPRODUCER

#include <vector>

using namespace std;

class IProducer
{
    public:
        virtual vector<Resource*>* AvailableResources() = 0;
        virtual double Produce(Resource* resource, double quantity) = 0;
};

#endif