#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

/* Generate a random number seeded with time value for better randomness */
int random_number_generator(int lowest, int highest)
{
    srand((unsigned)time(0));
    int random_integer;
    int range = highest-lowest;
    random_integer = lowest+(rand()%(range+1));
    cout << random_integer << endl;
}

int main()
{
    int argv[3];
    int argvLen = sizeof(argv)/sizeof(*argv);

    for (int i=0; i<argvLen; i++)
    {
        cout << "Enter value of argv[" << i+1 << "]:" << endl;
        cin >> argv[i];
    }

    int lowest = argv[0];
    int highest = argv[1];
    int divisor = argv[2];

    random_number_generator(lowest, highest);

    return 0;
}
