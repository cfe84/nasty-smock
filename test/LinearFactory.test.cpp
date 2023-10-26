#include <iostream>
#include <list>
#include "UnitTest++/UnitTest++.h"

#include "../src/LinearFactory.h"
#include "../src/IProducer.h"
#include "../src/QuantifiedResource.h"
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
        vector<QuantifiedResource *> *requests = factory.GetRequests();

        // then
        CHECK_EQUAL(1, availableResources->size());
        CHECK_EQUAL(&outputResource, (*availableResources)[0]);
        CHECK_EQUAL(1, requests->size());
        CHECK_EQUAL(0, (*requests)[0]->getQuantity());
        CHECK_EQUAL(&inputResource, (*requests)[0]->getResource());
    }

    QuantifiedResource *firstQuantifiedResource(vector<QuantifiedResource *> * requests)
    {
        return (*requests)[0];
    }

    TEST(LinearFactory_should_RequireTheRightAmount)
    {
        // given
        LinearFactory factory = LinearFactory(&inputResource, &outputResource, ratio);

        // when
        factory.RequestProduction(&outputResource, requestedQuantity);
        auto productions = factory.Produce();
        auto produced = firstQuantifiedResource(productions);
        auto requests = factory.GetRequests();
        auto request = firstQuantifiedResource(requests);

        // then
        CHECK_EQUAL(requestedQuantity * ratio, request->getQuantity()); // Require right quantity
        CHECK_EQUAL(0, produced->getQuantity());                        // No stock, produce 0.
    }

    TEST(LinearFactory_should_ProduceTheRequiredAmount_WhenDeliveredInFull)
    {
        // given
        LinearFactory factory = LinearFactory(&inputResource, &outputResource, ratio);

        // when
        // request to initiate the require
        factory.RequestProduction(&outputResource, requestedQuantity);
        auto requests = factory.GetRequests();
        auto request = firstQuantifiedResource(requests);
        factory.Deliver(request); // deliver in full
        factory.RequestProduction(&outputResource, requestedQuantity);
        auto production = factory.Produce();
        auto produced = firstQuantifiedResource(production);

        // then
        CHECK_EQUAL(requestedQuantity, produced->getQuantity());
    }

    TEST(LinearFactory_should_NotProduceOnceEmpty)
    {
        // given
        LinearFactory factory = LinearFactory(&inputResource, &outputResource, ratio);

        // when
        // request to initiate the require
        factory.RequestProduction(&outputResource, requestedQuantity);
        // first production
        auto requests = factory.GetRequests();
        auto request = firstQuantifiedResource(requests);
        factory.Deliver(request); // deliver in full
        factory.RequestProduction(&outputResource, requestedQuantity);
        factory.Produce();

        // Second production
        requests = factory.GetRequests();
        request = firstQuantifiedResource(requests);
        factory.RequestProduction(&outputResource, requestedQuantity);
        auto production = factory.Produce();
        auto producedInSecondRound = firstQuantifiedResource(production);

        // then
        CHECK_EQUAL(requestedQuantity * ratio, request->getQuantity());
        CHECK_EQUAL(0, producedInSecondRound->getQuantity());
    }

    TEST(LinearFactory_should_ProduceHalfAmount_WhenDeliveredHalf)
    {
        // given
        LinearFactory factory = LinearFactory(&inputResource, &outputResource, ratio);

        // when
        // request to initiate the require
        factory.RequestProduction(&outputResource, requestedQuantity);
        auto requests = factory.GetRequests();
        auto request = firstQuantifiedResource(requests);
        auto delivery = new QuantifiedResource(request->getResource(), request->getQuantity() / 2);
        factory.Deliver(delivery); // deliver in half
        factory.RequestProduction(&outputResource, requestedQuantity);
        auto production = factory.Produce();
        auto produced = firstQuantifiedResource(production);

        // then
        CHECK_EQUAL(requestedQuantity / 2, produced->getQuantity());
    }
}