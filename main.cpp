#include "vector.hpp"
#include <vector>
#include <iostream>
	void print_vector(ft::vector<int> &vec)
	{
		ft::vector<int>::iterator it = vec.begin();
        for (;it !=  vec.end(); it++)
            std::cout << *it << ' ';
		std::cout << '\n';
	};

int main()
{
	ft::vector<int> vec = ft::vector<int>(6, 99);
	std::cout << vec.data() << " = data address\n";
	print_vector(vec);
	std::cout << vec.size() << " = size \n";
	std::cout << vec.capacity() << " = capacity \n";

	// ft::vector<int> vec2 = vec;
	// std::cout << vec2.data() << " = data address\n";
	// print_vector(vec2);
	// std::cout << vec2.size() << " = size \n";
	// std::cout << vec2.capacity() << " = capacity \n";

	std::vector<int> stdvec;

	stdvec.assign(6, 15);

	vec.assign(stdvec.begin(), stdvec.end());
	std::cout << vec.data() << " = data address\n";
	print_vector(vec);
	std::cout << vec.size() << " = size \n";
	std::cout << vec.capacity() << " = capacity \n";

	ft::vector<int> vec2;
	vec2.assign(stdvec.begin(), stdvec.end());
	std::cout << vec2.data() << " = data address\n";
	print_vector(vec2);
	std::cout << vec2.size() << " = size \n";
	std::cout << vec2.capacity() << " = capacity \n";

	if (!std::equal(vec.begin(),vec.end(),vec2.begin()))
		std::cout << "it s not equal \n ";
	std::cout << "it s equal \n ";

	return 0;
}