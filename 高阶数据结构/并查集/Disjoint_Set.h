#pragma once

class UnionFindSet
{
public:
	UnionFindSet(size_t size)
		: _ufs(size, -1)
	{}

	bool Union(int x1, int x2)
	{
		int root1 = FindRoot(x1);
		int root2 = FindRoot(x2);
		// x1�Ѿ���x2��ͬһ������
		if (root1 == root2)
			return false;
		
		// ������������Ԫ�غϲ�
		_ufs[root1] += _ufs[root2];
		// ������һ���������Ƹı������һ��
		_ufs[root2] = root1;
		return true;
	}

	// �����и����ĸ�������Ϊ���ϵĸ���
	size_t Count()const
	{
		size_t count = 0;
		for (auto e : _ufs)
		{
			if (e < 0)
				++count;
		}
		return count;
	}

	// ��һ��Ԫ�صı�ţ��ҵ���Ԫ�����ڼ��ϵ�����
	int FindRoot(int index)
	{
		assert(index < _ufs.size());
		// ��������д洢���Ǹ������ҵ�������һֱ����
		while (_ufs[index] >= 0)
		{
			index = _ufs[index];
		}
		return index;
	}

	size_t Size()
	{
		size_t n = 0;
		for (int i = 0; i < _ufs.size(); i++)
		{
			if (_ufs[i] < 0)
			{
				n++;
			}
		}
		return n;
	}
private:
	vector<int> _ufs;
};