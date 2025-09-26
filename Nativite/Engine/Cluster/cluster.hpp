/**
  * @file cluster.hpp
  * This is the documentation of the `cluster.hpp` file
  *
  * @brief Description
  * Implementation of the Cluster class, its constructor and destructor, and its undefined virtual methods
  * in C++
  *
  * COPYRIGHT: Copyright © 2025 Tomascord
  *
  * LICENSE: Apache 2.0, See: @see @link LICENSE.md @endlink
*/

#pragma once

// C++ libraries imports
#include <vector>

// Nativite engine imports
#include "../Brain/brain.hpp"
#include "../Terminal/terminal.hpp"

/**
 *
 * @internal
 * The Cluster class is internal and is not part of the public API.
 *
 * @brief Description
 * The information unit that contains buckets, clusters simulates neurons
*/


class Cluster : protected virtual Brain, public Terminal {
  // Types
  public:
    using cluster_subv_t = Bucket*;
    using cluster_t = std::vector<Bucket*>;
  // Operators
  public:
    // Operator << implementation for the `Brain` class
    friend std::ostream& operator<<(
      std::ostream& ostream,
      Cluster*& cluster_
    );
  protected:
    // Internal functions of the class, although they are
    // virtual functions for polymorphism in child classes
    bool isValueNullptr(cluster_t* value);
    bool isSubValueNullptr(cluster_subv_t value);
    
    virtual bool hasDisponibleCapacity() override;
    virtual void resizeVec() override;

    virtual void newVec() override;

    virtual void evaluateCapacity(size_t capacity) override;
    void evaluateNullptrInAssignation(cluster_subv_t value);

    void pushObjectValue(cluster_subv_t value);
    
    virtual void assignDefaultCapacity() override;
    virtual void assignCapacity(size_t capacity) override;

    virtual void defaultNullptrVec() override;

    void deleteInternalObject(cluster_subv_t value);
    
    virtual void deleteAllFields() override;

    virtual void pushClusterObjectToBrain();

    // Non virtual functions
    void abstractBuild(
      cluster_t* value,
      size_t capacity
    );
    
    void newTerminal();

    // Core functions that abstract all
    // responsibilities into a single function, 
    // They are also virtual functions
    // because the child classes will also have a virtual method,
    // and polymorphism is applied so that objects of the child classes
    // can be created from a pointer of the parent class.

    // Abstract constructor
    virtual void build(
      cluster_t* value,
      size_t capacity,
      bool add=false
    );
    
    // Abstract destructor
    virtual void destroy();

    // operator<< functions
    virtual void printSlot(
      std::ostream& ostream,
      cluster_subv_t brain_
    );

    size_t takeSquareRootOfClusterSize(
      cluster_t cluster_
    );
    
    std::ostream& clusterExitOperator(std::ostream& ostream, Cluster*& cluster_);

  public:
    cluster_t cluster;          /**< The cluster field that is a array of buckets */
    size_t    cluster_capacity; /**< The cluster capacity */

    Terminal* terminal; /**< The terminal or cache of the cluster, equivalent
                             of the axon because it is an output */
    
    Cluster(
      cluster_t* cluster_v,
      size_t capacity
    );

    Cluster() = default;

    virtual ~Cluster() noexcept;
};