// Lang::CwC
#pramga once

#include "object.h"

/**
 * A basic String type for usage in tests. Since the stdlib is not allowed, we weren't able to
 * include more features String types from W2/W3.
 */
class String : public Object {
   public:
    char* _str;
    String(const char* from) {
        unsigned long count = 0;
        for (const char* i = from; *i != '\0'; i++) {
            count++;
        }
        _str = new char[count + 1];
        for (unsigned long i = 0; i < count; i++) {
            _str[i] = from[i];
        }
        _str[count] = '\0';
    }

    ~String() { delete[] _str; }

    virtual char* toCStr() {
        return _str;
    }

    virtual unsigned long length() {
        unsigned long count = 0;
        for (const char* i = _str; *i != '\0'; i++) {
            count++;
        }
        return count;
    }

    virtual unsigned long hash() {
        // This algorithm is taken from Java's String.hashCode implementation
        // https://github.com/openjdk/jdk/blob/8d307c1168f27460e8d0994089012a1d27b5552c/src/java.base/share/classes/java/lang/StringLatin1.java#L194
        size_t res = 0;
        for (size_t i = 0; i < length(); i++) {
            res = res * 31 + _str[i];
        }
        return res;
    }

    /**
     * Checks if this Object is equal to a user input.
     * @param o Object to compare.
     */
    virtual bool equals(Object* other) {
        if (String* s = dynamic_cast<String*>(other)) {
            if (s->length() != length()) {
                return false;
            }
            unsigned long l = length();
            for (unsigned long i = 0; i < l; i++) {
                if (s->_str[i] != _str[i]) {
                    return false;
                }
            }
            return true;
        }
        return false;
    }
};
