#include "UnitTest++/UnitTest++.h"

#include "../src/Resource.h"
#include "../src/QuantifiedResource.h"
#include "../src/StaticConsumer.h"

SUITE(StaticConsumer)
{
  TEST(should_provide_requests_based_on_initializer)
  {
    // given
    auto resource1 = new Resource("resource1");
    double quantity1 = 10;
    auto resource2 = new Resource("resource2");
    double quantity2 = 20;
    auto consumer = StaticConsumer({new QuantifiedResource(resource1, quantity1),
                                    new QuantifiedResource(resource2, quantity2)});

    // when
    auto request = consumer.GetRequests();

    // then
    CHECK_EQUAL(2, request.size());
    auto requestedQResource1 = request[0];
    auto requestedQResource2 = request[1];
    CHECK_EQUAL(resource1, requestedQResource1.getResource());
    CHECK_EQUAL(quantity1, requestedQResource1.getQuantity());
    CHECK_EQUAL(resource2, requestedQResource2.getResource());
    CHECK_EQUAL(quantity2, requestedQResource2.getQuantity());
  }

  // TEST(should_provide_requests_as_copies)
  // {
  //   // given
  //   auto resource = new Resource("resource1");
  //   double quantity = 10;
  //   auto consumer = StaticConsumer({new QuantifiedResource(resource, quantity)});

  //   // when
  //   auto request1 = consumer.GetRequests();
  //   auto request2 = consumer.GetRequests();

  //   // then
  //   CHECK(request1 != request2);
  //   CHECK(request1[0] != request2[0]);
  // }

  TEST(should_track_consumption)
  {
    // given
    auto resource1 = new Resource("resource1");
    double quantity1 = 10;
    auto resource2 = new Resource("resource2");
    double quantity2 = 20;
    auto consumer = StaticConsumer({new QuantifiedResource(resource1, quantity1),
                                    new QuantifiedResource(resource2, quantity2)});
    double deliveredQuantity11 = 10;
    double deliveredQuantity12 = 20;
    double deliveredQuantity21 = 50;

    // when
    auto delivery1 = QuantifiedResource(resource1, deliveredQuantity11);
    auto delivery2 = QuantifiedResource(resource2, deliveredQuantity21);
    auto delivery3 = QuantifiedResource(resource1, deliveredQuantity12);
    consumer.Deliver(&delivery1);
    consumer.Deliver(&delivery2);
    consumer.Deliver(&delivery3);
    auto consumption = *consumer.GetConsumption();

    // then
    CHECK_EQUAL(2, consumption.size());
    CHECK_EQUAL(deliveredQuantity11 + deliveredQuantity12, consumption[resource1]);
    CHECK_EQUAL(deliveredQuantity21, consumption[resource2]);
  }
}