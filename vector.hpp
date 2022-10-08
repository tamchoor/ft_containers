#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <vector>

// # include <limits>
// # include <iostream>
#include <memory>
#include "iterator.hpp"
#include "reverse_iterator.hpp"

namespace ft
{
	template < class T, class Allocator = std::allocator<T> > /* = allocator<_Tp> */
	class vector 
	{
		public :
			typedef Allocator allocator_type;
			typedef std::allocator_traits<allocator_type>         _alloc_traits;
			typedef typename _alloc_traits::size_type size_type;

			typedef T value_type;
			typedef value_type& reference;
			typedef const value_type& const_reference;
			typedef T* pointer;

			typedef ft::iterator<value_type> iterator;
			typedef ft::iterator<value_type const> const_iterator;
			typedef ft::reverse_iterator<iterator> reverse_iterator;
			typedef ft::reverse_iterator<const_iterator> const_reverse_iterator;
		

		public :
			explicit vector(): __begin_(nullptr), __end_(nullptr), _end_cap_(nullptr), _size(0), _alloc(allocator_type()) {}

			explicit vector (size_type n, const value_type& val = value_type()): __begin_(nullptr), __end_(nullptr), _end_cap_(nullptr), _size(0), _alloc(allocator_type())
			{
				if (n > 0)
				{
					if (n > max_size())
						throw std::length_error("vector:: n > max");
					__begin_ = _alloc.allocate(n);
					_end_cap_ = __begin_ + n;
					__end_ = __begin_;
					while (n--)
					{
						_alloc.construct(__end_, val);
						++__end_;
					}
				}
			}

			vector (const vector& x)
			: _alloc(x._alloc), __begin_(u_nullptr), __end_(u_nullptr), _end_cap_(u_nullptr)
			{
				this->assign(x.begin(), x.end());
			}

			~vector()
			{
				clear();
				_alloc.deallocate(__begin_, capacity());
			}

			void clear()
			{
				_destruct_at_the_end(__begin_);
				_size = 0;
			}

			size_type size() const
        	{
				return static_cast<size_type>(__end_ - __begin_);
			}

			size_type capacity() const
        	{
				return static_cast<size_type>(_end_cap_ - __begin_);
			}

			pointer data(void) 
			{
				return __begin_;
			}

			reference operator[](size_type __n)
			{
				return (__begin_[__n]);
			}

			const_reference operator[](size_type __n) const
			{
				return (__begin_[__n]);
			}

			reference at (size_type __n)
			{
				if (__n >= size())
					throw std::out_of_range("vector:: out_of_range");
				return (__begin_[__n]);
			}

			const_reference at (size_type __n) const
			{
				if (__n >= size())
					throw std::out_of_range("vector:: out_of_range");
				return (__begin_[__n]);
			}

			void reserve(size_type newSize)
			{
				if (newSize > capacity())
				{
					if (newSize > max_size())
						throw std::length_error("vector::reserve:: n > max");
					
					pointer prevBegin = __begin_;
					pointer prevEnd = __end_;
					size_type prevSize = size();
					size_type prevCapacity = capacity();

					__begin_ = _alloc.allocate(newSize);
					__end_ = __begin_;
					_size = newSize;
					_end_cap_ = __begin_ + newSize;

					while (prevBegin != prevEnd)
					{
						_alloc.construct(__end_, *prevBegin);
						++__end_;
						++prevBegin;
					}
					_alloc.deallocate(prevBegin - prevSize, prevCapacity);
				}
			}

			void resize (size_type n, value_type val = value_type())
			{
				if (n > max_size())
					throw (std::length_error("vector::resize:: n > max"));
				else if (n < size())
				{
					while (size() > n)
					{
						--__end_;
						_alloc.destroy(__end_);
					}
				}
				else
					insert(this->end(), n - this->size(), val);
			}

			iterator insert(const_iterator __position, const_reference __x)
			{
				size_type			i = __position - begin();

				insert(__position, 1, __x);
				return begin() + i;
			}

