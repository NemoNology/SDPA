#include <iostream>
#include <vector>

using namespace std;

using uint = unsigned int;

int main()
{
    int N;
    uint maxN = 31;
    vector<uint> nums(maxN);

    // Подсчитаем кол-во возможных путей к низу..
    // ..самостоятельно для первоначальных значений
    // nums[0] = Как добраться с низа до низа? - Единственным способом - ничего не сделать.
    nums[0] = 1;
    nums[1] = 1;
    nums[2] = 2;


    for (int i = 3; i < maxN; i++)
    {
        nums[i] = nums[i - 1] + nums[i - 2] + nums[i - 3];
    }

    cout << "Input n: ";
    cin >> N;

    while ((N <= 0) || (N >= 31))
    {
        cout << "Incorrect input: 0 < n < 31!\n";

        cout << "Input n: ";
        cin >> N;
    }

    cout << "Number of ways: " << nums[N] << endl;

    system("pause");
    return 0;
}