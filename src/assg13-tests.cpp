/** @file assg13-tests.cpp
 * @brief Unit tests for Assignment Classes: practice on classes and user
 *   defined types.
 *
 * @author Mathis Rhoades
 * @note   class: COSC 2336, Summer 2024
 * @note   ide  : VSCode Server 3.9.3, Gnu Development Tools
 * @note   assg : Assignment STL
 * @date   December 5, 2024
 *
 * Assignment Standard Template Library STL.
 */
#include "catch.hpp"
#include "list.cpp"
#include "list.hpp"
#include <iostream>
#include <list>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

/** Task 1 example test task.  Demonstrate using an STL list
 * container.
 */
TEST_CASE("<list> test list STL container", "[task1]")
{
  // list of integers
  list<int> l1;

  // list should be initially empty
  CHECK(l1.empty());

  // add item, it is now not empty
  l1.push_front(5);
  CHECK_FALSE(l1.empty());
  CHECK(l1.size() == 1);
}

/** Task 1: Reimplement the queue assignment functions but use STL queue and stack objects 
 * instead of our hand built ones.
 */
TEST_CASE("queue test front() member method basic functionality", "[task1]")
{
  SECTION("test front on a queue of integer values")
  {
    // front value of queue of size 1
    queue<int> queue1;
    queue1.push(7);

    CHECK(queue1.size() == 1);
    CHECK_FALSE(queue1.empty());
    CHECK(queue1.front() == 7);
    CHECK(str(queue1) == "<queue> size: 1 front:[ 7 ]:back");

    // front value of queue of size 2
    queue<int> queue2;
    queue2.push(11);
    queue2.push(7);

    CHECK(queue2.size() == 2);
    CHECK_FALSE(queue2.empty());
    CHECK(queue2.front() == 11);
    CHECK(str(queue2) == "<queue> size: 2 front:[ 11, 7 ]:back");

    // front value of queue of size 3
    queue<int> queue3;
    queue3.push(42);
    queue3.push(11);
    queue3.push(7);

    CHECK(queue3.size() == 3);
    CHECK_FALSE(queue3.empty());
    CHECK(queue3.front() == 42);
    CHECK(str(queue3) == "<queue> size: 3 front:[ 42, 11, 7 ]:back");
  }

  SECTION("test front on a queue of string values")
  {
    // front value of queue of size 1
    queue<string> queue1;
    queue1.push("golf");

    CHECK(queue1.size() == 1);
    CHECK_FALSE(queue1.empty());
    CHECK(queue1.front() == "golf");
    CHECK(str(queue1) == "<queue> size: 1 front:[ golf ]:back");

    // front value of queue of size 2
    queue<string> queue2;
    queue2.push("kilo");
    queue2.push("golf");

    CHECK(queue2.size() == 2);
    CHECK_FALSE(queue2.empty());
    CHECK(queue2.front() == "kilo");
    CHECK(str(queue2) == "<queue> size: 2 front:[ kilo, golf ]:back");

    // front value of queue of size 3
    queue<string> queue3;
    queue3.push("thanks-for-the-fish");
    queue3.push("kilo");
    queue3.push("golf");

    CHECK(queue3.size() == 3);
    CHECK_FALSE(queue3.empty());
    CHECK(queue3.front() == "thanks-for-the-fish");
    CHECK(str(queue3) == "<queue> size: 3 front:[ thanks-for-the-fish, kilo, golf ]:back");
  }

  SECTION("test pop_front on a queue of integer values")
  {
    // initially queue has 3 items on it
    queue<int> queue;
    queue.push(42);
    queue.push(11);
    queue.push(7);

    CHECK(queue.size() == 3);
    CHECK_FALSE(queue.empty());
    CHECK(queue.front() == 42);
    CHECK(str(queue) == "<queue> size: 3 front:[ 42, 11, 7 ]:back");

    // pop the front item
    queue.pop();
    CHECK(queue.size() == 2);
    CHECK_FALSE(queue.empty());
    CHECK(queue.front() == 11);
    CHECK(str(queue) == "<queue> size: 2 front:[ 11, 7 ]:back");

    // pop the next item, queue size reduced to 1 item now
    queue.pop();
    CHECK(queue.size() == 1);
    CHECK_FALSE(queue.empty());
    CHECK(queue.front() == 7);
    CHECK(str(queue) == "<queue> size: 1 front:[ 7 ]:back");

    // pop the next item, queue should be empty now
    queue.pop();
    CHECK(queue.size() == 0);
    CHECK(queue.empty());
    CHECK(str(queue) == "<queue> size: 0 front:[ ]:back");
  }

  SECTION("test pop on a queue of string values")
  {
    // initially queue has 3 items on it
    queue<string> queue;
    queue.push("life-universe-everything");
    queue.push("kilo");
    queue.push("golf");

    CHECK(queue.size() == 3);
    CHECK_FALSE(queue.empty());
    CHECK(queue.front() == "life-universe-everything");
    CHECK(str(queue) == "<queue> size: 3 front:[ life-universe-everything, kilo, golf ]:back");

    // pop the front item
    queue.pop();
    CHECK(queue.size() == 2);
    CHECK_FALSE(queue.empty());
    CHECK(queue.front() == "kilo");
    CHECK(str(queue) == "<queue> size: 2 front:[ kilo, golf ]:back");

    // pop the next item, queue size reduced to 1 item now
    queue.pop();
    CHECK(queue.size() == 1);
    CHECK_FALSE(queue.empty());
    CHECK(queue.front() == "golf");
    CHECK(str(queue) == "<queue> size: 1 front:[ golf ]:back");

    // pop the next item, queue should be empty now
    queue.pop();
    CHECK(queue.size() == 0);
    CHECK(queue.empty());
    CHECK(str(queue) == "<queue> size: 0 front:[ ]:back");
  }

  SECTION("test pop on a queue of integer values")
  { // initially queue is empty
    queue<int> queue;
    CHECK(queue.size() == 0);
    CHECK(queue.empty());
    CHECK(str(queue) == "<queue> size: 0 front:[ ]:back");

    // push item on back of empty queue
    queue.push(7);
    CHECK(queue.size() == 1);
    CHECK_FALSE(queue.empty());
    CHECK(queue.front() == 7);
    CHECK(str(queue) == "<queue> size: 1 front:[ 7 ]:back");

    // push item where queue grows to size 2
    queue.push(11);
    CHECK(queue.size() == 2);
    CHECK_FALSE(queue.empty());
    CHECK(queue.front() == 7);
    CHECK(str(queue) == "<queue> size: 2 front:[ 7, 11 ]:back");

    // push item where queue grows to size 3
    queue.push(42);
    CHECK(queue.size() == 3);
    CHECK_FALSE(queue.empty());
    CHECK(queue.front() == 7);
    CHECK(str(queue) == "<queue> size: 3 front:[ 7, 11, 42 ]:back");
  }
}
