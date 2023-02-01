#ifndef BIT_VECTOR
#define BIT_VECTOR
#include <iostream>

template<size_t SZ>
class bit_vector
{
	public:
		bit_vector();
		~bit_vector();
		void set(size_t index);
		void reset(size_t index);
	private:
		size_t* m_num;
};

template<size_t SZ>
bit_vector<SZ>::bit_vector()
{
	int count = (SZ - 1) / sizeof(long) * 8;
	m_num = new long[count];
}

template<size_t SZ>
bit_vector<SZ>::~bit_vector()
{
	delete[] m_num;
}

template<size_t SZ>
void bit_vector<SZ>::set(size_t index)
{
	if (index >= SZ)
	{
		std::cerr << "Out of range!";
		return;
	}
	m_num[index / (sizeof(long) * 8)] |= 1 << (index % (sizeof(long) * 8));
}

template<size_t SZ>
void bit_vector<SZ>::reset(size_t index)
{
	if (index >= SZ)
	{
		std::cerr << "Out of range!";
		return;
	}
	m_num[index / (sizeof(long) * 8)] &= ~(1 << (index % (sizeof(long) * 8)));
}

#endif
