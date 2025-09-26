/**
  * @file brain.cpp
  * This is the documentation of the `cluster.cpp` file
  *
  * @brief Description
  * Implementation of the Cluster class virtual methods and other methods,
  * also the implementation of its operators such as <<.
  *
  * COPYRIGHT: Copyright © 2025 Tomascord
  *
  * LICENSE: Apache 2.0, See: @see @link LICENSE.md @endlink
*/

// C++ libraries imports
#include <iostream>
#include <cmath>

// Nativite engine imports
#include "cluster.hpp"

/**
  * @internal
  * The `Cluster::isValueNullptr` method is internal of the `Cluster` class
  * 
  * @brief Description
  * Evaluates if the suggested `cluster_t* value` is `nullptr` or is `NULL`
  * 
  * @return
  * Returns a boolean, true if value if the previous expresion is right
*/


bool Cluster::isValueNullptr(cluster_t* value) {
  return 
    value == nullptr ||
    value == NULL;
}


/**
  * @internal
  * The `Cluster::isSubValueNullptr` method is internal of the `CLuster` class
  * 
  * @brief Description
  * Evaluates if the suggested `cluster_subv_t value` is `nullptr` or is `NULL`
  * 
  * @return
  * Returns a boolean, true if value if the previous expresion is right
*/


bool Cluster::isSubValueNullptr(cluster_subv_t value) {
  return 
    value == nullptr ||
    value == NULL;
}


/**
  * @internal
  * The `Cluster::hasDisponibleCapacity` method is internal of the `Cluster` class
  * 
  * @brief Description
  * Evaluates if `cluster.size()` is less than the capacity field
  * 
  * @return
  * Returns a boolean, true if value if the previous expresion is right
*/


bool Cluster::hasDisponibleCapacity() {
  return cluster.size() < cluster_capacity;
}


/**
  * @internal
  * The `Cluster::resizeVec` method is internal of the `Cluster` class
  * 
  * @brief Description
  * Resizes the capacity of the vector by adding more capacity to the 
  * `cluster` field vector, the function is used to reserve capacity to the vector
  * 
  * @return
  * This function does not return anything, since it
  * only resizes the capacity of the vector.
*/


void Cluster::resizeVec() {
  cluster_capacity += 15;
  cluster.resize(cluster_capacity);
}


/**
  * @internal
  * The `Cluster::newVec` method is internal of the `Cluster` class
  * 
  * @brief Description
  * Create a new vector for the `cluster` field
  * 
  * @return
  * This function does not return anything, since it
  * only creates a new vector for the `cluster` field
*/


void Cluster::newVec() {
  cluster = std::vector<Bucket*>(cluster_capacity);
}


/**
  * @internal
  * The `Cluster::evaluateCapacity` method is internal of the `Cluster` class
  * 
  * @brief Description
  * Evaluates with a switch case, if the capacity parameter is zero,
  * calls `Cluster::assignDefaultCapacity` to assign a default capacity, in the default case,
  * calls `Cluster::assignCapacity` with the `capacity` param and assign the capacity to the
  * `cluster_capacity` field the capacity
  * 
  * @return
  * This function does not return anything, since it
  * only evaluates with a switch case the capacity
*/


void Cluster::evaluateCapacity(size_t capacity) {
  switch (capacity) {
    case 0:
      assignDefaultCapacity();
      break;
    default:
      assignCapacity(capacity);
      break;
  }
}


/**
  * @internal
  * The `Cluster::evaluateNullptrInAssignation` method is internal of the `Cluster` class
  * 
  * @brief Description
  * Evaluates if the value if is nullptr or NULL or not,
  * if not, the `cluster` field push `value` to the `cluster` vector
  * 
  * @return
  * This function does not return anything, since it
  * only evaluates if the value is nullptr or NULL or not, and if it is
  * not nullptr the `value` is pushed to the `cluster` field of the class
*/


void Cluster::evaluateNullptrInAssignation(cluster_subv_t value) {
  if (!isSubValueNullptr(value)) {
    pushObjectValue(value);
  }
}


/**
  * @internal
  * The `Cluster::pushObjectValue` method is internal of the `Cluster` class
  * 
  * @brief Description
  * push to `cluster` the `value`, this function is
  * used to push the value if `value` is not nullptr or NULL
  * 
  * @return
  * This function does not return anything, since it
  * only push to `cluster` the `value`
*/


void Cluster::pushObjectValue(cluster_subv_t value) {
  cluster.push_back(value);
}


/**
  * @internal
  * The `Cluster::assignDefaultCapacity` method is internal of the `Cluster` class
  * 
  * @brief Description
  * assign a default capacity to the `cluster_capacity` field the capacity: 15
  * 
  * @return
  * This function does not return anything, since it
  * only assign 15 to the `cluster_capacity` field
*/


void Cluster::assignDefaultCapacity() {
  cluster_capacity = 15;
}


