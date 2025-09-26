/**
  * @file terminal.cpp
  * This is the documentation of the `terminal.hpp` file
  *
  * @brief Description
  * Implementation of the Terminal class methods,
  * also the implementation of its operators such as <<.
  *
  * COPYRIGHT: Copyright © 2025 Tomascord
  *
  * LICENSE: Apache 2.0, See: @see @link LICENSE.md @endlink
*/

// C++ libraries imports
#include "terminal.hpp"
#include <iostream>
#include <vector>


/**
  * @internal
  * The `Terminal::isValueNullptr` method is internal of the `Terminal` class
  * 
  * @brief Description
  * Evaluates if the suggested `terminal_t* value` is `nullptr` or is `NULL`
  * 
  * @return
  * Returns a boolean, true if value if the previous expresion is right
*/


bool Terminal::isValueNullptr(terminal_t* value) {
  return 
    value == nullptr ||
    value == NULL;
}


/**
  * @internal
  * The `Terminal::isSubValueNullptr` method is internal of the `Terminal` class
  * 
  * @brief Description
  * Evaluates if the suggested `terminal_subv_t value` is `nullptr` or is `NULL`
  * 
  * @return
  * Returns a boolean, true if value if the previous expresion is right
*/


bool Terminal::isSubValueNullptr(terminal_subv_t value) {
  return 
    value == nullptr ||
    value == NULL;
}


/**
  * @internal
  * The `Terminal::hasDisponibleCapacity` method is internal of the `Terminal` class
  * 
  * @brief Description
  * Evaluates if `terminal.size()` is less than the capacity field
  * 
  * @return
  * Returns a boolean, true if value if the previous expresion is right
*/


bool Terminal::hasDisponibleCapacity() {
  return terminal.size() < terminal_capacity;
}


/**
  * @internal
  * The `Terminal::newVec` method is internal of the `Terminal` class
  * 
  * @brief Description
  * Create a new vector for the `terminal` field
  * 
  * @return
  * This function does not return anything, since it
  * only creates a new vector for the `terminal` field
*/


void Terminal::newVec() {
  terminal = std::vector<Astruct*>(terminal_capacity);
}


/**
  * @internal
  * The `Terminal::defaultNullptrVec` method is internal of the `Terminal` class
  * 
  * @brief Description
  * assign to `terminal` field a default nullptr vector, if `terminal_v` in the constructor
  * of the class is nullptr or NULL
  * 
  * @return
  * This function does not return anything, since it
  * only assign a nullptr vec to `brain` field
*/


void Terminal::defaultNullptrVec() {
  size_t index = 0;

  while (
    index < terminal_capacity
  ) {
    terminal[index] = nullptr;
    index++;
  }
}


/**
  * @internal
  * The `Terminal::deleteBack` method is internal of the `Terminal` class
  * 
  * @brief Description
  * Deletes the first element of the vector of the field `terminal_t ​​terminal`
  * 
  * @return
  * This function does not return anything, since it
  * only delete the first element in the vector of 
  * `terminal_t ​​terminal`
*/


void Terminal::deleteBack() {
  terminal.erase(terminal.begin());
}


/**
  * @internal
  * The `Terminal::deleteInternalObject` method is internal of the `Terminal` class
  * 
  * @brief Description
  * delete the suggested value using `delete value;` and `value = nullptr;`
  * 
  * @return
  * This function does not return anything, since it
  * only delete the suggested value
*/


void Terminal::deleteInternalObject(terminal_subv_t value) {
  delete value;
  value = nullptr;
}


/**
  * @internal
  * The `Terminal::deleteAllFields` method is internal of the `Terminal` class
  * 
  * @brief Description
  * reset all fields, cleaning the `terminal` field and reset to 0 the `terminal_capacity` field
  * 
  * @return
  * This function does not return anything, since it
  * only delete all fields of the class
*/


void Terminal::deleteAllFields() {
  terminal.clear();
  terminal_capacity = 0;
  empty = true;
}


/**
  * @internal
  * The `Terminal::toggleEmptyFieldBoolean` method is internal of the `Terminal` class
  * 
  * @brief Description
  * Inverts the boolean value of the `empty` field
  * 
  * @return
  * This function does not return anything, since it
  * only delete all fields of the class
*/


void Terminal::toggleEmptyFieldBoolean() {
  empty = !empty;
}


/**
  * @internal
  * The `Terminal::pushObjectValue` method is internal of the `Terminal` class
  * 
  * @brief Description
  * push to `terminal` the `value`, this function is
  * used to push the value if `value` is not nullptr or NULL
  * 
  * @return
  * This function does not return anything, since it
  * only push to `terminal` the `value`
*/


void Terminal::pushObjectValue(terminal_subv_t value) {
  terminal.push_back(value);
}


/**
  * @internal
  * The `Terminal::build` method is internal of the `Terminal` class
  * 
  * @brief Description
  * build the `terminal` field according to different conditions
  * 
  * @return
  * This function does not return anything, since it
  * only build the `terminal` field
*/


void Terminal::build(terminal_t* terminal_v) {
  newVec();
  if (isValueNullptr(terminal_v)) 
    defaultNullptrVec();
  else {
    size_t index = 0;

    while (index < terminal_v->size()) {
      std::cout << index;
      if (hasDisponibleCapacity()) {
        pushObjectValue((*terminal_v)[index]);
      } else {
        deleteBack();
        pushObjectValue((*terminal_v)[index]);
      }
      index++;
    }

    toggleEmptyFieldBoolean();
  }
}


/**
  * @internal
  * The `Terminal::destroy` method is internal of the `Terminal` class
  * 
  * @brief Description
  * destroy the `terminal` deleting all `Astruct*` objects and reset the 
  * `terminal_capacity` field to 0
  * 
  * @return
  * This function does not return anything, since it
  * only destroy the `terminal` field and reset `terminal_capacity`
  * to 0
*/


void Terminal::destroy() {
  for (
    auto astruct : terminal
  ) {
    if (!isSubValueNullptr(astruct)) {
      deleteInternalObject(astruct);
    }
  }

  deleteAllFields();
}


/**
  * @internal
  * The `Terminal::Terminal` method is internal of the `Terminal` class
  *
  * @brief Description
  * The constructor of the `Terminal` class
  *
  * @details
  * It handles several things, such as checking if the value to be assigned is
  * nullptr or NULL, it also handles capacity assignment, creating a new vector
  * for `terminal`, checking that no more than 16 elements are passed and deleting
  * the first element if another is added when there are already 16 elements.
*/


Terminal::Terminal(terminal_t* terminal_v) {
  build(terminal_v);
}


/**
  * @internal
  * The `Terminal::~Terminal` method is internal of the `Terminal` class
  *
  * @brief Description
  * The destructor of the `Terminal` class
  *
  * @details
  * It handles how to check if a value is nullptr or NULL when deleting one by one
  * This prevents freeing memory to nullptr or NULL pointers although it is safe,
  * it is done to avoid unnecessary memory frees
*/


Terminal::~Terminal() noexcept {
  destroy();
}