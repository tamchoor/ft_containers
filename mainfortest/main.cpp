#include "vector.hpp"
#include <vector>
#include <iostream>

std::clock_t    start;
double          duration;


double timer_stop(){
    duration = ( std::clock() - start ) / (double) CLOCKS_PER_SEC;
	start = 0;
	return duration;
}

void timer_start(){
	start = std::clock();
}

template <class Type>
void print_vector(ft::vector<Type> &vec)
{
	typename ft::vector<Type>::iterator it = vec.begin();
	for (;it !=  vec.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
	std::cout << vec.size() << " = size \n";
	std::cout << vec.capacity() << " = capacity \n";
};

template <class Type>
void print_vector(std::vector<Type> &vec)
{
	typename std::vector<Type>::iterator it = vec.begin();
	for (;it !=  vec.end(); it++)
		std::cout << *it << ' ';
	std::cout << '\n';
	std::cout << vec.size() << " = size \n";
	std::cout << vec.capacity() << " = capacity \n";
};

		void print_vector(ft::vector<std::string> &vec)
	{
		ft::vector<std::string>::iterator it = vec.begin();
        for (;it !=  vec.end(); it++)
            std::cout << *it << ' ';
		std::cout << '\n';
		std::cout << vec.size() << " = size \n";
		std::cout << vec.capacity() << " = capacity \n";
	};



void test_vector_erase_iter(long count)
{
	//print job name
	std::string test_name = "-VECTOR ERASE ITER TEST-\n";
	// print_test_name(count);
	std::cout << test_name ;

	//init
    const size_t N = 10;
    const int M = 100;
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		size_t num = rand() % N;
		std::vector<int> v1;
		ft::vector<int> v2;
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v2.push_back(fill);
		}
		if (!num) continue;
		print_vector(v1);
		print_vector(v2);
		size_t it_pos = rand() % num;
		std::vector<int>::iterator it = v1.begin() + it_pos;
		ft::vector<int>::iterator its = v2.begin() + it_pos;
		std::vector<int>::iterator res_std = v1.erase(v1.begin(), it);
		ft::vector<int>::iterator res_ft = v2.erase(v2.begin(), its);
		if (res_std != v1.end() && res_ft != v2.end() && *res_std != *res_ft)
		 	++err_count;
		if (res_std - v1.begin() != res_ft - v2.begin())
			++err_count;
		std::cout << res_std - v1.begin() << "== res_std - v1.begin()  \n";
		std::cout << res_ft - v2.begin() << "== res_ft - v2.begin()  \n";
		std::cout << *res_std  << "== res_std   \n";
		std::cout << *res_ft  << "== res_ft  \n";
		std::cout << err_count << "== err  \n";
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
		std::cout << err_count << "== err  \n";
		if (!std::equal(v1.begin(),v1.end(),v2.begin()))
			++err_count;
		std::cout << err_count << "== err  \n";
		
		if (err_count > 0)
		{
			std::cout << "its NOT ok!!!\n";
			print_vector(v1);
			print_vector(v2);
			return;
		}
		if (i > count -2)
		{
			std::cout << "its ok!!!\n";
			print_vector(v1);
			print_vector(v2);
		}
	}
}
}


void test_vector_reverse_iter(long count){
	//print job name
	std::string test_name = "-VECTOR REVERSE ITER TEST-";
	std::cout << test_name ;

	//init
    const size_t N = 12;
    const int M = 20;
	srand(time(NULL));
	{
	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		size_t num = rand() % N;
		if (!num) continue;
		std::vector<int> v1;
		ft::vector<int> v2;
		for (size_t i = 0; i < num; ++i){
			int fill = rand() % M;
			v1.push_back(fill);
			v2.push_back(fill);
		}
		print_vector(v1);
		print_vector(v2);
		std::vector<int>::reverse_iterator it_rb = v1.rbegin();
		std::vector<int>::reverse_iterator it_re = v1.rend();
		ft::vector<int>::reverse_iterator its_rb = v2.rbegin();
		ft::vector<int>::reverse_iterator its_re = v2.rend();

		std::cout << *it_rb << "== it_rb  \n";
		std::cout << *it_re << "== it_re  \n";
		std::cout << *its_rb << "== its_rb   \n";
		std::cout << *its_re  << "== its_re  \n";

		std::cout << it_rb - it_re<< "== it_rb - it_re  \n";
		std::cout << its_rb - its_re << "== its_rb - its_re  \n";
		std::cout << its_re - its_rb  << "== its_re - its_rb   \n";

		if (*it_rb != *its_rb)
			++err_count;
		if (it_rb - it_re != its_rb - its_re)
			++err_count;
		if (!ft::equal(it_rb, it_re, its_rb))
			++err_count;

		if (err_count > 0)
		{
			std::cout << "its NOT ok!!!\n";
			// print_vector(v1);
			// print_vector(v2);
			return;
		}
		if (i > count -2)
		{
			std::cout << "its ok!!!\n";
			print_vector(v1);
			print_vector(v2);
		}
	}
	double comp_res = timer_stop();
	}
}

// template <typename T>
// std::vector<int> insert_test_1(ft::vector<T> vector) {
//     std::vector<int> v;
//     vector.assign(2600 * _ratio, 1);
//     g_start2 = timer();
//     v.push_back(*(vector.insert(vector.end() - 800 * _ratio, 44)));
//     g_end2 = timer();
//     v.push_back(vector.size());
//     v.push_back(vector.capacity());

//     return v;
// }




int main()
{
	// ft::vector<int> v1;
	// v1.assign(3, 4);
	// ft::reverse_iterator<ft::iterator<int> > it = v1.rbegin() + 1;
	// int i = *(it);
	// v1.push_back(i);
	// print_vector(v1);

	// std::vector<int> v2;
	// v2.assign(3, 4);
	// v2.push_back(*(v2.rbegin() + 2));
	// print_vector(v2);

	ft::vector<float> v1;
	std::vector<float> v2;

	v1.assign(3, 4.0f);
	print_vector(v1);

	v2.assign(3, 5.0f);
	print_vector(v2);

	v2.insert(v2.begin(), 2.0f, 6.0f);
	print_vector(v2);

	v1.insert(v1.begin(), 2.0f, 6.0f);
	print_vector(v1);
	

	// test_vector_erase_iter(1);
	// test_vector_reverse_iter(1);
	return 0;
}