#ifndef AUX_H_INCLUDED
#define AUX_H_INCLUDED

#include <string>
#include <vector>
#include <istream>
#include "tipos.h"

// Stream functions

void trimIS(std::istream & is);

// Vector and pair I/O

template<typename T, typename A>
std::ostream & operator<<(std::ostream & os,const vector<T,A> & v){
    os << "[ ";
    for(auto &i : v){
        os << i << " ";
    }
    os << "]";
    return os;
}

template<typename T, typename Q>
std::ostream & operator<<(std::ostream & os,const pair<T,Q> & p){
    os << "( " << p.first << " " << p.second << " )";
    return os;
}

template<typename T>
std::istream & operator>>(std::istream & is, vector<T> & v){
    T t;

    is.ignore(0xff,'['); // "  {"
    trimIS(is);
    while(is.peek() != ']'){
        is >> t;
        v.push_back(t);
        trimIS(is);
    }
    is.ignore(0xff,']'); // "  {"
    return is;
}

template<typename T, typename Q>
std::istream & operator>>(std::istream & is, pair<T,Q> & p){
    T t;
    Q q;

    is.ignore(0xff,'('); // "  {"
    is >> t >> q;
    is.ignore(0xff,')'); // "  {"

    p.first = t;
    p.second = q;
    return is;
}

#endif // AUX_H_INCLUDED

