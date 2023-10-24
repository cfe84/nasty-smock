#ifndef ICONSUMER
#define ICONSUMER

#include <vector>
#include "Request.h"

using namespace std;

class IConsumer
{
public:
    /// @brief Get a list of requests that the consumer requires.
    /// @return List of requests
    virtual vector<Request *> *Require() = 0;

    /// @brief Deliver resources to the consumer
    /// @param resource
    /// @param quantity
    virtual void Deliver(Resource *resource, double quantity) = 0;
};

#endif