/**
  * @internal
  * The `Cluster::assignCapacity` method is internal of the `Cluster` class
  * 
  * @brief Description
  * assign a capacity to the `cluster_capacity` field the suggested capacity
  * 
  * @return
  * This function does not return anything, since it
  * only assign the suggested capacity to the `brain_capacity` field
*/


void Cluster::assignCapacity(size_t capacity) {
  cluster_capacity = capacity;
}


/**
  * @internal
  * The `Cluster::defaultNullptrVec` method is internal of the `Cluster` class
  * 
  * @brief Description
  * assign to `cluster` field a default nullptr vector, if `cluster_v` in the constructor
  * of the class is nullptr or NULL
  * 
  * @return
  * This function does not return anything, since it
  * only assign a nullptr vec to `cluster` field
*/


void Cluster::defaultNullptrVec() {
  int index = 0;

  while (index < cluster_capacity) {
    cluster[index] = nullptr;
    index++;
  }
}


/**
  * @internal
  * The `Cluster::deleteInternalObject` method is internal of the `Cluster` class
  * 
  * @brief Description
  * delete the suggested value using `delete value;` and `value = nullptr;`
  * 
  * @return
  * This function does not return anything, since it
  * only delete the suggested value
*/


void Cluster::deleteInternalObject(cluster_subv_t value) {
  delete value;
  value = nullptr;
}


/**
  * @internal
  * The `Cluster::deleteAllFields` method is internal of the `Cluster` class
  * 
  * @brief Description
  * reset all fields, cleaning the `cluster` field and reset to 0 the `cluster_capacity` field
  * 
  * @return
  * This function does not return anything, since it
  * only delete all fields of the class
*/

void Cluster::deleteAllFields() {
  cluster.clear();
  cluster_capacity = 0;
}


/**
  * @internal
  * The `Cluster::pushClusterObjectToBrain` method is internal of the `Cluster` class
  * 
  * @brief Description
  * add to the `Brain` class the actual `Cluster` object
  * 
  * @return
  * This function does not return anything, since it
  * only add to the `Brain` class the `Cluster` object
*/


void Cluster::pushClusterObjectToBrain() {
  brain.push_back(this);
}


/**
  * @internal
  * The `Cluster::newTerminal` method is internal of the `Cluster` class
  * @brief Description
  * create a new `Terminal` object that is a cache for the most consulted elements in queries
  * 
  * @return
  * This function does not return anything, since it
  * only create a new `Terminal` object
*/


void Cluster::newTerminal() {
  terminal = new Terminal(nullptr);
}


/**
  * @internal
  * The `Cluster::abstractBuild` method is internal of the `Cluster` class
  * 
  * @brief Description
  * build the `cluster` field according to different conditions
  * 
  * @return
  * This function does not return anything, since it
  * only build the `cluster` field
*/


void Cluster::abstractBuild(
  cluster_t* value,
  size_t capacity
) {
  std::cout << "Executing Cluster::build...\n";

  evaluateCapacity(capacity);
  newVec();
  if (isValueNullptr(value)) {
    std::cout << "There is no value to copy for cluster field in Cluster class\n";
    std::cout << "Building a 15 nullptr vector...\n";

    defaultNullptrVec();

    std::cout << "Vector of 15 nullptr for Cluster class is built\n\n";
    return;
  } else {
    size_t index = 0;

    while (index < value->size()) {
      if (hasDisponibleCapacity()) {
        evaluateNullptrInAssignation(value->at(index));
      } else {
        resizeVec();
        evaluateNullptrInAssignation(value->at(index));
      }
      index++;
    }

    std::cout << "Cluster::cluster is built\n\n";
  }
}


/**
  * @internal
  * The `Cluster::build` method is internal of the `Cluster` class
  * 
  * @brief Description
  * build the `cluster` field according to different conditions, this function
  * uses the function `Cluster::abstractBuild` To avoid repeating the logic twice,
  * the cluster type object is also added to the Brain.
  * 
  * @return
  * This function does not return anything, since it
  * only build the `cluster` field and add to the `Brain` the
  * `Cluster` object
*/


void Cluster::build(
  cluster_t* value,
  size_t capacity,
  bool add
) {
  if (
    add == true
  ) {
    abstractBuild(value, capacity);
    if (brain.size() < brain_capacity) {
      pushClusterObjectToBrain();
    } else {
      resizeVec();
      pushClusterObjectToBrain();
    }
  } else {
    abstractBuild(value, capacity);
  }
}


/**
  * @internal
  * The `Cluster::destroy` method is internal of the `cluster` class
  * 
  * @brief Description
  * destroy the `cluster` deleting all `Bucket*` objects and reset the 
  * `cluster_capacity` field to 0
  * 
  * @return
  * This function does not return anything, since it
  * only destroy the `cluster` field and reset `cluster_capacity`
  * to 0
*/


