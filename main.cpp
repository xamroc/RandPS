#include <iostream>

using namespace std;

int main()
{
    int argv[3];
    int argvLen = sizeof(argv)/sizeof(*argv);

    for (int i=0; i<argvLen; i++)
    {
        cout << "Enter value of argv[" << i+1 << "]:" << endl;
        cin >> argv[i];
    }

    return 0;
}
