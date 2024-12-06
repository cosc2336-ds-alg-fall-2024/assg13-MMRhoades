/** @file list.cpp
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
#include "list.hpp"
#include <iostream>
#include <list>
#include <queue>
#include <sstream>
#include <string>
using namespace std;

/**
 * @brief Queue<int> to string
 *
 * Accessor method to construct and return a string representation
 * of the current values and status of this Queue instance.
 *
 * @returns string Returns the string constructed with the information
 *   about this Queue.
 */
string str(queue<int> queue)
{
  // create string of text
  ostringstream out;

  // stream queue information into the output stream
  out << "<queue> size: " << queue.size() << " front:[ ";

  // stream the current values of the queue to the output stream
  // start with values in format until the last value
  while(!queue.empty() and queue.size() > 1)
{
  out << queue.front() << ", ";
  queue.pop();
}

// at the last value, we don't want a comma
if (queue.size() == 1)
{
  out << queue.front() << " ";
}

out << "]:back";
return out.str();
}

/**
 * @brief Queue<string> to string
 *
 * Accessor method to construct and return a string representation
 * of the current values and status of this Queue instance.
 *
 * @returns string Returns the string constructed with the information
 *   about this Queue.
 */
string str(queue<string> queue)
{
  // create string of text
  ostringstream out;

  // stream queue information into the output stream
  out << "<queue> size: " << queue.size() << " front:[ ";

  // stream the current values of the queue to the output stream
  // start with values in format until the last value
  while (!queue.empty() and queue.size() > 1)
  {
    out << queue.front() << ", ";
    queue.pop();
  }

  // at the last value, we don't want a comma
  if (queue.size() == 1)
  {
    out << queue.front() << " ";
  }

  out << "]:back";
  return out.str();
}