/**
  * @file brain.hpp
  * This is the documentation of the `brain.hpp` file
  *
  * @brief Description
  * Implementation of the Brain class, its constructor and destructor, and its undefined virtual methods
  * in C++
  *
  * COPYRIGHT: Copyright © 2025 Tomascord
  *
  * LICENSE: Apache 2.0, See: @see @link LICENSE.md @endlink
*/

#pragma once

// C++ libraries imports
#include <cstddef>
#include <ostream>
#include <vector>


// Forward reference to `Cluster`
class Cluster;


// Forward reference to `Bucket<T>`
class Bucket;


/**
 * @internal
 * The Brain class is internal and is not part of the public API.
 *
 * @brief Description
 * The information unit that contains clusters that simulates neurons
*/


class Brain {
  // Types
  public:
    // The subvalue type of the `brain_t`
    using brain_subv_t = Cluster*;

    // The `brain` field type
    using brain_t = std::vector<brain_subv_t>;

  // Operators
  public:
    // Operator << implementation for the `Brain` class
    friend std::ostream& operator<<(
      std::ostream& ostream,
      Brain*& brain_
    );
    
  protected:
    // Internal functions of the class, although they are
    // virtual functions for polymorphism in child classes
    bool isValueNullptr(brain_t* value);
    bool isSubValueNullptr(brain_subv_t value);
    
    virtual bool hasDisponibleCapacity();
    virtual void resizeVec();

    virtual void newVec();

    virtual void evaluateCapacity(size_t capacity);
    void evaluateNullptrInAssignation(brain_subv_t value);

    void pushObjectValue(brain_subv_t value);
    
    virtual void assignDefaultCapacity();
    virtual void assignCapacity(size_t capacity);
    
    virtual void defaultNullptrVec();

    void deleteInternalObject(brain_subv_t value);
    
    virtual void deleteAllFields();

    // Core functions that abstract all
    // responsibilities into a single function, 
    // They are also virtual functions
    // because the child classes will also have a virtual method,
    // and polymorphism is applied so that objects of the child classes
    // can be created from a pointer of the parent class.

    // Abstract constructor
    void build(
      brain_t* value,
      size_t capacity
    );

    // Abstract destructor
    void destroy();

    // Printing functions and utilities for easier debugging without having to worry
    // about doing it from scratch

    // operator<< functions
    void printNewRow(
      std::ostream& ostream,
      size_t square_counter,
      size_t size,
      size_t index
    );

    void printSlot(
      std::ostream& ostream,
      brain_subv_t brain_
    );
    
    void printComma(
      std::ostream& ostream,
      size_t index,
      size_t size
    );

    size_t takeSquareRootOfBrainSize(
      brain_t brain_
    );
    
    std::ostream& brainExitOperator(std::ostream& ostream, Brain*& brain_);

  public:
    size_t  brain_capacity /**< The capacity of the `brain` field */;
    brain_t brain;         /**< The main field of the `Brain` class It is the second largest
                                unit of information in the engine, after the database bucket. */;

    Brain(brain_t* brain_v, size_t capacity);
    Brain() = default;
    
    virtual ~Brain() noexcept;
};