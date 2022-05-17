namespace allen
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			_bits.resize(N / 32 + 1, 0);//向上取整
		}


		//把映射的位标记成1
		void Set(size_t x)
		{
			assert(x < N);
			// 算出x映射的位在第i个整数
		// 算出x映射的位在这个整数的第j个位
			size_t i = x / 32;
			size_t j = x % 32;

			//_bits[i] 的第j位标记成1
			_bits[i] |= (1 << j);
		}

		void Reset(size_t x)
		{
			assert(x < N);
			// 算出x映射的位在第i个整数
		// 算出x映射的位在这个整数的第j个位
			size_t i = x / 32;
			size_t j = x % 32;

			//_bits[i] 的第j位标记成0
			_bits[i] &= (~(1<<j));
		}

		bool Test(size_t x)
		{
			assert(x < N);
			size_t i = x / 32;
			size_t j = x % 32;
			//只判断不改变

			// 如果第j位是1，结果是非0，非0就是真
			// 如果第j为是0，结果是0，0就是假
			return _bits[i] & (1 << j);
		}

	private:
		vector<int> _bits;
	};

	void Test_bitset()
	{
		//bitset<4294967295u> bs;
		bitset<-1> bs;
		/// <summary>
		/// 存入一定量的数
		/// </summary>
	
		//测试某一个数字是不是存在
		bs.Test(9012);
	}
}