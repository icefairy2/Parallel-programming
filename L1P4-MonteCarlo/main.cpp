#include <iostream>
#include <chrono>

using namespace std;

int main(int argc, char* argv[])
{
    long n, m = 0;
    double pi = 0.0;
    int i;
    double* points_x;
    double* points_y;
    chrono::high_resolution_clock::time_point t1, t2;
    srand(time(NULL));

    if (argc != 2)
    {
        cout << "Usage: program.exe N" << endl << "Where N is the number of random points to be generated" << endl;
    }

    n = atol(argv[1]);

    if (n < 0)
    {
        cout << "Please input a positive number!" << endl;
    }

    points_x = (double*)malloc(n * sizeof(double));
    points_y = (double*)malloc(n * sizeof(double));

    t1 = chrono::high_resolution_clock::now();

    for (i = 0; i < n; i++)
    {
        points_x[i] = (double)rand() / (double)RAND_MAX;
        points_y[i] = (double)rand() / (double)RAND_MAX;

        if (sqrt(pow(points_x[i], 2) + pow(points_y[i], 2)) <= 1)
        {
            m++;
        }
    }

    pi = 4 * (double)m / (double)n;

    t2 = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

    printf("Value of PI: %.20lf\n", pi);
    cout << "Total time: " << time_span.count() << " seconds." << endl;

    return 0;
}