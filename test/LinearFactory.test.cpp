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
    Resource inputResource = Resource("input");
    Resource outputResource = Resource("output");
    LinearFactory factory = LinearFactory(&inputResource, &outputResource, 2.0);

    // when
    vector<Resource*>* availableResources = factory.AvailableResources();
    vector<Request*>* requests = factory.GetRequests();

    // then
    CHECK_EQUAL(1, availableResources->size());
    CHECK_EQUAL(&outputResource, (*availableResources)[0]);

    CHECK_EQUAL(1, requests->size());
    CHECK_EQUAL(0, (*requests)[0]->getQuantity());
    CHECK_EQUAL(&inputResource, (*requests)[0]->getResource());
}