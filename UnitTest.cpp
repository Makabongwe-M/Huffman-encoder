#define CATCH_CONFIG_MAIN //So that catch will define a main method
#include "catch.hpp"
#include "HuffmanTree"
#include "HuffmanNode"
#include <vector>
#include <iostream>

TEST_CASE("Create Map", "This will test the createMap function in the HuffmanTree class"){
  std::vector<HuffmanNode> nodes;
  HuffmanNode object1('l', 5);
  HuffmanNode object2('H', 6);
  HuffmanNode object3('o', 10);
  HuffmanNode object4('G', 15);
  HuffmanNode object5('k', 8);
  HuffmanNode object6('k', 8);

  nodes.push_back(object1);
  nodes.push_back(object2);
  nodes.push_back(object3);
  nodes.push_back(object4);
  nodes.push_back(object5);
  nodes.push_back(object6);

	REQUIRE(nodes.size() == 5);

}
