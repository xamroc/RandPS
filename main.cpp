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

int main(int argc, char *argv[])
{
    //initscr();
    //int argv[3];
    //int argvLen = sizeof(argv)/sizeof(*argv);

    int lowest = atoi(argv[1]);
    int highest = atoi(argv[2]);
    int divisor = atoi(argv[3]);
/*
    for (int i=0; i<argvLen; i++)
    {
        printw("Enter value of argv[%d]: ", i+1);
        int n = getch();
        cout << endl;
        argv[i] = n;
        refresh();

        cout << "Enter value of argv[" << i+1 << "]:" << endl;
        cin >> argv[i];
    }
*/
    int random_number;
    srand((unsigned)time(0));

    do
    {
        random_number = random_number_generator(lowest, highest);
        cout << random_number << endl;
        sleep(1);
    } while(random_number % divisor != 0 );

    //endwin();
    return 0;
}
