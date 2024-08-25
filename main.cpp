// this is the windows version i hate not simple apis so i will make a linux version one day for unix systems
// to change the scree resolution just you can cha,ge the variable number_of_pixels
// the x is the resolution in x
// and the y is just the number of frames 
// pay attention and match the number of y to the number of pixels
#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

const int x = 10;
const int y = 20;
const int sleep_time = 300;
const int number_of_pixels = 2;
string get_version() {
#ifdef _WIN32
    return "windows";
#else
    return "unix";
#endif   
}

void clear_terminal() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif   
}

void animation(string matrix[y][x]) {
    int i = 0;
    int a = 0;
    int b = 0;
    
    string os = get_version();

    while (i < y) {
        a = 0;
        while (a < x) {
            cout << matrix[i][a];
            a = a + 1;
        }
        cout << "\n";
        i = i + 1;

        if (i % number_of_pixels == 0) {
            if (os == "windows") {
                Sleep(sleep_time);
            }
            else {
                cout << "Your system isn't supported. It will be added later.";
            }
            clear_terminal();
        }
    }
}

int main() {
    string matrix_animation[20][10] = {
        {"*........."},
        {"**........"},
        {"***......."},
        {"****......"},
        {"*****....."},
        {"******...."},
        {"*******..."},
        {"********.."},
        {"*********. "},
        {"**********"},
        {"**********"},
        {"*********."},
        {"********.."},
        {"*******..."},
        {"******...."},
        {"*****....."},
        {"****......"},
        {"***......."},
        {"**........"},
        {"*........."}
    };

    animation(matrix_animation);

    return 0;
}
