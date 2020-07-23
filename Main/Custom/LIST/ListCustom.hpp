#pragma once
#include <iostream>

template <typename T>
void ListCustom<T>::PushBack(T element)
{
	_Node* node = new _Node(element);
	node->proNode = _lastNode;
	node->preNode = _lastNode->preNode;

	_lastNode->preNode->proNode = node;
	_lastNode->preNode = node;
}

template <typename T>
void ListCustom<T>::PushFront(T element)
{
	_Node* node = new _Node(element);
	node->proNode = _firstNode->proNode;
	node->preNode = _firstNode;

	_firstNode->proNode->preNode = node;
	_firstNode->proNode = node;
}

template <typename T>
void ListCustom<T>::PopBack()
{
	_Node* temp = _lastNode->preNode;
	temp->preNode->proNode = _lastNode;
	_lastNode->preNode = temp->preNode;

	delete temp;
}

template <typename T>
void ListCustom<T>::PopFront()
{
	_Node* temp = _firstNode->proNode;
	_firstNode->proNode = temp->proNode;
	temp->proNode->preNode = _firstNode;

	delete temp;
}

template <typename T>
void ListCustom<T>::Print()
{
	if (_firstNode->proNode != nullptr)
	{
		_Node* temp = _firstNode->proNode;

		while (temp != nullptr)
		{
			std::cout << temp->element << " ";
			temp = temp->proNode;

			if (temp->proNode == nullptr)
				break;
		}
	}
}
