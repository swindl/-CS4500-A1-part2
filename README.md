# Part 2 Queue

## Object Design

Our part2 assignment contains method signatures for object and queue CwC
classes. Object.h is similar to the object classes from warmup exercises,
containing an Object constructor and destructor, a hash function and an equals
method. The main difference is the hash function returns an unsigned long instead of
size_t as it is part of the standard library.


## Queue Design

Our Queue implementation contains methods for a basic Queue data structure.
A user can initialize an empty Queue with a default capacity or a Queue with an initial capacity
input as an unsigned long. A default capacity is set at 16. Queue
operations include enqueue and dequeue to add and remove items, getTop and
getBottom to return the first and last most items entered into the Queue,
and an isEmpty functions that returns a boolean stating whether or not
the Queue is full. dequeue also returns the next to be removed item from the Queue.
A getSize function also allows a user to return the size of
the Queue. Users are also able to check whether or not a given Object exists in the queue
through a call to contains(). Objects are returned from the get functions, meaning that
dynamic casting is used when a user needs to convert an Object that is a known
string to a String. Our destruct method for a Queue does not assume ownership
of the data held in the Queue, meaning that removing this data from the heap is left to the user.
We also implement custom hash and equals methods for a Queue. A string implementation
that uses no standard library functions is used for String support through string.h.
string.h contains methods to return length,

## test-queue.cpp

The testing file contains three tests that enqueue and dequeue a Queue and
test full/empty methods. Both Strings and Objects are pushed to the Queue and
isFull/isEmpty are called between the calls. In addition, contains() is tested
and a queue's equals and hash methods are called.
