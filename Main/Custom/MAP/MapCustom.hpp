#pragma once
#include <iostream>

template<typename keyT, typename valueT>
void MapCustom<keyT, valueT>::Push(keyT k, valueT v)
{
	_Node* node = new _Node(k, v);
	if (_root == nullptr)
	{
		_heap.Push(nullptr);
		_root = node;
	}

	_heap.Push(node);

	for (int i = _heap.GetSIze() / 2; i > 0; i--)
		_MakeMaxHeap(i);
	for (int i = _heap.GetSIze(); i > 0; i--)
		_SortHeap(i);
}

template<typename keyT, typename valueT>
valueT MapCustom<keyT, valueT>::FInd(keyT k)
{

}

template<typename keyT, typename valueT>
void MapCustom<keyT, valueT>::_Swap(_Node*& a, _Node*& b)
{
	_Node* temp = a;
	a = b;
	b = temp;
}

template<typename keyT, typename valueT>
void MapCustom<keyT, valueT>::_SortHeap(int i)
{
	//_Swap(_heap[1], _heap[i]);

	int root = 1;
	int cur = 2;

	while (cur / 2 < i)
	{
		cur = 2 * root;
		if (cur < i - 1 && _heap[cur] < _heap[cur + 1]) cur++;
		if (cur < i && _heap[root] < _heap[cur])
			//_Swap(_heap[root], _heap[cur]);

		root = cur;
	}
}

template<typename keyT, typename valueT>
void MapCustom<keyT, valueT>::_MakeMaxHeap(int i)
{
	int cur = 2 * i;

	if (cur < _heap.GetSIze() && _heap[cur] < _heap[cur + 1]) cur++;

	if (_heap[i] < _heap[cur])
	{
		//_Swap(_heap[i], _heap[cur]);

		if (cur <= _heap.GetSIze() / 2) _MakeMaxHeap(cur);
	}
}