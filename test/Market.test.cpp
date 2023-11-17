#include <iostream>
#include <list>
#include "UnitTest++/UnitTest++.h"

#include "../src/IConsumer.h"
#include "../src/LinearFactory.h"
#include "../src/QuantifiedResource.h"

using namespace std;

Resource resource1 = Resource("r1");
double requestedQuantity1 = 2;

class FakeConsumer : public IConsumer
{
    vector<QuantifiedResource> request = vector<QuantifiedResource>{QuantifiedResource(&resource1, requestedQuantity1)};

public:
    FakeConsumer(){};
    double delivered = 0;
    vector<QuantifiedResource> GetRequests() override
    {
        return request;
    };

    /// @brief Deliver resources to the consumer
    /// @param resource
    /// @param quantity
    void Deliver(QuantifiedResource resource) override
    {
        CHECK_EQUAL(&resource1, resource.getResource());
        delivered += resource.getQuantity();
    };
};

class FakeProducer : public IProducer
{
    Resource *resource;
    vector<Resource *> *resources;

public:
    double requestedProduction = 0;
    FakeProducer(Resource *resource)
    {
        this->resources = new vector<Resource *>{resource};
        this->resource = resource;
    }

    vector<Resource *> *AvailableResources() override
    {
        return resources;
    }

    void RequestProduction(Resource *resource, double quantity) override
    {
        CHECK_EQUAL(this->resource, resource);
        requestedProduction += quantity;
    }

    /// @brief Trigger production of resources
    /// @return Resources that have been produced
    vector<QuantifiedResource> Produce() override{

    };
}

SUITE(LinearFactory){
    TEST(should_make_requests){
        // given
        auto consumer = FakeConsumer();
    }
}
;
