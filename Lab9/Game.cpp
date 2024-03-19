#include "Game.h"

namespace lab9
{
	Game::Game(unsigned int seed, size_t poolSize) : mObjects(poolSize)
	{
		srand(seed);
	}

	Game::~Game()
	{
		size_t count;
		count = mActiveGameObjects.size();

		for (unsigned int i = 0; i < count; i++)
		{
			delete mActiveGameObjects[i];
		}
	}

	void Game::Spawn()
	{	
		IceCube* iceCube = mObjects.Get(); // get one from non active pool
		iceCube->Initialize(rand() % MAX_FRAME_COUNT_TO_LIVE + 1);
		mActiveGameObjects.push_back(iceCube); // active
	}

	void Game::Update()
	{
		for (auto it = mActiveGameObjects.begin(); it != mActiveGameObjects.end();)
		{
			IceCube* iceCube = *it;
			iceCube->Animate();

			if (!iceCube->IsActive())
			{
				it = mActiveGameObjects.erase(it); // after erase, next element goes down -> no need to ++it
				mObjects.Return(iceCube); // return to non active pool
				continue;
			}
			else
			{
				++it;
			}
		}
	}
	
	const std::vector<IceCube*>& Game::GetActiveGameObjects() const
	{
		return mActiveGameObjects;
	}

	ObjectPool<IceCube>& Game::GetObjectPool()
	{
		return mObjects;
	}
}