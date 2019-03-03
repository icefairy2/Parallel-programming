#include <iostream>
#include <chrono>

using namespace std;

int main(int argc, char* argv[])
{
    int lower_bound, upper_bound;
    int* prime_array;
    int i, j;
    int n = 0;
    bool is_prime = true;
    chrono::high_resolution_clock::time_point t1, t2;

    if (argc != 3)
    {
        cout << "Usage: program.exe A B" << endl << "Where A and B are the bounds of the interval" << endl;
    }

    lower_bound = atoi(argv[1]);
    upper_bound = atoi(argv[2]);

    if (lower_bound < 0 || upper_bound < 0)
    {
        cout << "Please input positive bounds!" << endl;
    }

    if (lower_bound > upper_bound)
    {
        cout << "Interval bounds are invalid, please input lower first!" << endl;
    }

    prime_array = (int*)malloc((upper_bound - lower_bound) * sizeof(int));

    t1 = chrono::high_resolution_clock::now();

    //Optimizations
    if (lower_bound == 2)
    {
        prime_array[n++] = 2;
    }
    if (lower_bound % 2 == 0)
    {
        lower_bound++;
    }

    for (i = lower_bound; i <= upper_bound; i += 2)
    {
        is_prime = true;
        for (j = 3; j <= floor(sqrt(i)); j += 2)
        {
            if (i%j == 0)
            {
                is_prime = false;
            }
        }
        if (is_prime)
        {
            prime_array[n++] = i;
        }
    }

    t2 = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

    cout << " Primes: ";
    for (i = 0; i < n; i++)
    {
        cout << prime_array[i] << " ";
    }

    cout << endl << "Total time: " << time_span.count() << " seconds." << endl;

    return 0;
}