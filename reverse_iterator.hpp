#ifndef REVERSE_ITERATOR_HPP
# define REVERSE_ITERATOR_HPP


namespace ft
{
template<typename iterator>
class reverse_iterator: public iterator
{
public:
	using typename iterator::value_type;
    using typename iterator::pointer;
    using typename iterator::const_pointer;
    using typename iterator::reference;
    using typename iterator::const_reference;
    using typename iterator::difference_type;
public:
	reverse_iterator(): iterator() {}
	reverse_iterator(iterator const &it): iterator(it) {}
	reverse_iterator(reverse_iterator const &other): iterator(other.p) {}
	~reverse_iterator() {}
	
	reverse_iterator &operator=(reverse_iterator const &other)
	{
		this->p = other.p;
		return (*this);
	}

	reference operator*() 
	{
		iterator tmp(*this);
		return (*--tmp);
	}
	const_reference operator*() const 
	{
		iterator tmp(*this);
		return (*--tmp);
	}
	pointer operator->() 
	{
		iterator tmp(*this);
		return (&*--tmp);
	}
	const_pointer operator->() const 
	{
		iterator tmp(*this);
		return (&*--tmp);
	}
	reverse_iterator operator++(int) 
	{
		reverse_iterator tmp(*this);
		operator++();
		return (tmp);
	}
	iterator &operator++() 
	{
		return (this->iterator::operator--());
	}
	reverse_iterator operator--(int) 
	{
		reverse_iterator tmp(*this);
		operator--();
		return (tmp);
	}
	iterator &operator--() 
	{
		return (this->iterator::operator++());
	}
};
}

#endif
