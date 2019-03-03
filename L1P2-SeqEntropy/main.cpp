#include <iostream>
#include <chrono>

using namespace std;

int nr_of_ones(int num)
{
    int count = 0;

    while (num != 0)
    {
        if ((num & 1) == 1)
        {
            count++;
        }
        num = num >> 1;
    }

    return count;
}

int main(int argc, char* argv[])
{
    long nr_bytes;
    double nr_T, nr_Z;
    double nr_O = 0.0;
    double nr_E;
    char* byte_seq;
    unsigned int lookup_table[256];
    int i;
    chrono::high_resolution_clock::time_point t1, t2;
    srand(time(NULL));

    if (argc != 2)
    {
        cout << "Usage: program.exe N" << endl << "Where N is the number of bytes in the sequence" << endl;
    }

    nr_bytes = atol(argv[1]);

    if (nr_bytes < 0)
    {
        cout << "Please input a positive number!" << endl;
    }

    byte_seq = (char*)malloc(nr_bytes * sizeof(char));

    for (i = 0; i < nr_bytes; i++)
    {
        byte_seq[i] = rand();
    }

    t1 = chrono::high_resolution_clock::now();

    for (i = 0; i < 256; i++)
    {
        lookup_table[i] = nr_of_ones(i);
    }

    for (i = 0; i < nr_bytes; i++)
    {
        nr_O += lookup_table[(unsigned char)byte_seq[i]];
    }
    nr_T = nr_bytes * 8;
    nr_Z = nr_T - nr_O;

    nr_E = -(nr_O / nr_T)*log2(nr_O / nr_T) - (nr_Z / nr_T)*log2(nr_Z / nr_T);

    t2 = chrono::high_resolution_clock::now();
    chrono::duration<double> time_span = chrono::duration_cast<chrono::duration<double>>(t2 - t1);

    printf("Entropy: %.20lf\n", nr_E);
    cout << "Total time: " << time_span.count() << " seconds." << endl;

    return 0;
}