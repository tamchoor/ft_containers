#include "vector.hpp"
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

	ft::vector<int> vec2 = vec;
	std::cout << vec2.data() << " = data address\n";
	print_vector(vec2);
	std::cout << vec2.size() << " = size \n";
	std::cout << vec2.capacity() << " = capacity \n";



	// vec[0] = 5;
	// vec[1] = 7;
	// std::cout << vec[0] << "\n";
	// std::cout << vec[1] << "\n";

	// std::cout << vec.size() << " = size \n";
	// std::cout << vec.capacity() << " = capacity \n";
	// vec.clear();
	// std::cout << vec.data() << " = data address\n";
	// std::cout << vec[0] << "\n";
	// std::cout << vec[1] << "\n";
	// std::cout << vec.size() << " = size \n";
	// std::cout << vec.capacity() << " = capacity \n";
	// vec.push_back(55);
	// vec.push_back(66);

	// vec.reserve(100);
	// std::cout << vec.data() << " = data address\n";
	// std::cout << vec[0] << "\n";
	// std::cout << vec[1] << "\n";
	// std::cout << vec.size() << " = size \n";
	// std::cout << vec.capacity() << " = capacity \n";

	// vec.pop_back();
	// vec.pop_back();
	// 	std::cout << vec[0] << "\n";
	// std::cout << vec[1] << "\n";
	
	// try
	// {
	// 	vec.pop_back();
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }

	// vec.push_back(5);
	// // vec.push_back(6);
	// // vec.push_back(7);
	// std::cout << vec.data() << " = data address\n";
	// std::cout << vec.size() << " = size \n";
	// std::cout << vec.capacity() << " = capacity \n";

	// ft::vector<int> vec1;
	// vec1.push_back(1);
	// vec1.push_back(2);
	// vec1.push_back(3);
	// std::cout << vec1.data() << " = data address\n";
	// std::cout << vec1.size() << " = size \n";
	// std::cout << vec1.capacity() << " = capacity \n";

	// vec = vec1;

	// std::cout << vec.data() << " = data address\n";
	// std::cout << *vec.data() << " = data\n";
	// std::cout << vec.size() << " = size \n";
	// std::cout << vec.capacity() << " = capacity \n";

	// std::cout << vec.data() << " = data address\n";
	// std::cout << vec.size() << " = size \n";
	// std::cout << vec.capacity() << " = capacity \n";

	// std::cout << vec.front() << " = data address\n";


	return 0;
}