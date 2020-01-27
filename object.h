// Lang::CwC
#pragma once

/**
 * Class for Object code to implemented with a Queue
 */
class Object {
   public:
    /**
     * Constructs a new Object. The object does not contain anything.
     */
    Object() {}

    /**
     * Destructs this object.
     */
    virtual ~Object() {}

    /**
     * Returns a number suitable as a hash code for this object as
     * unsigned long.
     * @return The hash code
     */
    virtual unsigned long hash() {
        return reinterpret_cast<unsigned long>(this);
    }

    /**
     * Checks if this Object is equal to a user input.
     * @param o Object to compare.
     */
    virtual bool equals(Object* other) {
        return this == other;
    }
};
