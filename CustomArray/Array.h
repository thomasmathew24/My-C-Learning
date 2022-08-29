#pragma once

template<typename T>
class ArrayIterator
{
public:
	using Pointer = T*;
	using Reference = T&;

public:
	ArrayIterator(Pointer ptr) 
		: m_Ptr(ptr) {}

	ArrayIterator& operator++()
	{
		m_Ptr++;
		return *this;
	}

	ArrayIterator operator++(int)
	{
		ArrayIterator temp = *this;
		++(*this);
		return temp;
	}

	ArrayIterator& operator--()
	{
		m_Ptr--;
		return *this;
	}

	ArrayIterator operator--(int)
	{
		ArrayIterator temp = *this;
		--(*this);
		return temp;
	}

	Reference operator[](size_t index)
	{
		return *(m_Ptr + index);
		//OR return *(m_Ptr[index]);
	}

	Pointer operator->()
	{
		return m_Ptr;
	}

	Pointer operator*()
	{
		return *m_Ptr;
	}

	bool operator==(const ArrayIterator& other) const
	{
		return m_Ptr == other.m_Ptr;
	}

	bool operator!=(const ArrayIterator& other) const
	{
		return !(*this == other);
	}

private:
	Pointer m_Ptr;
};


template<typename T, size_t size>
class Array
{
private:
	T m_Data[size];

public:
	using Iterator = ArrayIterator<T>;

	Iterator begin()
	{
		return Iterator(m_Data);
	}

	Iterator end()
	{
		return Iterator(m_Data+size);
	}
public:
	constexpr size_t Size() const
	{
		return size;
	}

	T& operator[](size_t index)
	{
		return m_Data[index];
	}

	const T& operator[](size_t index) const
	{
		return m_Data[index];
	}

	T* Data()
	{
		return m_Data;
	}

	const T* Data() const
	{
		return m_Data;
	}
};


