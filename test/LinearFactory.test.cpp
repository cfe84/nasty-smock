#include <iostream>
#include <list>
#include "UnitTest++/UnitTest++.h"

#include "../src/LinearFactory.h"
#include "../src/IProducer.h"
#include "../src/Request.h"
#include "../src/Resource.h"

using namespace std;

TEST(LinearFactory)
{
    // given
    double ratio = 3;
    double requestedQuantity = 2;
    Resource inputResource = Resource("input");
    Resource outputResource = Resource("output");
    LinearFactory factory = LinearFactory(&inputResource, &outputResource, ratio);

    // when
    vector<Resource*>* availableResources = factory.AvailableResources();
    vector<Request*>* requests = factory.Require();

    // then 1. nothing required yet.
    CHECK_EQUAL(1, availableResources->size());
    CHECK_EQUAL(&outputResource, (*availableResources)[0]);
    CHECK_EQUAL(1, requests->size());
    CHECK_EQUAL(0, (*requests)[0]->getQuantity());
    CHECK_EQUAL(&inputResource, (*requests)[0]->getResource());
    auto producedQuantity = factory.Produce(&outputResource, requestedQuantity);
    CHECK_EQUAL(0, producedQuantity); // No stock, produce 0.
    
    // then 2. require 
    requests = factory.Require();
    CHECK_EQUAL(1, availableResources->size());
    CHECK_EQUAL(requestedQuantity * ratio, (*requests)[0]->getQuantity());
    factory.Deliver(&inputResource, requestedQuantity * ratio);
    producedQuantity = factory.Produce(&outputResource, requestedQuantity);
    CHECK_EQUAL(requestedQuantity, producedQuantity);

    // then 3. require again but without more input.
    requests = factory.Require();
    producedQuantity = factory.Produce(&outputResource, requestedQuantity);
    CHECK_EQUAL(0, producedQuantity);
}