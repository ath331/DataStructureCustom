#pragma once


template <typename T>
class ListCustom
{
public:
	ListCustom()
		:_firstNode(new _Node), _lastNode(new _Node)
	{
		_firstNode->proNode = _lastNode;
		_firstNode->preNode = nullptr;

		_lastNode->preNode = _firstNode;
		_lastNode->proNode = nullptr;
	}

	virtual ~ListCustom()
	{
		while (true)
		{
			_Node* temp = _firstNode->proNode;
			delete _firstNode;
			_firstNode = temp;

			if (_firstNode == _lastNode)
				break;
		}

		delete _lastNode;
	}

	void PushBack(T element);
	void PushFront(T element);
	void PopBack();
	void PopFront();

	void Print();
private:
	struct _Node
	{
		_Node() {};
		_Node(T element)
			:element(element), preNode(nullptr), proNode(nullptr)
		{
		}

		T element;

		_Node* preNode;
		_Node* proNode;
	};

private:
	_Node* _firstNode;
	_Node* _lastNode;
};

#include "ListCustom.hpp"