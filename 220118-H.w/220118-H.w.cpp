#include <iostream>
#include <time.h>
using namespace std;

struct Rectangle
{
    short width;
    short length;
};

void fillArrayRandom(Rectangle* obj, int size, int min, int max)
{
    for (int i = 0; i < size; ++i)
    {
        obj[i].width = rand() % (max - min + 1) + min;
        obj[i].length = rand() % (max - min + 1) + min;
    }
}

int findMaxRectangle(const Rectangle* obj, int size)
{
    int indx = 0;

    for (int i = 1; i < size; ++i)
        if ((obj[i].width * obj[i].length) > (obj[indx].width * obj[indx].length))
            indx = i;

    return indx;
}

void printRectangles(const Rectangle* obj, int size)
{
    cout << endl;
    for (int i = 0; i < size; ++i)
        cout << "Rectangle #" << i + 1 << ":\tLength: " << obj[i].length << "\tWidth: " << obj[i].width  << endl;
}

float getNum(string message, int min = 0, int max = 0)
{
    float num;
    bool err{};
    do
    {
        err = false;
        cout << message;
        cin >> num;

        if (cin.fail())
        {
            cin.clear();
            cin.ignore(32767, '\n');
            err = true;
        }
    } while ((num < min && (min != 0 || max != 0)) || num > max && max != 0 || err == true);

    return num;
}

int main()
{
    srand(time(NULL));
    rand();

    int size;

    /*cout << "Enter a size of array: ";
    cin >> size;*/

    size = getNum("Enter a size of array: ", 1);

    Rectangle* arr = new Rectangle[size];
    fillArrayRandom(arr, size, 3, 20);

    printRectangles(arr, size);

    int indx = findMaxRectangle(arr, size);

    cout << "\nThe most big rectangle ever is...  #" << indx << "\t(" << arr[indx].length << ", " << arr[indx].width << ")\n\n";

    for (int i = 0; i < arr[indx].width; ++i)
    {
        for (int j = 0; j < arr[indx].length; ++j)
        {
            if (i == 0 || i == arr[indx].width - 1 || j == 0 || j == arr[indx].length - 1)
                cout << "* ";
            else
                cout << "  ";
        }
        cout << endl;
    }



    return 0;
}
