#include <iostream>
#include <chrono>

using namespace std;

int main(int argc, char* argv[])
{
    long n;
    double pi = 0.0;
    int i;
    chrono::high_resolution_clock::time_point t1, t2;

    if (argc != 2)
    {
        cout << "Usage: program.exe N" << endl << "Where N is the number of bytes in the sequence" << endl;
    }

    n = atol(argv[1]);

    if (n < 0)
    {
        cout << "Please input a positive number!" << endl;
    }

    t1 = chrono::high_resolution_clock::now();

    for (i = 0; i < n; i++)
    {
        pi += 4.0 / (1.0 + pow((i + 0.5) / (double)n, 2));
    }
    pi *= 1.0 / (double)n;

    t2 = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

    printf("Value of PI: %.20lf\n", pi);
    cout << "Total time: " << time_span.count() << " seconds." << endl;

    return 0;
}