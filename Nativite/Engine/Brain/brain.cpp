/**
  * @file brain.cpp
  * This is the documentation of the `brain.hpp` file
  *
  * @brief Description
  * Implementation of the Brain class virtual methods and other methods,
  * also the implementation of its operators such as <<.
  *
  * COPYRIGHT: Copyright © 2025 Tomascord
  *
  * LICENSE: Apache 2.0, See: @see @link LICENSE.md @endlink
*/

// C++ libraries imports
#include <cmath>
#include <iostream>
#include <ostream>

// Nativite engine imports
#include "brain.hpp"

/**
  * @internal
  * The `Brain::isValueNullptr` method is internal of the `Brain` class
  * 
  * @brief Description
  * Evaluates if the suggested `brain_t* value` is `nullptr` or is `NULL`
  * 
  * @return
  * Returns a boolean, true if value if the previous expresion is right
*/


bool Brain::isValueNullptr(brain_t* value) {
  return 
    value == nullptr ||
    value == NULL;
}


/**
  * @internal
  * The `Brain::isSubValueNullptr` method is internal of the `Brain` class
  * 
  * @brief Description
  * Evaluates if the suggested `brain_subv_t value` is `nullptr` or is `NULL`
  * 
  * @return
  * Returns a boolean, true if value if the previous expresion is right
*/


bool Brain::isSubValueNullptr(brain_subv_t value) {
  return 
    value == nullptr ||
    value == NULL;
}

/**
  * @internal
  * The `Brain::hasDisponibleCapacity` method is internal of the `Brain` class
  * 
  * @brief Description
  * Evaluates if `brain.size()` is less than the capacity field
  * 
  * @return
  * Returns a boolean, true if value if the previous expresion is right
*/


bool Brain::hasDisponibleCapacity() {
  return brain.size() < brain_capacity;
}


/**
  * @internal
  * The `Brain::resizeVec` method is internal of the `Brain` class
  * 
  * @brief Description
  * Resizes the capacity of the vector by adding more capacity to the 
  * `brain` field vector, the function is used to reserve capacity to the vector
  * 
  * @return
  * This function does not return anything, since it
  * only resizes the capacity of the vector.
*/


void Brain::resizeVec() {
  brain_capacity += 15;
  brain.resize(brain_capacity);
}


/**
  * @internal
  * The `Brain::newVec` method is internal of the `Brain` class
  * 
  * @brief Description
  * Create a new vector for the `brain` field
  * 
  * @return
  * This function does not return anything, since it
  * only creates a new vector for the `brain` field
*/


void Brain::newVec() {
  brain = std::vector<Cluster*>(brain_capacity);
}


/**
  * @internal
  * The `Brain::evaluateCapacity` method is internal of the `Brain` class
  * 
  * @brief Description
  * Evaluates with a switch case, if the capacity parameter is zero,
  * calls `Brain::assignDefaultCapacity` to assign a default capacity, in the default case,
  * calls `Brain::assignCapacity` with the `capacity` param and assign the capacity to the
  * `brain_capacity` field the capacity
  * 
  * @return
  * This function does not return anything, since it
  * only evaluates with a switch case the capacity
*/


