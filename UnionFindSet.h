#pragma once
#include <vector>

class UnionFindSet
{
public:
	UnionFindSet(int size)
		: _ufs(size, -1)
	{}

	size_t FindRoot(int x)
	{
		int root = x;
		while (_ufs[root] >= 0) {
			root = _ufs[root];
		}

		//·��ѹ��
		while (_ufs[x] >= 0)
		{
			int parent = _ufs[x];
			_ufs[x] = root;

			x = parent;
		}

		return root;
	}

	void Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);

		if (root1 == root2) {
			return;
		}

		//��������С������ļ��Ϻϲ�
		if (_ufs[root1] < _ufs[root2]) {
			std::swap(root1, root2);
		}

		_ufs[root1] += _ufs[root2];
		_ufs[root2] = root1;
	}

	//�Ƿ���ͬһ����
	bool InSet(int x1, int x2)
	{
		return FindRoot(x1) == FindRoot(x2);
	}

	//���ϸ���
	size_t SetCount()
	{
		size_t count = 0;
		for (int i = 0; i < _ufs.size(); i++) {
			if (_ufs[i] < 0 ) {
				++count;
			}
		}

		return count;
	}

private:
	std::vector<int> _ufs;
};

void TestUFS()
{
	UnionFindSet u(10);

	u.Union(0, 6);
	u.Union(7, 6);
	u.Union(7, 8);

	u.Union(1, 4);
	u.Union(4, 9);

	u.Union(2, 3);
	u.Union(2, 5);

}