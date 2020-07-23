#pragma once
#include "../VECTOR/VectorCustom.h"

template <typename T>
class StackCustom : public VectorCustom<T>
{
public:
	T GetTop();
private:
};

#include "StackCustom.hpp"