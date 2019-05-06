#include <iostream>
#include <time.h>
#include <iomanip>
using namespace std;


long long recursion(int n)
{
	cout << "--";
	if (n == 1)
		return 1;
	else if (n == 2)
		return 1;

	return recursion(n - 1) + recursion(n - 2);
}

long long loop(int n)
{
	long long a=1, b=1, sum;
	for (int i = 0; i < n; i++)
	{
		if (i == 0) sum = a;
		else
		{
			sum = a + b;
			a = b;
			b = sum;
		}
	}
	return sum;
	
}


int main()
{
	long long  result;
	clock_t start, end;
	start = clock();
	result = recursion(10);
	end = clock();
	cout.setf(ios::fixed);
	cout << endl << "Recuion result	is " << result << " " << "spend time: " << setprecision(10) << (float)(end - start) / CLOCKS_PER_SEC << " second " << endl;


	start = clock();
	result = loop(10);
	end = clock();
	cout << "Loop result is " << result << " " << "spend time: " << setprecision(10) << (float)((end - start) / CLOCKS_PER_SEC) << " second " << endl;





	system("pause");
	return 0;
}