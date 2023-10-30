#ifndef ICONSUMER
#define ICONSUMER

#include <vector>
#include "QuantifiedResource.h"

using namespace std;

class IConsumer
{
public:
    /// @brief Get a list of requests that the consumer requires.
    /// @return List of requests
    virtual vector<QuantifiedResource> GetRequests() = 0;

    /// @brief Deliver resources to the consumer
    /// @param resource
    /// @param quantity
    virtual void Deliver(QuantifiedResource resource) = 0;
};

#endif