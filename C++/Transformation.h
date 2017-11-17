#ifndef _TRANSFORMATION_H_
#define _TRANSFORMATION_H_

#include <iostream>
#include "data_type.h"


// Transformation through boolean algorithm
void eliminate_imply(Id_Node*);

void eliminate_iff(Id_Node*);

void eliminate_not(Id_Node*&);

void push_or_below_and(Id_Node*);  

#endif
