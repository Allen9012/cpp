namespace allen
{
	template<size_t N>
	class bitset
	{
	public:
		bitset()
		{
			_bits.resize(N / 32 + 1, 0);//����ȡ��
		}


		//��ӳ���λ��ǳ�1
		void Set(size_t x)
		{
			assert(x < N);
			// ���xӳ���λ�ڵ�i������
		// ���xӳ���λ����������ĵ�j��λ
			size_t i = x / 32;
			size_t j = x % 32;

			//_bits[i] �ĵ�jλ��ǳ�1
			_bits[i] |= (1 << j);
		}

		void Reset(size_t x)
		{
			assert(x < N);
			// ���xӳ���λ�ڵ�i������
		// ���xӳ���λ����������ĵ�j��λ
			size_t i = x / 32;
			size_t j = x % 32;

			//_bits[i] �ĵ�jλ��ǳ�0
			_bits[i] &= (~(1<<j));
		}

		bool Test(size_t x)
		{
			assert(x < N);
			size_t i = x / 32;
			size_t j = x % 32;
			//ֻ�жϲ��ı�

			// �����jλ��1������Ƿ�0����0������
			// �����jΪ��0�������0��0���Ǽ�
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
		/// ����һ��������
		/// </summary>
	
		//����ĳһ�������ǲ��Ǵ���
		bs.Test(9012);
	}
}