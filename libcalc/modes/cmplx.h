#pragma once

#define BaseScalarType ComplexScalar

#include <objects/ComplexScalar.h>
#include <global.h>

ComplexScalar *conjg(ComplexScalar *input);

BaseScalarType *arg(ComplexScalar *input);
