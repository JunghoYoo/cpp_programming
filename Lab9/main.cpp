#include <cassert>
#include <vector>
#include "IceCube.h"
#include "ObjectPool.h"
#include "Game.h"

using namespace lab9;

int main()
{
	ObjectPool<IceCube> pool(3);

	assert(pool.GetMaxFreeObjectCount() == 3);
	assert(pool.GetFreeObjectCount() == 0);

	IceCube* i1 = pool.Get();// 1�� �����ؼ� �����ش� 

	i1->Initialize(5);

	IceCube* i2 = pool.Get();// 1�� �����ؼ� �����ش� 
	i2->Initialize(1);

	IceCube* i3 = pool.Get();// 1�� �����ؼ� �����ش� 
	i3->Initialize(4);

	assert(pool.GetFreeObjectCount() == 0);
	i1->Reset(); // i1-0
	pool.Return(i1); //1��°-0
	assert(pool.GetFreeObjectCount() == 1); // i1 

	IceCube* i4 = pool.Get();// i1�� �����ش� 

	assert(i1 == i4); // ����
	assert(!(i4->IsActive()));//i4-0

	pool.Return(i2);//1��°-1
	pool.Return(i3);//2��°-4
	pool.Return(i4);//3��°-0

	////////////////////////////////////////////////

	Game game(1, 4);
	const std::vector<IceCube*>& activeGameObjects = game.GetActiveGameObjects();
	assert(activeGameObjects.size() == 0);

	game.Spawn(); // 42
	game.Spawn(); // 68
	game.Spawn(); // 35
	game.Spawn(); // 1
	game.Spawn(); // 70

	assert(activeGameObjects.size() == 5); // Spawn�� maxpool�� ������� Ŀ���� -> spawn �ϸ� active �ϱ�
	assert(activeGameObjects[0]->IsActive());
	assert(activeGameObjects[1]->IsActive());
	assert(activeGameObjects[2]->IsActive());
	assert(activeGameObjects[3]->IsActive());
	assert(activeGameObjects[4]->IsActive());

	const IceCube* i5 = activeGameObjects[3];

	game.Update(); // 4��°�� �������� ������ ���� - seed ���� 1�϶� �׷��� �Ǵµ�?

	const std::vector<IceCube*>& activeGameObjects2 = game.GetActiveGameObjects();
	assert(activeGameObjects2.size() == 4);
	assert(activeGameObjects[0] == activeGameObjects2[0]);
	assert(activeGameObjects[1] == activeGameObjects2[1]);
	assert(activeGameObjects[2] == activeGameObjects2[2]);
	assert(activeGameObjects[3] == activeGameObjects2[3]);
	// op2 const lab9::ObjectPool<lab9::IceCube> &
	auto& op2 = game.GetObjectPool();
	IceCube* i6 = op2.Get(); 

	assert(i6 == i5); // Pool���� ���� == 4��°�� ������ : GetActiveGameObjects �� GetObjectPool�� ������ ���͸� �����ϴ� ��

	op2.Return(i6);
}