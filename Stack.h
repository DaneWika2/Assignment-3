// General description of the ADT and supported operations – exportable operations only
// Do not include any implementation details
#ifndef _STACK_H // Guard – start
#define _STACK_H
#include <string>

typedef std::string SElement; // typedef <existing type> <new type>

// basic form of generic programming
class Stack {
    public: // exportable
            // General description of each of the ADT operations/methods/functions – exportable operations only
            Stack();
            Stack( Stack & ); // reuse pop & push
            ~Stack(); 
            void push( const SElement );
            void pop( SElement & );
            void peek( SElement & ); // reuse pop & push
            void view(); // reuse pop & push

    private: // non-exportable
        // No private member documentation – implementation details are hidden/abstracted away
        struct SNode;
        typedef SNode * SNodePtr;
        struct SNode {
        SElement element;
        SNodePtr next;
        };
    SNodePtr top;
};

#endif // Guard – end