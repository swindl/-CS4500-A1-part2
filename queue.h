// Lang::CwC
#pragma once

#include "object.h"

/**
 *  The CwC implementation of a Queue supports Objects and (since String is a subclass), Strings.
 *  It represents a queue that can be added to and removed from in First-In-First-Out order.
 *  That is, the order of objects returned by dequeue() will be exactly the same as the order
 *  added by enqueue().
 *  Additionally, this queue implementation does not take ownership of any of its object entries.
 *  Objects must be guaranteed by user code to be valid during the lifetime of this queue, and must
 *  also be freed by user code.
 */
class Queue : public Object {
   public:
    // Default initial capacity for queue
    static const unsigned long DEFAULT_CAPACITY = 16;

    /**
     * Constructs a new Queue object with a default initial capacity.
     */
    Queue() : Queue(DEFAULT_CAPACITY) {}

    /**
     * Constructs a new Queue object.
     * @param initial_capacity The initial capacity to allocate for storing queue items
     * ie, enqueue can be called this many times initially without Queue having to perform a
     * reallocation
     */
    Queue(unsigned long initial_capacity) : Object() {}

    /**
     * Destructor for Queue. Does not free any contained objects (that is the responsibility of
     * user code).
     */
    virtual ~Queue() {}

    /**
     * Returns true if the Queue is empty
     * @return true or false
     */
    virtual bool isEmpty() = 0;

    /**
     * Gets the number of items currently in the queue.
     * @return The number of objects
     */
    virtual unsigned long getSize() = 0;

    /**
     * Adds an item to the top of a Queue.
     * This does not take ownership of the object o, user code must free the object later.
     * o must also be valid for the lifetime of this queue.
     * @param o Object to add (non-null, or this method will abort)
     */
    virtual void enqueue(Object* o) = 0;

    /**
     * Removes and returns the object at the bottom of the queue.
     * @returns The object, or null if the queue is empty
     */
    virtual Object* dequeue() = 0;

    /**
     * Return the Object on the top (last in) of the Queue
     * @return Object on top of the Queue, or null if the queue is empty
     */
    virtual Object* getTop() = 0;

    /**
     * Return Object on bottom (first in) of queue
     * @return Object on bottom of the Queue, or null if the queue is empty
     */
    virtual Object* getBottom() = 0;

    /**
     * Checks if an object that is equal (via ->equals()) to the given object currently exists in
     * the queue.
     * @param object What to look for
     * @return true if exists, false if not
     */
    virtual bool contains(Object* object) = 0;

    // Force implementation of hash and equals for the queue
    virtual unsigned long hash() = 0;
    virtual bool equals(Object* other) = 0;
};
