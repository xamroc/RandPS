#include <ncurses.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <unistd.h>

using namespace std;

/* Return a random number based on time seed for better randomness */
int random_number_generator(int lowest, int highest)
{
    int range = highest-lowest;
    int random_integer = lowest+(rand()%(range+1));
    return random_integer;
}

int main()
{
    int argv[3];
    int argvLen = sizeof(argv)/sizeof(*argv);

    refresh();

    for (int i=0; i<argvLen; i++)
    {
        cout << "Enter value of argv[" << i+1 << "]:" << endl;
        cin >> argv[i];
    }

    int lowest = argv[0];
    int highest = argv[1];
    int divisor = argv[2];

    int random_number;
    srand((unsigned)time(0));

    do
    {
        random_number = random_number_generator(lowest, highest);
        cout << random_number << endl;
        sleep(1);
    } while(random_number % divisor != 0 );

    return 0;
}