			void insert(iterator position, size_type j, const value_type& val)
			{
				size_type			i = position - begin();
				size_type			prevSize = size();

				if ((size() + j) > capacity())
					reserve(size() + j);
				for (size_type k = j + prevSize - 1; k > i + j - 1; k--)
				{
					_alloc.construct((__begin_ + k), *(__begin_ + k - j));
					_alloc.destroy((__begin_ + k - j));
				}
				for (size_type l = i; l < i + j; l++)
				{
					_alloc.construct((__begin_ +l), val);
				}
				__end_ = __begin_ + _size;
			}

			template <class InputIterator>
			void	insert( iterator position, InputIterator first, InputIterator last,
				typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
			{
				size_type			i = position - begin();
				size_type			j = ft::distance(first, last);
				size_type			prevSize = size();

				if ((size() + j) > capacity())
					reserve(size() + j);
				for (size_type k = j + prevSize - 1; k > i + j - 1; k--)
				{
					_alloc.construct((__begin_ + k), *(__begin_ + k - j));
					_alloc.destroy((__begin_ + k - j));
				}
				for (size_type l = i; l < i + j; l++)
				{
					_alloc.construct((__begin_ +l), *first);
					++first;
				}
				__end_ = __begin_ + _size;
			}

			void push_back(const_reference val)
			{
				size_type _capacity = capacity();
				if (_size == _capacity && _size > 7)
					reserve(_capacity * 1.5);
				else if (_size == _capacity)
					reserve(_capacity + 1);
				if (_size < _capacity)
				{
					_alloc.construct(__end_, val);
					++__end_;
					++_size;
				}
			}

			void pop_back()
			{
				if (!empty())
				{
					_alloc.destroy(&this->back());
					--__end_;
					--_size;
				}
			}

			bool empty() const
			{
				return this->__begin_ == this->__end_;
			}

			reference front () 
			{
				return (*__begin_); 
			}

			const_reference front () const 
			{
				return (*__begin_); 
			}

			reference back()
			{
					return *(this->__end_ - 1);
			}

			const_reference back()  const
			{
					return *(this->__end_ - 1);
			}

			size_type max_size(void) const 
			{ 
				return allocator_type().max_size(); 
			}

			iterator begin() 
			{ 
				return (__begin_); 
			}

			const_iterator begin() const 
			{
				return (__begin_);
			}

			iterator end()
			{
				return (iterator(__end_));
			}

			const_iterator end() const
			{
				return (const_iterator(__end_));
			}

			reverse_iterator rbegin() 
			{
				return (reverse_iterator(this->end())); 
			}

			const_reverse_iterator rbegin() const 
			{
				return (reverse_iterator(this->end())); 
			}

			reverse_iterator rend() 
			{ 
				return (reverse_iterator(this->begin())); 
			}

			const_reverse_iterator rend() const 
			{ 
				return (reverse_iterator(this->begin())); 
			}

			void assign(size_type __n, const_reference __u)
			{
				this->clear();
				if (__n == 0)
					return ;
				if (__n <= capacity())
    			{
					for(int n = 0; n < __n; n++)
					{
						_alloc.construct(__end_, __u);
						++__end_;
					} 
				}
				else
				{
					this->reserve(__n);
					for(int n = 0; n < __n; n++)
					{
						_alloc.construct(__end_, __u);
						++__end_;
					}
				}
				_size = __n;
			}

			template <class InputIterator>
			void assign(InputIterator first, InputIterator last, 
			typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = u_nullptr)
			{
				size_type __new_size = ft::distance(first, last);
				this->clear();
				if (__new_size <= capacity())
				{
					while( &(*first) != &(*last))
					{
						_alloc.construct(__end_, *first);
						++first;
						++__end_;
					} 
				}
				else 
				{
					this->reserve(__new_size);
					while( &(*first) != &(*last))
					{
						_alloc.construct(__end_, *first);
						++first;
						++__end_;
					}

				}
				_size = __new_size;
			}



		private:

			pointer __begin_;
			pointer __end_;
			pointer _end_cap_;
			size_type _size;
			allocator_type  _alloc;


			void _destruct_at_the_end(pointer new_last)
			{
				pointer __soon_to_be_end = __end_;
				while (new_last != __soon_to_be_end)
					_alloc.destroy(--__soon_to_be_end);
				__end_ = new_last;
			}
	};
}

#endif