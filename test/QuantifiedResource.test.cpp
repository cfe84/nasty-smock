#include "UnitTest++/UnitTest++.h"

#include "../src/Resource.h"
#include "../src/QuantifiedResource.h"

SUITE(QuantifiedResource)
{
  TEST(ShouldCloneCorrectly)
  {
    // Given
    auto resource = new Resource("resource");
    double quantity = 102;
    auto originalQuantifiedResource = new QuantifiedResource(resource, quantity);

    // when
    auto copiedQuantifiedResource = new QuantifiedResource(originalQuantifiedResource);

    // then
    CHECK(copiedQuantifiedResource != originalQuantifiedResource);
    CHECK_EQUAL(resource, copiedQuantifiedResource->getResource());
    CHECK_EQUAL(quantity, copiedQuantifiedResource->getQuantity());
  }
}