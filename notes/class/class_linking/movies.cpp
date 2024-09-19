#include "movies.h"

 movieset::Movie::Movie()  //namespace::class::function
 {
    _id = 42;
 }

 int movieset::Movie::getId()
 {
    return _id;
 }