#pragma once

#ifndef BaseScalarType
#define BaseScalarType Scalar
#endif

#include <iostream>
#include <internals.h>
#include <setup/PrecisionSetup.h>
#include <objects/Scalar.h>

using namespace std;

BaseScalarType _A_, _B_, _C_, _D_, _X_, _Y_, _M_;

void query(string query, BaseScalarType *value){
	cout << query;
	cout.flush();
	string buffer;
	getline(cin, buffer);
	value->parseInput(buffer);
}
