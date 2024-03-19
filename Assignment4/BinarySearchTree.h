#pragma once

#include <memory>
#include <vector>
#include <stack>
#include <cassert>
using namespace std;

namespace assignment4
{
	template<typename T>
	class TreeNode;

	template<typename T>
	class BinarySearchTree final
	{
	public:
		void Insert(std::unique_ptr<T> data);
		bool Search(const T& data);
		bool Delete(const T& data);
		const std::weak_ptr<TreeNode<T>> GetRootNode() const;
		// static 멤버함수 -> static 멤버변수만 접근가능하며 인스턴스 안만들고 사용가능
		static std::vector<T> TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode);
		static std::vector<T> CheckBSTRule(const std::shared_ptr<TreeNode<T>> startNode);

	private:
		inline bool isLeaf(const std::shared_ptr<TreeNode<T>> leafNode);

		std::shared_ptr<TreeNode<T>> getLeftMostNode(const std::shared_ptr<TreeNode<T>> startNode);
		std::shared_ptr<TreeNode<T>> getRightMostNode(const std::shared_ptr<TreeNode<T>> startNode);

		std::shared_ptr<TreeNode<T>> mRootNode;
	};

	template<typename T>
	std::shared_ptr<TreeNode<T>> mRootNode = nullptr;

	template<typename T>
	void BinarySearchTree<T>::Insert(std::unique_ptr<T> data)
	{
		if (mRootNode == nullptr) // make first node as root
		{
			std::shared_ptr<TreeNode<T>> newNode = std::make_shared<TreeNode<T>>(move(data));

			mRootNode = newNode;
			mRootNode->Parent.reset();
		}
		else
		{
			std::shared_ptr<TreeNode<T>> currentNode;
			currentNode = mRootNode;

			// L->V->R
			while (1)
			{
				if (*currentNode->Data > * data)
				{
					if (currentNode->Left != nullptr)
					{
						currentNode = currentNode->Left; // Left Down
					}
					else // leaf (left empty) 
					{
						std::shared_ptr<TreeNode<T>> newNode = std::make_shared<TreeNode<T>>(move(data));

						currentNode->Left = newNode;	// down
						newNode->Parent = currentNode;	// up

						break;
					}
				}
				else if (*currentNode->Data < *data)
				{
					if (currentNode->Right != nullptr)
					{
						currentNode = currentNode->Right; // Right Down
					}
					else // leaf (right empty)
					{
						std::shared_ptr<TreeNode<T>> newNode = std::make_shared<TreeNode<T>>(move(data));

						currentNode->Right = newNode;	// down
						newNode->Parent = currentNode;	// up

						break;
					}
				}
				else //  (*(currentNode->Data) == *data) // same data on the left
				{
					if (currentNode->Left != nullptr)
					{
						currentNode = currentNode->Left; // Left Down
					}
					else
					{
						std::shared_ptr<TreeNode<T>> newNode = std::make_shared<TreeNode<T>>(move(data));

						currentNode->Left = newNode;	// down
						newNode->Parent = currentNode;	// up

						break;
					}
				}
			}
		}
	}

	template<typename T>
	const std::weak_ptr<TreeNode<T>> BinarySearchTree<T>::GetRootNode() const
	{
		return mRootNode;
	}

	template<typename T>
	bool BinarySearchTree<T>::Search(const T& data)
	{
		bool bFound = false;
		std::shared_ptr<TreeNode<T>> currentNode;

		currentNode = this->mRootNode;

		// L->V->R
		while (1)
		{
			if (currentNode == nullptr) // make first node as root
			{
				bFound = false;

				break;
			}
			else
			{
				if (*currentNode->Data > data)
				{
					if (currentNode->Left != nullptr)
					{
						currentNode = currentNode->Left; // Left Down
					}
					else // leaf 
					{
						bFound = false;

						break;
					}
				}
				else if (*currentNode->Data < data)
				{
					if (currentNode->Right != nullptr)
					{
						currentNode = currentNode->Right; // Right Down
					}
					else // leaf 
					{
						bFound = false;

						break;
					}
				}
				else // same data 
				{
					bFound = true;

					break;
				}
			}
		}

		return bFound;
	}

	template<typename T>
	bool BinarySearchTree<T>::Delete(const T& data)
	{
		bool bSearchResult;

		bSearchResult = Search(data);

		if (bSearchResult == true)
		{
			std::shared_ptr<TreeNode<T>> currentNode;
			std::shared_ptr<TreeNode<T>> parentNode;

			currentNode = this->mRootNode;

			// L->V->R
			while (1)
			{
				if (*currentNode->Data > data)
				{
					// there is a node which *currentNode->Data == data, so don't check whether currentNode->Left is nullptr
					currentNode = currentNode->Left; // Left Down
				}
				else if (*currentNode->Data < data)
				{
					// there is a node which *currentNode->Data == data, so don't check whether currentNode->Right is nullptr
					currentNode = currentNode->Right; // Right Down
				}
				else // found
				{
					if (isLeaf(currentNode) == true) // leaf node
					{
						if (mRootNode != currentNode)
						{
							parentNode = currentNode->Parent.lock();

							if (parentNode->Left == currentNode) // left leaf
							{
								parentNode->Left.reset();
							}
							else // right leaf
							{
								parentNode->Right.reset();
							}
						}
						else // there is only 1 node within the BST
						{
							mRootNode->Parent.reset();
							mRootNode->Left.reset();
							mRootNode->Right.reset();
							mRootNode.reset();
						}
					}
					else if (currentNode->Left == nullptr) // only right child
					{
						if (mRootNode != currentNode)
						{
							parentNode = currentNode->Parent.lock();

							if (parentNode->Left == currentNode)
								parentNode->Left = currentNode->Right;
							else
								parentNode->Right = currentNode->Right;

							currentNode->Right->Parent = parentNode;

							currentNode.reset();
						}
						else // root
						{
							mRootNode = currentNode->Right;
							currentNode->Right->Parent.reset();

							currentNode.reset();
						}
					}
					else if (currentNode->Right == nullptr) // only left child
					{
						if (mRootNode != currentNode)
						{
							parentNode = currentNode->Parent.lock();

							if (parentNode->Left == currentNode)
								parentNode->Left = currentNode->Left;
							else
								parentNode->Right = currentNode->Left;

							currentNode->Left->Parent = parentNode;

							currentNode.reset();
						}
						else // root
						{
							mRootNode = currentNode->Left;
							mRootNode->Parent.reset();

							currentNode->Left->Parent.reset();

							currentNode.reset();
						}
					}
					else // left and right chld
					{
						// initial
						parentNode = currentNode->Parent.lock();

						// left side of current Node is subtree (include candidate node)
						std::shared_ptr<TreeNode<T>> subtreeNode = currentNode->Left;

						// find new parent of current node & no right child of candidateNode(Left of current)
						std::shared_ptr<TreeNode<T>> candidateNode = getRightMostNode(subtreeNode);

						//assert(candidateNode->Right == nullptr);

						// remove candidateNode from subtree
						if (subtreeNode == candidateNode)
						{
							if (candidateNode->Left != nullptr) // left child exists
							{
								if (*candidateNode->Left->Data == *candidateNode->Data)
								{
									subtreeNode = candidateNode->Left;
									// has no right child on the remaining same data node (insertion rule)
									while ((subtreeNode->Left != nullptr) && (*subtreeNode->Left->Data == *subtreeNode->Data))
									{
										// go down
										subtreeNode = subtreeNode->Left;
									};

									// move to not the same node
									if (subtreeNode->Left != nullptr)
										subtreeNode = subtreeNode->Left;
									else // all nodes are same
										subtreeNode.reset();
								}
								else
								{
									subtreeNode = candidateNode->Left;
								}
							}
							else // candidateNode has no right child node
							{
								subtreeNode.reset();
							}
						}
						else
						{
							if (candidateNode->Left == nullptr) // candiate node is leaf
							{
								std::shared_ptr<TreeNode<T>> candidateParentNode = candidateNode->Parent.lock();
								candidateParentNode->Right = nullptr; // Candiate is Right Most
							}
							else
							{
								if (*candidateNode->Left->Data != *candidateNode->Data)
								{
									// connect left child and parent of candidateNode
									std::shared_ptr<TreeNode<T>> candidateParentNode = candidateNode->Parent.lock();
									candidateParentNode->Right = candidateNode->Left; // Candiate is Right Most
									candidateParentNode->Right->Parent = candidateParentNode;
								}
								else // same data exists on the left of candidate
								{
									// don't move candiate's left chld to candidateParentNode
									// disconnect all same data from subtree
									std::shared_ptr<TreeNode<T>> candidateParentNode = candidateNode->Parent.lock();

									// Get end of the same data on the left child of candidate
									std::shared_ptr<TreeNode<T>> candidateChildNode;
									candidateChildNode = candidateNode->Left;

									while ((candidateChildNode->Left != nullptr) && (*candidateChildNode->Left->Data == *candidateChildNode->Data))
									{
										// go down
										candidateChildNode = candidateChildNode->Left;
									};

									if (candidateChildNode->Left != nullptr)
									{
										candidateParentNode->Right = candidateChildNode->Left;
										candidateParentNode->Right->Parent = candidateParentNode;
									}
									else
										candidateParentNode->Right = nullptr;

								}
							}
						}

						// candidate node - drop current node
						if (mRootNode == currentNode) // insert data same as mRootNode->data 
						{
							mRootNode = candidateNode;
							mRootNode->Parent.reset();
						}
						else
						{
							// 
							if (parentNode->Left == currentNode)
							{
								parentNode->Left = candidateNode;
								parentNode->Left->Parent = parentNode;
							}
							else // Right
							{
								parentNode->Right = candidateNode;
								parentNode->Right->Parent = parentNode;
							}
						}

						// copy existing connection
						candidateNode->Right = currentNode->Right;
						candidateNode->Right->Parent = candidateNode;

						// connect subtree at the left of candidate
						if (subtreeNode != nullptr) // if not subtreeNode == candidateNode
						{
							if (candidateNode->Left == nullptr)
							{
								candidateNode->Left = subtreeNode;
								candidateNode->Left->Parent = candidateNode;
							}
							else
							{
								if (*candidateNode->Left->Data == *candidateNode->Data)
								{
									// Get end of the same data on the left child of candidate
									std::shared_ptr<TreeNode<T>> candidateChildNode;
									candidateChildNode = candidateNode->Left;

									while ((candidateChildNode->Left != nullptr) && (*candidateChildNode->Left->Data == *candidateChildNode->Data))
									{
										// go down
										candidateChildNode = candidateChildNode->Left;
									};

									candidateChildNode->Left = subtreeNode;
									candidateChildNode->Left->Parent = candidateChildNode;
								}
								else
								{
									candidateNode->Left = subtreeNode;
									candidateNode->Left->Parent = candidateNode;
								}
							}
						}
					}

					break; // just in case, not effective
				}
			}
		}

		return bSearchResult;
	}

	// static member function
	template<typename T>
	std::vector<T>  BinarySearchTree<T>::TraverseInOrder(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> result;
		std::stack<std::shared_ptr<TreeNode<T>>> traverseStack;
		std::shared_ptr<TreeNode<T>> currentNode;
		std::shared_ptr<TreeNode<T>> currentParentNode;
		bool bPrevPopedNode;

		currentNode = startNode;
		bPrevPopedNode = false;

		if (currentNode != nullptr) // not empty tree
		{
			// L->V->R
			do
			{
				if ((currentNode->Left != nullptr) && (bPrevPopedNode == false)) // ignore above condition if no right child	
				{
					traverseStack.push(currentNode);
					bPrevPopedNode = false;
					currentParentNode = currentNode;
					currentNode = currentNode->Left; // Left Down

					if (currentParentNode != currentNode->Parent.lock())
					{
						assert(currentParentNode == currentNode->Parent.lock()); // check upside ptr 
					}
				}
				else
				{
					result.insert(result.end(), *currentNode->Data); // push to vector

					if (currentNode->Right != nullptr)
					{
						currentParentNode = currentNode;
						currentNode = currentNode->Right; // Right Down

						if (currentParentNode != currentNode->Parent.lock())
						{
							assert(currentParentNode == currentNode->Parent.lock()); // check upside ptr 
						}

						bPrevPopedNode = false;

					}
					else // currentNode has left nor right (leaf)
					{
						if (traverseStack.empty() == false)
						{
							currentNode = traverseStack.top(); // Up
							traverseStack.pop();
							bPrevPopedNode = true;
						}
						else
						{
							currentNode = nullptr; // nothing to traverse
							bPrevPopedNode = false;
						}
					}
				}
			} while (currentNode != nullptr);
		}

		return result;
	}

	template<typename T>
	std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::getLeftMostNode(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::shared_ptr<TreeNode<T>> currentNode;
		std::shared_ptr<TreeNode<T>> resultNode;

		currentNode = startNode;
		
		// Keep going to Left until Left child is null
		while (1)
		{
			if (currentNode == nullptr) // wrong parameter !!!
			{
				resultNode = nullptr;

				//assert(0);

				break;
			}
			else
			{
				if (currentNode->Left != nullptr)
				{
					currentNode = currentNode->Left; // Left Down
				}
				else // left most
				{
					resultNode = currentNode;

					break;
				}
			}
		}

		return resultNode;
	}

	template<typename T>
	std::shared_ptr<TreeNode<T>> BinarySearchTree<T>::getRightMostNode(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::shared_ptr<TreeNode<T>> currentNode;
		std::shared_ptr<TreeNode<T>> resultNode;

		currentNode = startNode;

		// Keep going to Right until Right child is null
		while (1)
		{
			if (currentNode == nullptr) // wrong parameter !!!
			{
				resultNode = nullptr;

				//assert(0);

				break;
			}
			else
			{
				if (currentNode->Right != nullptr)
				{
					currentNode = currentNode->Right; // Right Down
				}
				else // Right most
				{
					resultNode = currentNode;

					break;
				}
			}
		}

		return resultNode;
	}
	template<typename T>
	bool BinarySearchTree<T>::isLeaf(const std::shared_ptr<TreeNode<T>> leafNode)
	{
		if ((leafNode->Left == nullptr) && (leafNode->Right == nullptr))
			return true;
		else
			return false;
	}
	template<typename T>
	std::vector<T> BinarySearchTree<T>::CheckBSTRule(const std::shared_ptr<TreeNode<T>> startNode)
	{
		std::vector<T> result;
		result = TraverseInOrder(startNode);

		T prev = NULL;

		for (auto it = result.begin(); it != result.end(); ++it)
		{
			//cout << *it << " ";

			if (it != result.begin())
			{
				assert(prev <= *it); // "BST Rule fails"
			}

			prev = *it;
		}

		return result;
	}
}