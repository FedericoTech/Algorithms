#include<cstdio>

void countdown(int x)
{
	if(x == 0){
		printf("Done!\n");
		return;
	} else {
		printf("%d...\n", x);
		countdown(x - 1);
		printf("foo %d\n", x);
	}
}

//Using recursion to implement power and factorial functions

// 2^4 = 2 x 2 x 2 x 4
int power(const int &num, const int &pwr)
{
	if(pwr == 0) {
		return 1;
	} else {
		return num * power(num, pwr - 1); // --pwr wouldn't work because pwr is constant
	}
}

template<unsigned int N, unsigned int O>
struct power_t {
	static constexpr unsigned int value = N * power_t<N, O - 1>::value;
};

template<unsigned int N>
struct power_t<N, 0> {
	static constexpr unsigned int value = 1;
};


// 5! = 5 x 4 x 3 x 2 x 1 = 120;
// 0! = 1;
int factorial(const int &num)
{
	if(num == 0){
		return 1;
	} else {
		return num * factorial(num - 1);
	}
}

template<unsigned int N>
struct factorial_t {
	static constexpr unsigned int value = N * factorial_t<N - 1>::value;
};

template<>
struct factorial_t<0> {
	static constexpr unsigned int value = 1;
};

int main()
{
	//countdown(5);

	printf("\npower function\n");

	printf("%d to the power of %d is %d\n", 5, 3, power(5, 3));
	printf("%d to the power of %d is %d\n", 1, 5, power(1, 5));

	printf("\npower template\n");

	printf("%d to the power of %d is %d\n", 5, 3, power_t<5, 3>::value);
	printf("%d to the power of %d is %d\n", 1, 5, power_t<1, 5>::value);

	printf("\nfactorial function\n");

	printf("%d! is %d\n", 4, factorial(4));
	printf("%d! is %d\n", 0, factorial(0));

	printf("\nfactorial template\n");

	printf("%d! is %u\n", 4, factorial_t<4>::value);
	printf("%d! is %u\n", 0, factorial_t<0>::value);



	return 0;
}
