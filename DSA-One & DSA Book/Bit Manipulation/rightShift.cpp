#include <iostream>
using namespace std;
#include <chrono>
using namespace std ::chrono;
int main()
{
    auto startTime = high_resolution_clock::now();
    int a = 10000000000000000;
    while (a > 0)
    {
        // printf("%d\n", a);
        // a = a >> 1;
        a = a / 2;
    }
    auto stopTime = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stopTime - startTime);
    float finalDur = duration.count();
    float sec = finalDur / 1000000;
    cout << "Time taken :" << sec << " microsec" << endl;
}