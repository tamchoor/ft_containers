# ft_containers
Implement vector container types of the C++ standard template library



You have to take the structure of each standard container as reference. If a part of the Orthodox Canonical form is missing in it, do not implement it.

As a reminder, you have to comply with the C++98 standard, so any later feature of the containers MUST NOT be implemented, but every C++98 feature (even deprecated ones) is expected.

		#Mandatory part

Implement the following containers and turn in the necessary <container>.hpp files with a Makefile:

         • vector

You don’t have to do the vector<bool> specialization.


It will use your vector class as default underlying container. But it must still be compatible with other containers, the STL ones included.\


You also have to implement:

• iterators_traits

• reverse_iterator

• enable_if

Yes, it is C++11 but you will be able to implement it in a C++98 manner. This is asked so you can discover SFINAE.

• is_integral

• equal and/or lexicographical_compare

• std::pair

• std::make_pair

		Requirements

The namespace must be ft.

• Each inner data structure used in your containers must be logical and justified (this
means using a simple array for map is not ok).

• You cannot implement more public functions than the ones offered in the standard containers. Everything else must be private or protected. Each public function or variable must be justified.

• All the member functions, non-member functions and overloads of the standard containers are expected.

• You must follow the original naming. Take care of details.

• If the container has an iterator system, you must implement it.

• You must use std::allocator.

• For non-member overloads, the keyword friend is allowed. Each use of friend must be justified and will be checked during evaluation.
