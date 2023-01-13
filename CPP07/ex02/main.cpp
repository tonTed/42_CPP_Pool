#include "Array.hpp"

#define MAX_VAL 750
int main(int, char**)
{

	// int * a = new int();
	// std::cout << a << std::endl;
	// std::cout << *a << std::endl;

	// Array<int> c;
	// std::cout << c._array << std::endl;
	// std::cout << *c._array << std::endl;

	Array<int> b(5);
	std::cout << &b << std::endl;
	std::cout << b._array << std::endl;
	std::cout << *b._array << std::endl;
	b._array[0] = 5;
	b._array[1] = 7;
	std::cout << b._array[0] << std::endl;
	std::cout << b._array[1] << std::endl;
	std::cout << std::endl;

	Array<int> d;
	std::cout << &d << std::endl;
	std::cout << std::endl;

	d = Array<int>(b);
	std::cout << &d << std::endl;
	std::cout << &b << std::endl;
	std::cout << std::endl;

	// std::cout << d._array[0] << std::endl;

	// d._array[0] = 9;
	// std::cout << d._array[0] << std::endl;
	// std::cout << b._array[0] << std::endl;
	
	// std::cout << b->_array << std::endl;

	// Array<int> numbers(MAX_VAL);
	// int* mirror = new int[MAX_VAL];
	// srand(time(NULL));
	// for (int i = 0; i < MAX_VAL; i++)
	// {
	//     const int value = rand();
	//     numbers[i] = value;
	//     mirror[i] = value;
	// }
	// //SCOPE
	// {
	//     Array<int> tmp = numbers;
	//     Array<int> test(tmp);
	// }

	// for (int i = 0; i < MAX_VAL; i++)
	// {
	//     if (mirror[i] != numbers[i])
	//     {
	//         std::cerr << "didn't save the same value!!" << std::endl;
	//         return 1;
	//     }
	// }
	// try
	// {
	//     numbers[-2] = 0;
	// }
	// catch(const std::exception& e)
	// {
	//     std::cerr << e.what() << '\n';
	// }
	// try
	// {
	//     numbers[MAX_VAL] = 0;
	// }
	// catch(const std::exception& e)
	// {
	//     std::cerr << e.what() << '\n';
	// }

	// for (int i = 0; i < MAX_VAL; i++)
	// {
	//     numbers[i] = rand();
	// }
	// delete [] mirror;//
	// return 0;
}