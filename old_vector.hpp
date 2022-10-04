// #ifndef OVECTOR_HPP
// # define OVECTOR_HPP

// # include <limits>
// # include <iostream>
// #include <memory>

// namespace ft
// {
// 	// template <class T>
// 	// class __vector_base
// 	// {
// 	// 	public :
// 	// 		// typedef Allocator allocator_type;
// 	// 		typedef unsigned long size_type;

// 	// 	protected :
// 	// 		typedef T value_type;
// 	// 		typedef value_type& reference;
// 	// 		typedef const value_type& const_reference;
// 	// 		typedef T* pointer;
// 	// 		typedef pointer iterator;
// 	// 		typedef const iterator const_iterator;
			
		

// 	// 		pointer __begin_;
// 	// 		pointer __end_;
// 	// 		size_type _end_cap_;

// 	// };

// 	template < typename T, Allocator = std::allocator<T> /* = allocator<_Tp> */>
// 	class vector 
// 	{
// 		public :
// 			typedef Allocator allocator_type;
// 			typedef unsigned long size_type;

// 			typedef T value_type;
// 			typedef value_type& reference;
// 			typedef const value_type& const_reference;
// 			typedef T* pointer;
// 			typedef pointer iterator;
// 			typedef const iterator const_iterator;
		

// 		public :
// 			explicit vector(): __begin_(nullptr), __end_(nullptr), _end_cap_(nullptr), _size(0) {}

// 			explicit vector (size_type n): __begin_(nullptr), __end_(nullptr), _end_cap_(nullptr), _size(0) 
// 			{
// 				__begin_ = allocator_type.allocate(n);
// 				_end_cap_ = __begin_ + n;
// 				__end_ = __begin_;
// 				while (n--)
// 				{
// 					allocator_type.construct(_end, val);
// 					++__end_;
// 				}
// 			}

// 			vector (vector const & ref) :__begin_(nullptr), __end_(nullptr), _end_cap_(0), _size(ref._size)
// 			{
// 				this->reserve(ref._end_cap_);
// 				if (ref.__begin_)
// 				{
// 					size_type i;
// 					for (i = 0; i < _size; i++)
// 					{
// 						*(__begin_ + i) = *(ref.__begin_ + i);
// 					}
// 					__end_ = (__begin_ + i);
// 				}
// 			}

// 			vector &operator=(vector const &ref)
// 			{
// 				if (this == &ref)
// 				{
// 					return *this;
// 				}
// 				this->reserve(ref._end_cap_);
// 				if (ref.__begin_)
// 				{
// 					size_type i;
// 					for (i = 0; i < _size; i++)
// 					{
// 						*(__begin_ + i) = *(ref.__begin_ + i);
// 					}
// 					__end_ = (__begin_ + i);
// 				}
// 				_size = ref._size;
// 				return *this;
// 			}

// 			~vector()
// 			{
// 				if (__begin_)
// 					delete __begin_;
// 			}

// 			bool empty(void) const 
// 			{
// 				return this->__begin_ == this->__end_;
// 			}

// 			reference operator[](size_type __n)
// 			{
// 				return (__begin_[__n]);
// 			}

// 			const_reference operator[](size_type __n) const
// 			{
// 				return (__begin_[__n]);
// 			}

// 			reference at(size_type __n)
// 			{
// 				if (__n >= _size)
// 					throw std::logic_error("vector"); //"vector[] index out of bounds"
// 				return (__begin_[__n]);
// 			}

// 			const_reference at(size_type __n) const
// 			{
// 				if (__n >= _size)
// 					throw std::logic_error("vector"); //"vector[] index out of bounds"
// 				return (__begin_[__n]);
// 			}

// 			reference front(void) 
// 			{
// 				return *__begin_;
// 			}

// 			const_reference front(void) const
// 			{
// 				return *__begin_;
// 			}

// 			reference back(void) 
// 			{
// 				return *(__end_ - 1);
// 			}

// 			const_reference back(void) const
// 			{
// 				return *(__end_ - 1);
// 			}

// 			pointer data(void) 
// 			{
// 				return __begin_;
// 			}

// 			const_pointer data(void) const
// 			{
// 				return __begin_;
// 			}

// 			size_type size(void) const 
// 			{
// 				return (this->_size);
// 			}

// 			size_type max_size(void) const
// 			{
// 				return (ft::min((size_type) std::numeric_limits<difference_type>::max(),
// 						std::numeric_limits<size_type>::max() / sizeof(value_type)));
// 			}

// 			size_type capacity(void) const 
// 			{
// 				return (this->_end_cap_);
// 			}
			
// 			void reserve(size_type newSize)
// 			{
// 				if (newSize > _end_cap_)
// 				{
// 					value_type * tmp = static_cast<value_type*> (::operator new (sizeof(value_type) * newSize));
// 					swapArrays(tmp, newSize);
// 				}
// 			}

// 			void resize(size_type size)
// 			{
// 				if (size > this->_end_cap)
// 					this->reserve(size);
// 				if (size > this->m_size)
// 				{
// 					value_type val=value_type();
// 					for (size_type i = this->m_size; i < size; ++i)
// 						*(this->__begin_ + i) = val;
// 				}
// 				else if (size < this->m_size)
// 				{
// 					for (size_type i = size; i < this->m_size; ++i)
// 						this->__begin_ + i.value_type::~value_type();
// 				}
// 					this->m_size = size;
// 			}

// 			void push_back(const_reference val)
// 			{
// 				if (_size == _end_cap_ && _size > 7)
// 					reserve(_end_cap_ * 1.5);
// 				else if (_size == _end_cap_)
// 					reserve(_end_cap_ + 1);
// 				if (_size < _end_cap_)
// 				{
// 					*__end_ = val;
// 					__end_ = __end_ + 1;
// 					_size = _size + 1;
// 				}
// 			}

// 			void pop_back(void) 
// 			{
// 				__end_::~value_type();
// 				__end_ = __end_ - 1;
// 				_size = _size - 1;
// 			}

// 			void swap(vector &other)
// 			{
// 				vector<value type> tmp;

// 				tmp.copyAllPointers(this);
// 				this->copyAllPointers(other);
// 				other.copyAllPointers(tmp);
// 			}

// 		private:

// 			pointer __begin_;
// 			pointer __end_;
// 			pointer _end_cap_;
// 			size_type _size;

// 		private : /*funcs for public funcs*/
// 			void swapArrays(value_type * tmp, size_type newSize)
// 			{
// 				value_type * tmpEnd = tmp;

// 				if (__begin_)
// 				{
// 					size_type i;
// 					for (i = 0; i < _size; i++)
// 					{
// 						*(tmp + i) = *(__begin_ + i);
// 					}
// 					tmpEnd = (tmp + i);
// 					delete __begin_;
// 				}
// 				__begin_ = tmp;
// 				__end_ = tmpEnd;
// 				_end_cap_ = newSize;
// 			}

// 			void copyAllPointers(vector const &ref)
// 			{
// 				ref._size = _size;
// 				ref.__begin_ = __begin_;
// 				ref.__end_ = __end_;
// 				ref._end_cap_ = _end_cap_;
// 			}

// 			size_type max_size() const
// 			{
// 				return allocator_type().max_size();
// 			}
// 	};
// }

// #endif
