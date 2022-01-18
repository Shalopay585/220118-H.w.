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

int main()
{
    srand(time(NULL));
    rand();

    cout << "Enter a size of array: ";
    int size;
    cin >> size;

    Rectangle* arr = new Rectangle[size];
    fillArrayRandom(arr, size, 3, 15);

    printRectangles(arr, size);

    int indx = findMaxRectangle(arr, size);

    cout << "\nThe most big rectangle ever...\t(" << arr[indx].length << ", " << arr[indx].width << ")\n\n";

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
