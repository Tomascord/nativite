/**
  * @file terminal.hpp
  * This is the documentation of the `terminal.hpp` file
  *
  * @brief Description
  * Implementation of the Terminal class, its constructor and destructor, and its undefined methods
  * in C++
  *
  * COPYRIGHT: Copyright © 2025 Tomascord
  *
  * LICENSE: Apache 2.0, See: @see @link LICENSE.md @endlink
*/

#pragma once

// C++ libraries imports
#include <vector>

// Forward reference to Astruct
class Astruct;

class Terminal {
  // Types and Unions They are defined before private so that 
  // the protected: and public: parts can use them without errors.
  public: 
    using terminal_subv_t = Astruct*;
    using terminal_t         = std::vector<terminal_subv_t>;
  protected:
    bool isValueNullptr(terminal_t* value);
    bool isSubValueNullptr(terminal_subv_t value);

    bool hasDisponibleCapacity();

    void newVec();

    void defaultNullptrVec();
    
    void deleteBack();
    void deleteInternalObject(terminal_subv_t value);
    void deleteAllFields();

    void pushObjectValue(terminal_subv_t value);

    void toggleEmptyFieldBoolean();

    void build(terminal_t* terminal_v);
    void destroy();
  public:
    size_t     terminal_capacity = 17;   /**< The terminal capacity of the terminal */
    bool       empty             = true; /**< The terminal field that Indicates if the terminal
                                              is empty or not */
    terminal_t terminal; /**< The cache that contains the most consulted data */
    bool       automaticTerminalManagment = true; /**< Indicates if the terminal It is handled automatically,
                                                       adding elements automatically and removing them
                                                       as well. */

    Terminal(terminal_t* terminal_v);
    Terminal() = default;

    ~Terminal() noexcept;
};