#pragma once
#include "../VECTOR/VectorCustom.h"

template<typename keyT, typename valueT>
class MapCustom
{
public:
	void Push(keyT k, valueT v);
	valueT FInd(keyT k);

	valueT operator[] (const keyT k) const
	{
		return FInd(k);
	}

private:
	struct _Node
	{
		_Node() {};
		_Node(keyT k, valueT v)
			:key(k), value(v)
		{
		};

		keyT key;
		valueT value;

		bool operator< (const _Node& node) const
		{
			return key < node.key;
		}
	};

private:
	VectorCustom<_Node*> _heap;
	_Node* _root = nullptr;

	void _Swap(_Node*& a, _Node*& b);
	void _SortHeap(int i);
	void _MakeMaxHeap(int i);
};

#include "MapCustom.hpp"