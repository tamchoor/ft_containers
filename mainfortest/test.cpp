#include <vector>
#include <iostream>

	void print_vector(std::vector<int> &vec)
	{
		std::vector<int>::iterator it = vec.begin();
        for (;it !=  vec.end(); it++)
            std::cout << *it << ' ';
		std::cout << '\n';
	};

int main()
{

	// std::cout << "Test empty vector\n";
	// std::vector<int> vec;
	// std::cout << vec.data() << " = data address\n";
	// std::cout << vec.size() << " = size \n";
	// std::cout << vec.capacity() << " = capacity \n";

	// std::cout << "\nTest vector with one elem\n";
	// vec.push_back(5);
	// std::cout << vec.data() << " = data address\n";
	// std::cout << *vec.data() << " = data\n";
	// std::cout << vec.size() << " = size \n";
	// std::cout << vec.capacity() << " = capacity \n";

	// std::cout << "\nTest vector with two elems\n";
	// vec.push_back(6);
	// std::cout << vec.data() << " = data address\n";
	// std::cout << *vec.data() << " = data1\n";

	// int * ptr = vec.data();
	// *ptr = 1;
	// std::cout << vec.data() << " = data address\n";
	// std::cout << *vec.data() << " = data1\n";
	
	// std::cout << vec.data() + 1 << " = data2 address\n";
	// std::cout << *(vec.data() + 1) << " = data2\n";
	// std::cout << vec.size() << " = size \n";
	// std::cout << vec.capacity() << " = capacity \n";


	// vec.push_back(5);
	// vec.push_back(5);
	// vec.push_back(5);
	// vec.push_back(5);
	// vec.push_back(5);
	// std::cout << vec.data() << " = data address\n";
	// std::cout << vec.size() << " = size \n";
	// std::cout << vec.capacity() << " = capacity \n";

	// vec.reserve(3);
	// std::cout << vec.data() << " = data address\n";
	// std::cout << vec.size() << " = size \n";
	// std::cout << vec.capacity() << " = capacity \n";

	// std::cout << "\nTest new vector \n";

	// std::vector<int> vec1;

	// vec1.reserve(7);
	// std::cout << vec1.data() << " = data address\n";
	// std::cout << vec1.size() << " = size \n";
	// std::cout << vec1.capacity() << " = capacity \n";

	std::cout << "\nTest vector with one elem\n";

	std::vector<int> vec = std::vector<int>(6, 99);;
	std::cout << vec.data() << " = data address\n";
	print_vector(vec);
	std::cout << vec.size() << " = size \n";
	std::cout << vec.capacity() << " = capacity \n";

	std::vector<int> vec2 = vec;
	std::cout << vec2.data() << " = data address\n";
	print_vector(vec2);
	std::cout << vec2.size() << " = size \n";
	std::cout << vec2.capacity() << " = capacity \n";

	if (!std::equal(vec.begin(),vec.end(),vec2.begin()))
		std::cout << "it s not equal \n ";
	std::cout << "it s equal \n";

	// vec.assign(3, 6);
	// print_vector(vec);
	// std::cout << vec.size() << " = size \n";
	// std::cout << vec.capacity() << " = capacity \n";

	// vec.assign(13, 16);
	// print_vector(vec);
	// std::cout << vec.size() << " = size \n";
	// std::cout << vec.capacity() << " = capacity \n";

	// vec.assign(3, 1);
	// print_vector(vec);
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
	// 	vec.at(16);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << "--\n";
	// }
	

	// vec.shrink_to_fit();
	// std::cout << vec.capacity() << " = capacity \n";
	// std::cout << *vec.begin() << " = begin \n";
	// std::cout << vec[0] << " = [0]\n"; 
	// std::cout << vec[2] << " = [2]\n"; 
	// std::cout << vec[3] << " = [3]\n"; 
	// vec.clear();
	// std::cout << vec.data() << " = data address\n";
	// std::cout << vec.size() << " = size \n";
	// std::cout << vec.capacity() << " = capacity \n";
	// std::cout << *vec.begin() << " = begin \n";
	// std::cout << vec[0] << " = [0]\n"; 
	// std::cout << vec[2] << " = [2]\n"; 
	// std::cout << vec[3] << " = [3]\n"; 
	// vec.push_back(5);

	// try
	// {
	// 	std::cout << vec.front() << " = data address\n";
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << '\n';
	// }
	
	

	// std::cout << vec.empty() << " = vec.empty\n";
	// 
	// std::cout << vec.empty() << " = vec.empty\n";
	// vec.push_back(6);
	// vec.push_back(7);
	// // vec.resize(1000);
	// std::cout << vec.data() << " = data address\n";
	// std::cout << vec.size() << " = size \n";
	// std::cout << vec.capacity() << " = capacity \n";
	// std::cout << vec[0] << " = [0]\n"; 
	// std::cout << vec[2] << " = [2]\n"; 
	// std::cout << vec[3] << " = [3]\n"; 
	// std::cout << vec[4] << " = [4]\n"; 
	// std::cout << vec[5] << " = [5]\n"; 
	// try
	// {
	// 	std::cout << vec.at(0) << " = at[0]\n"; 
	// 	std::cout << vec.at(5) << " = at[5]\n"; 
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr <<" ex =" << e.what() << '\n';
	// }
	

	// vec.clear();
	// std::cout << vec.data() << " = data address\n";
	// std::cout << *vec.data() << " = data\n";
	// std::cout << (vec.begin() == vec.end()) << " =vec.end();\n";
	// std::cout << vec.size() << " = size \n";
	// std::cout << vec.capacity() << " = capacity \n";

	// std::vector<int> vec1;
	// vec1.push_back(1);
	// vec1.push_back(2);
	// vec1.push_back(3);
	// vec1.push_back(1);
	// vec1.push_back(2);
	// vec1.push_back(3);
	// // vec1.resize(1000);
	// std::cout << vec1.data() << " = data address\n";
	// std::cout << vec1.size() << " = size \n";
	// std::cout << vec1.capacity() << " = capacity \n";

	// vec = vec1;

	// std::cout << vec.data() << " = data address\n";
	//  std::cout << *vec.data() << " = data\n";
	// std::cout << vec.size() << " = size \n";
	// std::cout << vec.capacity() << " = capacity \n";


	return 0;
}