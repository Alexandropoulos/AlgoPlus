#define CATCH_CONFIG_MAIN
#include "../../src/classes/tree/avl_tree.h"
#include "../catch2/catch.hpp"
#include <string>

TEST_CASE("checking insertions and traversals") {
  avl_tree<int> a1;
  avl_tree<char> a2;
  avl_tree<std::string> a3;

  a1.insert(10);
  a1.insert(15);
  a1.insert(4);
  a1.insert(-150);
  std::vector<int> v = {-150, 4, 10, 15};
  std::vector<int> inorder = a1.inorder();
  REQUIRE(v == inorder);

  a2.insert('g');
  a2.insert('d');
  a2.insert('w');
  a2.insert('o');
  std::vector<char> _v = {'d', 'g', 'o', 'w'};
  std::vector<char> _inorder = a2.inorder();
  REQUIRE(_v == _inorder);

  a3.insert("hello");
  a3.insert("from");
  a3.insert("mars");
  a3.insert("cheers");
  std::vector<std::string> __v = {"cheers", "from", "hello", "mars"};
  std::vector<std::string> __inorder = a3.inorder();
  REQUIRE(__v == __inorder);
}

TEST_CASE("checking removals") {
  avl_tree<int> a1;
  a1.insert(10);
  a1.insert(2);
  a1.insert(190);
  a1.insert(-20);
  a1.insert(23);
  a1.remove(190);
  std::vector<int> v = {-20, 2, 10, 23};
  std::vector<int> inorder = a1.inorder();
  REQUIRE(v == inorder);
}