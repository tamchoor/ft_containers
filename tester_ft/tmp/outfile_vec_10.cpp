#include <iostream>
#include "test_utils.hpp"
#include <vector>
#include "vector.hpp"
#include "old_vector.hpp"

extern std::string	test_name;
void test_vector_erase_pos(long count){
	//print job name
	test_name = "-VECTOR ERASE POS TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = std::numeric_limits<int>::max();
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
		size_t it_pos = rand() % num;
		std::vector<int>::iterator it = v1.begin() + it_pos;
		ft::vector<int>::iterator its = v2.begin() + it_pos;
		std::vector<int>::iterator res_std = v1.erase(it);
		ft::vector<int>::iterator res_ft = v2.erase(its);
		if (res_std != v1.end() && res_ft != v2.end() && *res_std != *res_ft)
		 	++err_count;
		if (res_std - v1.begin() != res_ft - v2.begin())
			++err_count;
		int std_res = v1.size();
		int ft_res = v2.size();
		if (std_res != ft_res)
			++err_count;
		if (!std::equal(v1.begin(),v1.end(),v2.begin()))
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
	}

	//std working
    std::vector<int> v1(count, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		v1.erase(v1.begin());
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	ft::vector<int> v2(count, M);
	timer_start();
	for (int i = 0; i < count; ++i){
		v2.erase(v2.begin());
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

int main(){
	test_vector_erase_pos(100000);
}