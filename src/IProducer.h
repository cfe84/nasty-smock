#ifndef IPRODUCER
#define IPRODUCER

#include <vector>

using namespace std;

class IProducer
{
public:
    /// @brief Get the resources that this producer can produced
    /// @return Resources that can be produced
    virtual vector<Resource *> *AvailableResources() = 0;
    /// @brief Ask the producer to produce a quantity of a resource
    /// @param resource Reference to the resource to be produced
    /// @param quantity Quantity asked
    /// @return Quantity that was effectively produced.
    virtual double Produce(Resource *resource, double quantity) = 0;
};

#endif