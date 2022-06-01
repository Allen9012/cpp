#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <map>
using namespace std;

// �ڽӾ���
namespace Matrix
{
	template<class V, class W, bool Direction = false>
	class Graph
	{
	public:
		Graph(const V* vertexs, size_t n)
		{
			_vertexs.reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				_vertexs.push_back(vertexs[i]);
				_vIndexMap[vertexs[i]] = i;
			}

			_matrix.resize(n);
			for (auto& e : _matrix)
			{
				e.resize(n);
			}
		}

		size_t GetVertexIndex(const V& v)
		{
			auto ret = _vIndexMap.find(v);
			if (ret != _vIndexMap.end())
			{
				return ret->second;
			}
			else
			{
				throw invalid_argument("�����ڵĶ���");
				return -1;
			}
		}

		void AddEdge(const V& src, const V& dst, const W& w)
		{
			size_t srcindex = GetVertexIndex(src);
			size_t dstindex = GetVertexIndex(dst);

			_matrix[srcindex][dstindex] = w;//����Ȩֵ
			if (Direction == false)
			{
				_matrix[dstindex][srcindex] = w;
			}
		}

		void BFS(const V& src)
		{
			size_t srcindex = GetVertexIndex(src);
			vector<bool> visited;
			visited.resize(_vertexs.size(), false);

			queue<int> q;
			q.push(srcindex);
			visited[srcindex] = true;
			size_t d = 1;
			size_t dSize = 1;

			while (!q.empty())
			{
				printf("%s��%d�Ⱥ���:", src.c_str(), d);

				while (dSize--)
				{
					size_t front = q.front();
					q.pop();
					for (size_t i = 0; i < _vertexs.size(); ++i)
					{
						if (visited[i] == false && _matrix[front][i] != W())
						{
							printf("[%d:%s] ", i, _vertexs[i].c_str());
							visited[i] = true;
							q.push(i);
						}
					}
				}
				cout << endl;

				dSize = q.size();
				++d;
			}
		}

		void _DFS(size_t srcIndex, vector<bool>& visited)
		{
			printf("[%d:%s]->", srcIndex, _vertexs[srcIndex].c_str());
			visited[srcIndex] = true;
			// srcIndex->i
			for (size_t i = 0; i < _vertexs.size(); ++i)
			{
				if (visited[i] == false && _matrix[srcIndex][i] != W())
				{
					_DFS(i, visited);
				}
			}
		}


		void DFS(const V& src)
		{
			size_t srcindex = GetVertexIndex(src);
			vector<bool> visited;
			visited.resize(_vertexs.size(), false);

			_DFS(srcindex, visited);
		}


	private:
		map<string, int> _vIndexMap;
		vector<V> _vertexs;			 // ���㼯��
		vector<vector<W>> _matrix;   // �洢�߼��ϵľ���
	};

	void TestGraph()
	{
		string a[] = { "����", "����", "����", "����", "����" };
		Graph<string, int> g1(a, sizeof(a)/sizeof(string));
		g1.AddEdge("����", "����", 100);
		g1.AddEdge("����", "����", 200);
		g1.AddEdge("����", "����", 30);
		g1.AddEdge("����", "����", 30);

		g1.BFS("����");

		g1.DFS("����");
	}
}


// �ڽӱ�
namespace LinkTable
{
	template<class W>
	struct LinkEdge
	{
		int _srcIndex;
		int _dstIndex;
		W _w;
		LinkEdge<W>* _next;

		LinkEdge(const W& w)
			: _srcIndex(-1)
			, _dstIndex(-1)
			, _w(w)
			, _next(nullptr)
		{}
	};

	template<class V, class W, bool Direction = false>
	class Graph
	{
		typedef LinkEdge<W> Edge;
	public:
		Graph(const V* vertexs, size_t n)
		{
			_vertexs.reserve(n);
			for (size_t i = 0; i < n; ++i)
			{
				_vertexs.push_back(vertexs[i]);
				_vIndexMap[vertexs[i]] = i;
			}

			_linkTable.resize(n, nullptr);
		}

		size_t GetVertexIndex(const V& v)
		{
			auto ret = _vIndexMap.find(v);
			if (ret != _vIndexMap.end())
			{
				return ret->second;
			}
			else
			{
				throw invalid_argument("�����ڵĶ���");
				return -1;
			}
		}

		void AddEdge(const V& src, const V& dst, const W& w)
		{
			size_t srcindex = GetVertexIndex(src);
			size_t dstindex = GetVertexIndex(dst);

			// 0 1
			Edge* sd_edge = new Edge(w);
			sd_edge->_srcIndex = srcindex;
			sd_edge->_dstIndex = dstindex;
			//ͷ��
			sd_edge->_next = _linkTable[srcindex];
			_linkTable[srcindex] = sd_edge;

			// 1 0
			// ����ͼ
			if (Direction == false)
			{
				Edge* ds_edge = new Edge(w);
				ds_edge->_srcIndex = dstindex;
				ds_edge->_dstIndex = srcindex;
				ds_edge->_next = _linkTable[dstindex];
				_linkTable[dstindex] = ds_edge;
			}
		}


	private:
		map<string, int> _vIndexMap;
		vector<V> _vertexs;			 // ���㼯��
		vector<Edge*> _linkTable;    // �ߵļ��ϵ��ٽӱ�
	};

	void TestGraph()
	{
		string a[] = { "����", "����", "����", "����" };
		Graph<string, int> g1(a, 4);
		g1.AddEdge("����", "����", 100);
		g1.AddEdge("����", "����", 200);
		g1.AddEdge("����", "����", 30);
	}
}