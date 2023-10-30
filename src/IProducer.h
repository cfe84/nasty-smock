#ifndef IPRODUCER
#define IPRODUCER

#include <vector>
#include "./QuantifiedResource.h"

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
    virtual void RequestProduction(Resource *resource, double quantity) = 0;

    /// @brief Trigger production of resources
    /// @return Resources that have been produced
    virtual vector<QuantifiedResource> Produce() = 0;
};

#endif