void Cluster::destroy() {
  for (
    auto bucket : cluster
  ) {
    if (!isSubValueNullptr(bucket)) {
      deleteInternalObject(bucket);
    }
  }
  deleteAllFields();
}


/**
  * @internal
  * The `Cluster::Cluster` method is internal of the `Cluster` class
  *
  * The constructor of the `Cluster` class
  *
  * It handles several things, such as checking if the value to be assigned is
  * nullptr or NULL, it also handles capacity assignment, creating a new vector
  * for `cluster`, resizing the `cluster` vector.
*/


Cluster::Cluster(
  cluster_t* cluster_v,
  size_t capacity
) : 
  Brain(),
  Terminal() {
  build(cluster_v, capacity, true);
}


/**
  * @internal
  * The `Cluster::~Cluster` method is internal of the `Cluster` class
  *
  * The destructor of the `Cluster` class
  *
  * It handles how to check if a value is nullptr or NULL when deleting one by one
  * This prevents freeing memory to nullptr or NULL pointers although it is safe,
  * it is done to avoid unnecessary memory frees
*/


Cluster::~Cluster() noexcept {
  destroy();
}

//////////////////////////////////
// ////////// OPERATORS //////////
//////////////////////////////////

// operator<< functions


/**
   * @internal
  * The `Cluster::printSlot` method is internal of the `Cluster` class
  *
  * @brief Description
  * Prints an empty slot by printing 'empty' to the console or if the value is not nullptr or NULL
  * prints the respective value
  *
  * @return
  * This function does not return anything, it just prints to the console with std::ostream&
*/


void Cluster::printSlot(
  std::ostream& ostream,
  cluster_subv_t bucket_
) {
  if (
    isSubValueNullptr(
      bucket_
    )
  ) {
    ostream << "empty";
  }
}


/**
   * @internal
  * The `Cluster::takeSquareRootOfClusterSize` method is internal of the `Cluster` class
  *
  * @brief Description
  * Takes the square root of the size of `cluster` and rounds it so it is not decimal.
  * This is useful for very legible printing, since when printed it looks like a square
  * and not a flat array.
  *
  * @return
  * Returns a double which contains the square root of the size of `cluster`
*/


size_t Cluster::takeSquareRootOfClusterSize(
  cluster_t cluster_
) {
  return std::ceil(
    std::sqrt(
      cluster_.size()
    )
  );
}


/**
   * @internal
  * The `Cluster::brainExitOperator` method is internal of the `Cluster` class
  *
  * @brief Description
  * Prints on the console what a brain looks like, its buckets, its empty slots
  * in a very legible way
  *
  * @return
  * Returns a std::ostream& with what has been printed
*/


std::ostream& Cluster::clusterExitOperator(
  std::ostream& ostream,
  Cluster*& cluster_
) {
  // The following variable is to print the commas correctly, so that the
  // commas are not printed after the last element, 2 was put and not 1 because
  // 1 had no effect.

  const size_t SQUARE_ROOT_OF_CLUSTER_SIZE = takeSquareRootOfClusterSize(cluster_->cluster);
  const int CLUSTER_SIZE_LESS_ONE = cluster_->cluster.size() - 1;
  const int EMPTY = -1;
  size_t square_counter = 0;
  
  ostream << "Cluster([";

  if (CLUSTER_SIZE_LESS_ONE > EMPTY) {
    ostream << "\n";
  }

  size_t index = 0;

  while (index < cluster_->cluster.size()) {
    // Execute the functions that print the object, it is executed in the order of 
    // new slot -> comma, and so that it looks good and ordered,
    // what `printNewRow` and if the square counter is the square root a new line is printed

    if (index == 0) {
      ostream << "  ";
    }

    if (
      square_counter == SQUARE_ROOT_OF_CLUSTER_SIZE
    ) {
      cluster_->printNewRow(
        ostream,
        square_counter,
        cluster_->cluster.size(),
        index
      );

      square_counter = 0;
    }

    cluster_->printSlot(ostream, cluster_->cluster[index]);
    
    // NOTE: It was decided to put brain.size() - 2 and not - 1 because - 1 did
    // not make a change and caused the comma to be printed even after the last element,
    // the solution was to put - 2 and not - 1
    printComma(ostream, index, CLUSTER_SIZE_LESS_ONE);

    square_counter++;
    index++;
  }

  if (CLUSTER_SIZE_LESS_ONE > EMPTY) {
    ostream << "\n";
  }
  
  ostream << "])";

  return ostream;
}


/** 
  * @brief Description
  * operator<< implementation for the `Cluster` class
  *
  * @returns 
  * Returns std::ostream& which is then printed to the console
*/


std::ostream& operator<<(
  std::ostream& ostream,
  Cluster*& cluster_
) {
  return cluster_->clusterExitOperator(
    ostream,
    cluster_
  );
}