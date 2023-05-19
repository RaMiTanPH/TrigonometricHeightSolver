#include <iostream> // The usage of some variable types, inputs and outputs and basically the brain of our program.
#include <iomanip> // Used to manipulate values for me to use setprecision[] to get a specific decimal places
#include <cmath> // Used for mathematical reasons.
#include <string> // Used to support getting the values properly using the syntaxes in <string>
#include <sstream> // Used to manipulate data strings that will convert them into number data types(int, float, double).
#include <algorithm> // Used to sort, search, modify elements in a container(arrays or lists) for more efficiency.
#include "trigoExtras.h" //Custom Header file used to find the height of an object.

using namespace std;

void solving(double personHeight, double degrees, double val1, char DepOrElev, double result, bool deb1, bool deb3, bool reaLL);

int main(double degrees, double val1, double result, char DepOrElev, bool activator, bool reaLL, double personHeight) //Parameters for the needed Values
{
    //VARIABLES//

    string object, unit;
    string input1, input2, input3, input4, input5;
    char YrN;
    char YrN2;
    bool fek = true;
    bool rel = true;
    bool deb1 = true;
    bool deb2 = true;
    bool deb3 = false;
    bool deb4 = false;
    bool deb5 = false;
    bool deb6 = true;

    if (activator == true) {
        while(fek == true) {
        cout << "\nWhat building or thing are you measuring? ";
            getline(cin, object);
        if (object.empty()) {
            cout << "You Inputted Empty Input, Please Input the building or thing that you will be measuring.\n";
            fek == true;
            }
            break;
        }

        while(fek == true) {
        cout << "\nWhat is the unit of measurement will you use? ";
            getline(cin, unit);
        if (unit.empty()) {
            cout << "You Inputted Empty Input, Please Input the unit of measurement you will be using.\n";
            fek == true;
            }
            break;
        }

        if (DepOrElev == 'e' || 'E') {
                if (reaLL == false) { // person is present then add it to the height

                    result = personHeight + result;
                }
            result = round(result * 100.0) / 100.0; // rounding of the the nearest hundredths
            cout << "\nThe Height of the " << object << " is approximately " << fixed << setprecision(2) << result << " " << unit << " In Angle of Elevation." << endl;
            cout << "\n\n[Input Y if Yes or Input N if No]"; // iteration question
            cout << "\nDo you still wanna continue? ";
            cin >> YrN2;
            while(deb6) {
                if (YrN2 == 'y' || 'Y') {
                    rel = true;
                    deb6 = false;
                } else if (YrN2 == 'n' || 'N') {
                    rel = false;
                    deb6 = false;
                } else
                    deb6 = true;
            }
        } else if (DepOrElev == 'd' || 'D') {
            result = round(result * 100.0) / 100.0;
            cout << "\nThe Base of the " <<  object << " is approximately " << fixed << setprecision(2) << result << " " << unit << " In Angle of Depression." << endl;
            cout << "\n\n[Input Y if Yes or Input N if No]"; // iteration question
            cout << "\nDo you still wanna continue? ";
            cin >> YrN2;
            while(deb6) {
                if (YrN2 == 'y' || 'Y') {
                    rel = true;
                    deb6 = false;
                } else if (YrN2 == 'n' || 'N') {
                    rel = false;
                    deb6 = false;
                } else
                    deb6 = true;
            }
        }
        return 0;
    }

// WHERE IT ALL STARTS
    cout << "Trigonometric Height Solver by R.Tan" << endl; //Credits to Ralph Michael S. Tan
    cout << "QUESTION I : PROBLEM ANALYZER" << endl;

while(rel) {
    while (deb1) {
        cout << "\n[Input E if Elevation or Input D if Depression]";
        cout << "\nIs This an Angle of Elevation or Depression? ";
        getline(cin, input1);

    if (input1.length() == 1) {
        DepOrElev = input1[0];
        if (DepOrElev == 'e' || DepOrElev == 'E') {
            deb1 = false;
        } else if (DepOrElev == 'd' || DepOrElev == 'D') {
            deb1 = false;
        }
    }

    if (input1.length() != 1 || (DepOrElev != 'e' && DepOrElev != 'E' && DepOrElev != 'd' && DepOrElev != 'D')) {
        cout << "\nYou Entered the Wrong Conditions.";
        deb1 = true;
    }
}

    if (deb1 = false || DepOrElev == 'e' || DepOrElev == 'E') {
        while(deb2) {
        cout << "\n[Input Y if Yes or Input N if No]";
        cout << "\nIs there a person standing while measuring the object using clinometer? ";
            getline(cin, input2);
    if (input2.length() == 1) {
        YrN = input2[0];
            if(YrN == 'y' || YrN == 'Y' || YrN == 'n' || YrN == 'N') {
            deb2 = false;
        }
    } else {

        cout << "\nYou Entered the Wrong Conditions.";
        deb1 = true;
            }
        }
    }

if (deb2 == false && YrN == 'y' || YrN == 'Y') {
   do {
    if (YrN == 'y' || 'Y' && input2.length() == 1) {
    cout << "\nEnter the person's height(Eye Level): ";
    getline(cin, input3); // read in whole line of input as string

    // remove whitespace from beginning and end of string
    input3.erase(input3.begin(), find_if(input3.begin(), input3.end(), [](unsigned char ch) {
        return !isspace(ch);
    }));
    input3.erase(find_if(input3.rbegin(), input3.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(), input3.end());

    // check if input consists only of whitespace
    if (input3.empty()) {
        cout << "Input is blank or consists only of whitespace." << endl;
    }
    // if input is not blank or whitespace, convert to int
    else {
        stringstream ss(input3);
        if (ss >> personHeight) {
            cout << "Input is valid: " << personHeight << endl;
            deb3 = false;
            reaLL = false;
            break;
        }
        else {
            cout << "Invalid input." << endl;
            }
        }
    }
   } while (!deb3);
}
    do {
    cout << "\nEnter the distance/base between the object/building and the person/pointAngle using clinometer: ";
    getline(cin, input4); // read in whole line of input as string

    // remove whitespace from beginning and end of string
    input4.erase(input4.begin(), find_if(input4.begin(), input4.end(), [](unsigned char ch) {
        return !isspace(ch);
    }));
    input4.erase(find_if(input4.rbegin(), input4.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(), input4.end());

    // check if input consists only of whitespace
    if (input4.empty()) {
        cout << "Input is blank or consists only of whitespace." << endl;
    }
    // if input is not blank or whitespace, convert to int
    else {
        stringstream ss(input4);
        if (ss >> val1) {
            cout << "Input is valid: " << val1 << endl;
            deb4 = false;
            break;
        }
        else {
            cout << "Invalid input." << endl;
        }
    }
   } while (!deb4);

    do {
    cout << "\nEnter the measured/given degrees according to the degree of view to the top object: ";
    getline(cin, input5); // read in whole line of input as string

    // remove whitespace from beginning and end of string
    input5.erase(input5.begin(), find_if(input5.begin(), input5.end(), [](unsigned char ch) {
        return !isspace(ch);
    }));
    input4.erase(find_if(input5.rbegin(), input5.rend(), [](unsigned char ch) {
        return !isspace(ch);
    }).base(), input5.end());

    // check if input consists only of whitespace
    if (input5.empty()) {
        cout << "Input is blank or consists only of whitespace." << endl;
    }
    // if input is not blank or whitespace, convert to int
    else {
        stringstream ss(input5);
        if (ss >> degrees) {
            cout << "Input is valid: " << degrees << endl;
            deb5 = false;
            break;
        }
        else {
            cout << "Invalid input." << endl;
        }
    }
   } while (!deb5);

   solving(personHeight, degrees, val1, DepOrElev, result, deb1, deb3, reaLL); // solving using the given values
}


return 0;
}

void solving(double personHeight, double degrees, double val1, char DepOrElev, double result, bool deb1, bool deb3, bool reaLL) {
    bool activator = false;
    cout << "\nSolving... " << endl;
    if (DepOrElev == 'e' || 'E') {
        result = eleTan(degrees, val1, result);
    } else if (DepOrElev == 'd' || DepOrElev == 'D') {
        result = depTan(degrees, val1, result);
    }
    if (deb1 == false) {
        result = personHeight + result;
    }
    activator = true;
    main( degrees, val1, result, DepOrElev, activator, reaLL, personHeight);

}
