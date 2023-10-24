#include <iostream>
#include <list>
#include "UnitTest++/UnitTest++.h"

#include "../src/LinearFactory.h"
#include "../src/IProducer.h"
#include "../src/Request.h"
#include "../src/Resource.h"

using namespace std;

double ratio = 3;
double requestedQuantity = 2;
Resource inputResource = Resource("input");
Resource outputResource = Resource("output");

SUITE(LinearFactory)
{

    TEST(LinearFactoryReturns0WhenNothingRequired)
    {
        // given
        LinearFactory factory = LinearFactory(&inputResource, &outputResource, 0);

        // when
        vector<Resource *> *availableResources = factory.AvailableResources();
        vector<Request *> *requests = factory.Require();

        // then
        CHECK_EQUAL(1, availableResources->size());
        CHECK_EQUAL(&outputResource, (*availableResources)[0]);
        CHECK_EQUAL(1, requests->size());
        CHECK_EQUAL(0, (*requests)[0]->getQuantity());
        CHECK_EQUAL(&inputResource, (*requests)[0]->getResource());
    }

    Request *firstRequest(vector<Request *> * requests)
    {
        return (*requests)[0];
    }

    TEST(LinearFactory_should_RequireTheRightAmount)
    {
        // given
        LinearFactory factory = LinearFactory(&inputResource, &outputResource, ratio);

        // when
        auto producedQuantity = factory.Produce(&outputResource, requestedQuantity);
        auto requests = factory.Require();
        auto request = firstRequest(requests);

        // then
        CHECK_EQUAL(requestedQuantity * ratio, request->getQuantity()); // Require right quantity
        CHECK_EQUAL(0, producedQuantity);                               // No stock, produce 0.
    }

    TEST(LinearFactory_should_ProduceTheRequiredAmount_WhenDeliveredInFull)
    {
        // given
        LinearFactory factory = LinearFactory(&inputResource, &outputResource, ratio);

        // when
        // request to initiate the require
        factory.Produce(&outputResource, requestedQuantity);
        auto requests = factory.Require();
        auto request = firstRequest(requests);
        factory.Deliver(request->getResource(), request->getQuantity()); // deliver in full
        double producedQuantity = factory.Produce(&outputResource, requestedQuantity);

        // then
        CHECK_EQUAL(requestedQuantity, producedQuantity);
    }

    TEST(LinearFactory_should_NotProduceOnceEmpty)
    {
        // given
        LinearFactory factory = LinearFactory(&inputResource, &outputResource, ratio);

        // when
        // request to initiate the require
        factory.Produce(&outputResource, requestedQuantity);
        auto requests = factory.Require();
        auto request = firstRequest(requests);
        factory.Deliver(request->getResource(), request->getQuantity()); // deliver in full
        factory.Produce(&outputResource, requestedQuantity);
        requests = factory.Require();
        request = firstRequest(requests);
        double producedQuantityInSecondRound = factory.Produce(&outputResource, requestedQuantity);

        // then
        CHECK_EQUAL(requestedQuantity * ratio, request->getQuantity());
        CHECK_EQUAL(0, producedQuantityInSecondRound);
    }

    TEST(LinearFactory_should_ProduceHalfAmount_WhenDeliveredHalf)
    {
        // given
        LinearFactory factory = LinearFactory(&inputResource, &outputResource, ratio);

        // when
        // request to initiate the require
        factory.Produce(&outputResource, requestedQuantity);
        auto requests = factory.Require();
        auto request = (*requests)[0];
        factory.Deliver(request->getResource(), request->getQuantity() / 2); // deliver in half
        double producedQuantity = factory.Produce(&outputResource, requestedQuantity);

        // then
        CHECK_EQUAL(requestedQuantity / 2, producedQuantity);
    }
}