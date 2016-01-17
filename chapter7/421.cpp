#include <iostream>
#include <iterator>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
	vector<int> v1 = {3,4,7,8,13};
	vector<int> v2 = { 1, 4, 8,11};

	set_difference(v1.cbegin(), v1.cend(), v2.cbegin(), v2.cend(), ostream_iterator<int>(cout, "\n"));
	getchar();
}
