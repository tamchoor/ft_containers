#ifndef ITERATOR_HPP
# define ITERATOR_HPP

// # include <__iterator/iterator_traits.h>
namespace ft
{

	template < class iter >
	struct iterator_traits
	{
		typedef typename iter::difference_type		difference_type;
		typedef typename iter::value_type			value_type;
		typedef typename iter::pointer				pointer;
		typedef typename iter::reference			reference;
		typedef typename iter::iterator_category	iterator_category;
	};

	template < class T >
	struct iterator_traits< T* >
	{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef T*										pointer;
		typedef T&										reference;
		typedef std::random_access_iterator_tag			iterator_category;
	};

	template <class T>
	struct iterator_traits<const T*>
	{
		typedef ptrdiff_t								difference_type;
		typedef T										value_type;
		typedef const T*								pointer;
		typedef const T&								reference;
		typedef std::random_access_iterator_tag			iterator_category;
	};

template<typename T>
class iterator
{
	public:
		typedef T value_type;
		typedef std::ptrdiff_t difference_type;
		typedef value_type* pointer;
		typedef value_type& reference;
		typedef value_type const * const_pointer;
		typedef value_type const & const_reference;
		typedef std::random_access_iterator_tag iterator_category;
		typedef iterator< const T > const_iterator;

	
	protected:
		pointer p;

	public:
		iterator(): p(nullptr) {}
		iterator(pointer p): p(p) {}
		iterator(iterator const &other): p(other.p) {}
		~iterator() {}

		iterator &operator=(iterator const &other) 
		{
			this->p = other.p;
			return (*this);
		}
		reference operator*() 
		{
			return (*this->p);
		}
		const_reference operator*() const 
		{
			return (*this->p);
		}
		pointer operator->() 
		{
			return (this->p);
		}
		const_pointer operator->() const 
		{
			return (this->p);
		}
		reference operator[](int val) 
		{
			return (*(this->p + val));
		}
		const_reference operator[](int val) const 
		{
			return (*(this->p + val));
		}

		iterator operator++(int) 
		{
			iterator tmp(*this);
			++this->p;
			return (tmp);
		}
		iterator &operator++() 
		{
			++this->p;
			return (*this);
		}
		iterator operator--(int) 
		{
			iterator tmp(*this);
			--this->p;
			return (tmp);
		}
		iterator &operator--() 
		{
			--this->p;
			return (*this);
		}
		iterator &operator+=(int value) 
		{
			this->p += value;
			return (*this);
		}
		iterator operator+(int value) const 
		{
			iterator tmp(*this);
			return (tmp += value);
		}
		iterator &operator-=(int value) 
		{
			this->p -= value;
			return (*this);
		}
		iterator operator-(int value) const 
		{
			iterator tmp(*this);
			return (tmp -= value);
		}
		difference_type operator-(iterator const &other) const 
		{
			return (this->p - other.p);
		}

		bool operator==(iterator const &other) const 
		{
			return (this->p == other.p);
		}
		bool operator!=(iterator const &other) const 
		{
			return (this->p != other.p);
		}
		bool operator<(iterator const &other) const 
		{
			return (this->p < other.p);
		}
		bool operator<=(iterator const &other) const 
		{
			return (this->p <= other.p);
		}
		bool operator>(iterator const &other) const 
		{
			return (this->p > other.p);
		}
		bool operator>=(iterator const &other) const 
		{
			return (this->p >= other.p);
		}

};
		
		// template<bool Cond, class T = void> struct enable_if {};
		// template<class T> struct enable_if<true, T> { typedef T type; };

		    template <bool is_integral, typename T>
        struct is_integral_res {
            typedef T type;
            static const bool value = is_integral;
            };

    /*
    ** @brief default template of the structure is_integral_type.
    ** If the type given in argument is from the list, the structure
    ** will be overide by nexts, in according to it type.
    ** If the type given is argument isn't in the list, 
    ** stocked value will be false. So it's not a integral type.
    */
    template <typename>
        struct is_integral_type : public is_integral_res<false, bool> {};

    /* @brief is_integral_type for bool. "value is true".*/
    template <>
        struct is_integral_type<bool> : public is_integral_res<true, bool> {};

    /* @brief is_integral_type for char. "value is true".*/
    template <>
        struct is_integral_type<char> : public is_integral_res<true, char> {};

    /* @brief is_integral_type for signed char. "value is true".*/
    template <>
        struct is_integral_type<signed char> : public is_integral_res<true, signed char> {};

    /* @brief is_integral_type for short int. "value is true".*/
    template <>
        struct is_integral_type<short int> : public is_integral_res<true, short int> {};
    
    /* @brief is_integral_type for int. "value is true".*/
    template <>
        struct is_integral_type<int> : public is_integral_res<true, int> {};

    /* @brief is_integral_type for long int. "value is true".*/
    template <>
        struct is_integral_type<long int> : public is_integral_res<true, long int> {};

    /* @brief is_integral_type for long long int. "value is true".*/
    template <>
        struct is_integral_type<long long int> : public is_integral_res<true, long long int> {};

    /* @brief is_integral_type for unsigned char. "value is true".*/
    template <>
        struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> {};

    /* @brief is_integral_type for unsigned short int. "value is true".*/
    template <>
        struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> {};

    /* @brief is_integral_type for unsigned int. "value is true".*/
    template <>
        struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> {};

    /* @brief is_integral_type for unsigned long int. "value is true".*/
    template <>
        struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};
    
    /* @brief is_integral_type for unsigned long long int. "value is true".*/
    template <>
        struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};

    /*
    ** @brief Give a structure who contain is the
    ** typename given in template is integral or not,
    ** stocked in "value".
    */
    template <typename T>
        struct is_integral : public is_integral_type<T> { };

	template<bool Cond, class T = void>
	struct enable_if {};
    template<class T> 
	struct enable_if<true, T> { typedef T type; };


	template<class InputIterator>
        typename iterator_traits<InputIterator>::difference_type distance (InputIterator first, InputIterator last,
			typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0)
        {
            typename iterator_traits<InputIterator>::difference_type rtn = 0;
            while (first != last)
            {
                ++first;
                ++rtn;
            }
            return (rtn);
        };
	static class nullptr_t
{
    public:
        /*
        ** @brief For conversion to any type
        ** of null non-member pointer.
        */
        template<class T>
        operator T*() const { return (0); }

        /*
        ** @brief For conversion to any type of null
        ** member pointer.
        */
        template<class C, class T>
        operator T C::*() const { return (0); }

    private:
        
        /*
        ** @brief It's imposible to get an address of
        ** a nullptr.
        */
        void operator&() const;

} u_nullptr = {};


}

#endif