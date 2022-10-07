#include <iostream>
#include "test_utils.hpp"
#include <vector>
#include "vector.hpp"
#include "old_vector.hpp"

extern std::string	test_name;
void test_vector_two_param_ctor(long count){
	//print job name
	test_name = "-VECTOR TWO PARAM CONSTRUCTION TEST-";
	print_test_name(count);

	//init
    const size_t N = 42;
    const int M = 99;
	std::vector<int> v1(N, M);
	ft::vector<int> v2(N, M);

	//output test
	timer_start();
	long err_count = 0;
	for (int i = 0; i < count; ++i){
		int std_res = *(v1.begin() + i % N);
		int ft_res = *(v2.begin() + i % N);
		if (std_res != ft_res)
			++err_count;
	}
	double comp_res = timer_stop();
    print_comp_res(err_count, comp_res);
    
	//std working
	timer_start();
	for (int i = 0; i < count; ++i){
        std::vector<int> v1(N, M);
	}
	double std_res = timer_stop();
	std::cout << "std result: " << std_res << " sec | " << std::flush;
	
	//ft working 
	timer_start();
	for (int i = 0; i < count; ++i){
        ft::vector<int> v2(N, M);
	}
	double ft_res = timer_stop();
	std::cout << "ft result: " << ft_res << " sec | " << std::flush;
	print_result(std_res, ft_res);
}

int main(){
	test_vector_two_param_ctor(100000);
}