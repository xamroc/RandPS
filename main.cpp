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
    initscr();

    int lowest = atoi(argv[1]);
    int highest = atoi(argv[2]);
    int divisor = atoi(argv[3]);

    int random_number;
    srand((unsigned)time(0));

    int c;
    do
    {
        random_number = random_number_generator(lowest, highest);
        printw("rand = %d", random_number);
        //cout << random_number << endl;
        refresh();
        sleep(1);
    } while((c=getch())!=49 || random_number % divisor != 0);
    endwin();
    return 0;
}
