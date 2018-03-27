#include <iostream>                                 //Simple IO
#include <fstream>                                  //File Read And Write
#include <sstream>                                  //Stream to integer

using namespace std;

long candy_sampler(int n, int s, int l) {
    long a = s * s + l, b = s, c;                     //Holds n-1 and n-2 respectively, temp is

    //Base Cases:
    if (n == 0) { return 0; }                       //Base Case for 0 == 0
    if (n == 1) { return s; }                       //Base Case for 1 == 1
    if (n == 2) { return s * s + l; }               //Base Case for 2 == s^2 + l

    //Iterative DP
    for (int i = 3; i <= n; ++i) {
        c = s * a + l * b;                          //c  = recurence
        b = a;                                      //Old n-1 = New n-1
        a = c;                                      //Old n = New n

    }
    return a;
}

int main() {
    ifstream file("input.txt");                     //Reads from input file
    ofstream ofile("output.txt");                   //Output File
    string line;                                    //Line of the file
    int n, s, l, i = -1;                            //Indicates the number of problem instances
    while (getline(file, line)) {                   //Get Each Line
        stringstream stream(line);                  //Read input file as stream
        ++i;                                        //Iteration count
        if (i == 0)                                 //Discard First Line of File
            continue;
        stream >> n >> s >> l;                      //Store in variables n, s, and l
        ofile << candy_sampler(n, s, l) << endl;    //Call the candy sampler function
    }
    return 0;
}