void Brain::evaluateCapacity(size_t capacity) {
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
  * The `Brain::evaluateNullptrInAssignation` method is internal of the `Brain` class
  * 
  * @brief Description
  * Evaluates if the value if is not nullptr or NULL or not,
  * if not, the `brain` field push `value` to the `brain` vector
  * 
  * @return
  * This function does not return anything, since it
  * only evaluates if the value is nullptr or NULL or not, and if it is
  * not nullptr the `value` is pushed to the `brain` field of the class
*/


void Brain::evaluateNullptrInAssignation(brain_subv_t value) {
  if (!isSubValueNullptr(value)) {
    pushObjectValue(value);
  }
}


/**
  * @internal
  * The `Brain::pushObjectValue` method is internal of the `Brain` class
  * 
  * @brief Description
  * push to `brain` the `value`, this function is
  * used to push the value if `value` is not nullptr or NULL
  * 
  * @return
  * This function does not return anything, since it
  * only push to `brain` the `value`
*/


void Brain::pushObjectValue(brain_subv_t value) {
  brain.push_back(value);
}


/**
  * @internal
  * The `Brain::assignDefaultCapacity` method is internal of the `Brain` class
  * 
  * @brief Description
  * assign a default capacity to the `brain_capacity` field the capacity: 15
  * 
  * @return
  * This function does not return anything, since it
  * only assign 15 to the `brain_capacity` field
*/


void Brain::assignDefaultCapacity() {
  brain_capacity = 25;
}


/**
  * @internal
  * The `Brain::assignCapacity` method is internal of the `Brain` class
  * 
  * @brief Description
  * assign a capacity to the `brain_capacity` field the suggested capacity
  * 
  * @return
  * This function does not return anything, since it
  * only assign the suggested capacity to the `brain_capacity` field
*/


void Brain::assignCapacity(size_t capacity) {
  brain_capacity = capacity;
}


/**
  * @internal
  * The `Brain::defaultNullptrVec` method is internal of the `Brain` class
  * 
  * @brief Description
  * assign to `brain` field a default nullptr vector, if `brain_v` in the constructor
  * of the class is nullptr or NULL
  * 
  * @return
  * This function does not return anything, since it
  * only assign a nullptr vec to `brain` field
*/


void Brain::defaultNullptrVec() {
  size_t index = 0;

  while (index < brain_capacity) {
    brain[index] = nullptr;
    index++;
  }
}


/**
  * @internal
  * The `Brain::deleteInternalObject` method is internal of the `Brain` class
  * 
  * @brief Description
  * delete the suggested value using `delete value;` and `value = nullptr;`
  * 
  * @return
  * This function does not return anything, since it
  * only delete the suggested value
*/


void Brain::deleteInternalObject(brain_subv_t value) {
  delete value;
  value = nullptr;
}


/**
  * @internal
  * The `Brain::deleteAllFields` method is internal of the `Brain` class
  * 
  * @brief Description
  * reset all fields, cleaning the `brain` field and reset to 0 the `brain_capacity` field
  * 
  * @return
  * This function does not return anything, since it
  * only delete all fields of the class
*/


void Brain::deleteAllFields() {
  brain.clear();
  brain_capacity = 0;
}


/**
  * @internal
  * The `Brain::build` method is internal of the `Brain` class
  * 
  * @brief Description
  * build the `brain` field according to different conditions
  * 
  * @return
  * This function does not return anything, since it
  * only build the `brain` field
*/


void Brain::build(
  brain_t* value,
  size_t capacity
) {
  std::cout << "Executing Brain::build...\n";

  evaluateCapacity(capacity);
  newVec();
  if (isValueNullptr(value)) {

    std::cout << "There is no value to copy for brain field in Brain class\n";
    std::cout << "Building a 25 nullptr vector...\n";

    defaultNullptrVec();

    std::cout << "Vector of 25 nullptr for Brain class is built\n\n";
    return;
  } else {
    size_t index = 0;

    std::cout << "Copying suggested value...\n";

    while (index < value->size()) {
      if (hasDisponibleCapacity()) {
        evaluateNullptrInAssignation(value->at(index));
      } else {
        resizeVec();
        evaluateNullptrInAssignation(value->at(index));
      }
      index++;
    }
    
    std::cout << "Brain::brain is built\n\n";
  }
}


/**
  * @internal
  * The `Brain::destroy` method is internal of the `Brain` class
  * 
  * @brief Description
  * destroy the `brain` deleting all `Cluster*` objects and reset the 
  * `brain_capacity` field to 0
  * 
  * @return
  * This function does not return anything, since it
  * only destroy the `brain` field and reset `brain_capacity`
  * to 0
*/


void Brain::destroy() {
  for (
    auto cluster : brain
  ) {
    if (!isSubValueNullptr(cluster)) {
      deleteInternalObject(cluster);
    }
  }
  deleteAllFields();
}

/**
  * @internal
  * The `Brain::Brain` method is internal of the `Brain` class
  *
  * @brief Description
  * The constructor of the `Brain` class
  *
  * @details
  * It handles several things, such as checking if the value to be assigned is
  * nullptr or NULL, it also handles capacity assignment, creating a new vector
  * for `brain`, resizing the `brain` vector.
*/


Brain::Brain(
  brain_t* brain_v,
  size_t capacity
) {
  build(brain_v, capacity);
}


/**
  * @internal
  * The `Brain::~Brain` method is internal of the `Brain` class
  *
  * @brief Description
  * The destructor of the `Brain` class
  *
  * @details
  * It handles how to check if a value is nullptr or NULL when deleting one by one
  * This prevents freeing memory to nullptr or NULL pointers although it is safe,
  * it is done to avoid unnecessary memory frees
*/


Brain::~Brain() noexcept {
  destroy();
}

//////////////////////////////////
// ////////// OPERATORS //////////
//////////////////////////////////

// operator<< functions


/**
   * @internal
  * The `Brain::printNewRow` method is internal of the `Brain` class
  *
  * @brief Description
  * Prints a new line, printing a line break, and also printing a 2-indent tab stop
  *
  * @return
  * This function does not return anything, it just prints to the console with std::ostream&
*/


void Brain::printNewRow(
  std::ostream& ostream,
  size_t square_counter,
  size_t BRAIN_SIZE,
  size_t index
) {
  ostream << "\n";
  if (index < BRAIN_SIZE) {
    ostream << "  ";
  }
}


/**
   * @internal
  * The `Brain::printSlot` method is internal of the `Brain` class
  *
  * @brief Description
  * Prints an empty slot by printing 'empty' to the console or if the value is not nullptr or NULL
  * prints the respective value
  *
  * @return
  * This function does not return anything, it just prints to the console with std::ostream&
*/


void Brain::printSlot(
  std::ostream& ostream,
  brain_subv_t brain_
) {
  if (
    isSubValueNullptr(
      brain_
    )
  ) {
    ostream << "empty";
  } else {
    ostream << "item";
  }
}


/**
   * @internal
  * The `Brain::printComma` method is internal of the `Brain` class
  *
  * @brief Description
  * Prints ', ' as an element separator when printing empty elements
  *
  * @return
  * This function does not return anything, it just prints to the console with std::ostream&
*/


void Brain::printComma(
  std::ostream& ostream,
  size_t index,
  size_t size
) {
  if (
    index < size
  ) {
    ostream << ", ";
  }
}


/**
   * @internal
  * The `Brain::takeSquareRootOfBrainSize` method is internal of the `Brain` class
  *
  * @brief Description
  * Takes the square root of the size of `brain` and rounds it so it is not decimal.
  * This is useful for very legible printing, since when printed it looks like a square
  * and not a flat array.
  *
  * @return
  * Returns a double which contains the square root of the size of `brain`
*/


size_t Brain::takeSquareRootOfBrainSize(
  brain_t brain_
) {
  return std::ceil(
    std::sqrt(
    brain_.size()
    )
  );
}


/**
   * @internal
  * The `Brain::brainExitOperator` method is internal of the `Brain` class
  *
  * @brief Description
  * Prints on the console what a brain looks like, its clusters, its empty slots
  * in a very legible way
  *
  * @return
  * Returns a std::ostream& with what has been printed
*/


std::ostream& Brain::brainExitOperator(
  std::ostream& ostream,
  Brain*& brain_
) {
  // The following variable is to print the commas correctly, so that the
  // commas are not printed after the last element, 2 was put and not 1 because
  // 1 had no effect.

  const size_t SQUARE_ROOT_OF_BRAIN_SIZE = takeSquareRootOfBrainSize(brain_->brain);
  const int BRAIN_SIZE_LESS_ONE = brain_->brain.size() - 1;
  const int EMPTY = -1;
  size_t square_counter = 0;
  
  ostream << "Brain([";

  if (BRAIN_SIZE_LESS_ONE > EMPTY) {
    ostream << "\n";
  }

  size_t index = 0;

  while(index < brain_->brain.size()) {
    // Execute the functions that print the object, it is executed in the order of 
    // new slot -> comma, and so that it looks good and ordered,
    // what `printNewRow` and if the square counter is the square root a new line is printed

    if (index == 0) {
      ostream << "  ";
    }

    if (
      square_counter == SQUARE_ROOT_OF_BRAIN_SIZE
    ) {
      printNewRow(
        ostream,
        square_counter,
        brain_->brain.size(),
        index
      );

      square_counter = 0;
    }

    brain_->printSlot(ostream, brain_->brain[index]);
    
    brain_->printComma(ostream, index, BRAIN_SIZE_LESS_ONE);

    square_counter++;
    index++;
  }

  if (BRAIN_SIZE_LESS_ONE > EMPTY) {
    ostream << "\n";
  }

  ostream << "])";

  return ostream;
}


/** 
  * @brief Description
  * operator<< implementation for the `Brain` class
  *
  * @returns 
  * Returns std::ostream& which is then printed to the console
*/


std::ostream& operator<<(
  std::ostream& ostream,
  Brain*& brain_
) {
  return brain_->brainExitOperator(
    ostream,
    brain_
  );
}