#include "Graph.h"

// 图中任意两个点，借助1为中转点找更新
//for (int k = 0; k < n; ++k)
//{
//	for (int i = 0; i < n; ++i)
//	{
//		for (int j = 0; j < n; ++j)
//		{
//			if (e[i][k] + e[k][j] < e[i][j])
//			{
//				e[i][j] = e[i][k] + e[k][j];
//			}
//		}
//	}
//}



int main()
{
	Matrix::TestGraph();

	return 0;
}