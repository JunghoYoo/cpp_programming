#pragma once

#include <memory>
#include <iostream>

namespace lab10
{
	template<typename T>
	class Node;

	template<typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		void Insert(std::unique_ptr<T> data);
		void Insert(std::unique_ptr<T> data, unsigned int index);
		bool Delete(const T& data);
		bool Search(const T& data) const;

		std::shared_ptr<Node<T>> operator[](unsigned int index) const;
		unsigned int GetLength() const;

	private:
		std::shared_ptr<Node<T>> mHead;

		unsigned int mLength;
	};

	template<typename T> DoublyLinkedList<T>::DoublyLinkedList()
		: mHead(nullptr), mLength(0)
	{
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data)
	{
		if (mHead == nullptr) // 贸澜 积己
		{ 
			mHead = std::make_shared<Node<T>>(move(data));
		}
		else // add node as tail
		{
			std::shared_ptr<Node<T>> currentnode;
			
			currentnode = mHead; // head
			
			for (unsigned int k = 1; k < mLength; k++)
			{
				currentnode = currentnode->Next;
			}
			
			currentnode->Next = std::make_shared<Node<T>>(move(data), currentnode); // new node
			currentnode->Next->Previous = currentnode;
		}
		++mLength;
	}

	template<typename T>
	void DoublyLinkedList<T>::Insert(std::unique_ptr<T> data, unsigned int index)
	{
		std::shared_ptr<Node<T>> currentnode;
		unsigned int insertindex;

		if (index < mLength)
			insertindex = index;
		else
			insertindex = mLength;

		currentnode = mHead; // head

		if (mLength == 0) // 贸澜 积己
		{
			mHead = std::make_shared<Node<T>>(move(data));
		}
		else if (insertindex == mLength) // tail
		{
			for (unsigned int k = 1; k < insertindex; k++)
			{
				currentnode = currentnode->Next;
			}
			
			currentnode->Next = std::make_shared<Node<T>>(move(data), currentnode); // new node
			currentnode->Next->Previous = currentnode;
		}
		else if (insertindex == 0) // head
		{
			mHead = std::make_shared<Node<T>>(move(data));
			mHead->Next = currentnode;
			
			currentnode->Previous = mHead;
		}
		else // insert in the middle of nodes
		{ 
			for (unsigned int k = 1; k < insertindex; k++)
			{
				currentnode = currentnode->Next;
			}

			std::shared_ptr<Node<T>> next = currentnode->Next;
			std::weak_ptr<Node<T>> previous = currentnode->Previous;

			// currentnode -> new node -> next

			// Next
			currentnode->Next = std::make_shared<Node<T>>(move(data)); // new node
			currentnode->Next->Next = next;

			// Previous
			currentnode->Next->Previous = currentnode;
			next->Previous = currentnode->Next;
		}

		mLength++;
	}

	template<typename T>
	bool DoublyLinkedList<T>::Delete(const T& data)
	{
		std::shared_ptr<Node<T>> currentnode;

		currentnode = mHead; // head

		for (unsigned int k = 1; k < mLength; k++) // search
		{
			if (data == *currentnode->Data.get())
				break;

			currentnode = currentnode->Next;
		}

		if (currentnode != nullptr) 
		{
			if (data == *currentnode->Data.get()) // found
			{	
				// currentnode : will be deleted
				if (mHead == currentnode) // head
				{
					if (mLength == 1) // will be empty
					{
						mHead.reset();
					}
					else // will not be empty
					{
						mHead = currentnode->Next;
						mHead->Next = currentnode->Next->Next;

						mHead->Next->Previous = mHead;

						// don't need delete
					}
				}
				else if (currentnode->Next != nullptr) // not tail
				{
					std::shared_ptr<Node<T>> currentprevnode = currentnode->Previous.lock();
					std::shared_ptr<Node<T>> currentnextnode = currentnode->Next;

					// prev
					currentprevnode->Next = currentnode->Next;
					// next
					currentnextnode->Previous = currentprevnode;

					// don't need delete
				}
				else // tail
				{
					std::shared_ptr<Node<T>> currentprevnode = currentnode->Previous.lock();
					currentprevnode->Next = nullptr;

					// don't need delete
				}

				mLength--;

				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	template<typename T>
	bool DoublyLinkedList<T>::Search(const T& data) const
	{
		std::shared_ptr<Node<T>> currentnode;

		currentnode = mHead; // head

		for (unsigned int k = 1; k < mLength; k++)
		{
			if (*currentnode->Data == data)
				break;

			currentnode = currentnode->Next;
		}

		if (currentnode != nullptr)
		{
			if (*currentnode->Data == data)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}

	template<typename T>
	std::shared_ptr<Node<T>> DoublyLinkedList<T>::operator[](unsigned int index) const
	{
		if (mLength > 0)
		{
			if (index < mLength)
			{
				std::shared_ptr<Node<T>> currentnode;
				currentnode = mHead; // head

				for (unsigned int k = 0; k < index; k++)
				{
					currentnode = currentnode->Next;
				}

				return currentnode;
			}
			else // out of bound
			{
				return nullptr;
			}
		}
		else // empty list
		{
			return nullptr;
		}
	}

	template<typename T>
	unsigned int DoublyLinkedList<T>::GetLength() const
	{
		return mLength;
	}
}	