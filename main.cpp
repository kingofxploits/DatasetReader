#include <windows.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h>
#include <utility>
#include <iomanip>
#include <string>
#include <vector>
#include <limits>
#include "stateViolations.h"
#include "Record.h"

using namespace std;
            // fixes an issue regarding numeric_limits<streamsize>::max
#define MAXLIMIT  
            // TypeWriter Effect
template<typename T>
void TypeWriter(T& message, int time);
            // wait for continue input
template<typename T>
void Continue(T string);
            // Clears the screen
void ClearScreen();
            // Search records by given state
vector<Record> stateSearch(vector<Record>& , string , int&);
            // Sorting (Bubble Sorting)
void bubbleSorting(vector<Record>&);
            // Search License Plate (Binary Search)
int Search(std::vector<Record>&, std::string);
            // Total Number of Unpaid Violations
int UnpaidViolations(std::vector<Record>& );
            // AveragePaidViolations
double AveragePaidViolations(std::vector<Record>&);
            // Read DataSet 
bool readCSVtovector(string, vector<Record>&);
            // New printing function
void printData(vector<Record>&, int);
            // User INterface
void UserInterface(vector<Record>&);
            // main function
int main() {
        // create vector of records
    vector<Record> dataSetRecords;
        // name of file for data 
    string filename{ "dataset.csv" };
        // Read in dataset
    readCSVtovector(filename, dataSetRecords);
        // Display user interface
    UserInterface(dataSetRecords);
        
    return 0; // exit with success
} //end main()

//read in csv records to vector of Records
bool readCSVtovector(string fn, vector<Record>& records) {
    bool success = false;

    ifstream infile(fn, ios::in); // open file 
    string line; // string to hold each line of data 
    std::string licensePlate, state, licenseType, issueDate, payment,
        violation, fineAmount, issuingAgency, violationStatus;

    if (infile.is_open()) { // if file opened successfully
        getline(infile, line); // read in header row
        std::cout << "Reading..\n";
        // use for loop to go through remaining rows 
        while (getline(infile, line)) {
            istringstream row{ line };
            // Use getline(row, line, ','); to store unwanted values
            getline(row, licensePlate, ',');
            getline(row, state, ',');
            getline(row, licenseType, ',');
            getline(row, line, ',');
            getline(row, issueDate, ',');
            getline(row, line, ',');
            getline(row, violation, ',');
            getline(row, line, ',');
            getline(row, fineAmount, ',');
            getline(row, line, ',');
            getline(row, line, ',');
            getline(row, line, ',');
            getline(row, payment, ',');
            getline(row, line, ',');
            getline(row, line, ',');
            getline(row, line, ',');
            getline(row, issuingAgency, ',');
            getline(row, violationStatus, ',');
            getline(row, line); //last row=unwanted

            Record newRecord{ licensePlate, state, licenseType, issueDate,
                violation, fineAmount,issuingAgency, violationStatus,payment };

            records.push_back(newRecord);
        }
        success = true; // true means we were able to read file 
    }
    infile.close();
    return success;
}
            //printing from overloaded operator
void printData(vector<Record>& records, int recordSize) {
    if (recordSize > records.size()) {recordSize = records.size();}
    if(recordSize == 1){ cout << "\tPrinting " << recordSize << " record \n"; }
    else { cout << "\tPrinting " << recordSize << " records \n"; }
    for (int i{ 0 }; i < recordSize; i++) {
        cout << records[i];
    }
    //print all records
    char printAllRecords{NULL};
    while (true) {
        cout << "\tWould you like to print all records? y or n: ";
        cin >> printAllRecords;
        switch (printAllRecords) {
            case 'y': case 'Y':
            {
                cout << "\nPrinting all " << records.size() << " records.\n";
                for (Record rec : records) {
                    cout << rec;
                }
                cout << "\t succesfully printed " << records.size() << " records!" << endl;
                [[fallthrought]];
            }
            case 'n': case 'N':
            {
                Continue("Click ESC to EXIT or BackScpace to return to main menu :)");
                while (_getch()) {
                    if (GetAsyncKeyState(VK_ESCAPE) != 0) {
                        //exit with code 0
                        TypeWriter("\tExiting now...\n", 20);
                        exit(0);
                    }
                    if (GetAsyncKeyState(VK_BACK) != 0) {
                        main();
                    }
                   
                }
                [[fallthrough]];
            }
            default: {
                cout << "\t"<<printAllRecords << " is not an option :( \n";
            }
        }//end switch
    }
}

void UserInterface(vector<Record>& dataSetRecords) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (1 + rand() % 15));
    TypeWriter("\t\t\t\t\t\[*]Programming Project[*]\n\n", 20);
    int pointer = 0;
    std::vector<std::string> mainMenu = { "Search License PLate",
        "Average Paid violations","State With the Most Violations",
         "Print Records", "Total Number of Unpaid Violations",
        "Print Records of Given State","[!]Exit[!]" };
    while (true) {
        ClearScreen();
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (1 + rand() % 15));
        printf("\t\t\t\t\t[*]Programming Project[*]\n");
        printf("\t\t\t\t  [*]Click [Space] To Select Choice[*]\n\n");
        for (int i = 0; i < mainMenu.size(); i++) {
            if (i == pointer) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                cout << "\t-> "; TypeWriter(mainMenu[i], 20); std::cout << " <-\n";
            }
            else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                cout << "\t"<< mainMenu[i] << "\n";
            }
        }//end forloop

        while (true) {
            if (GetAsyncKeyState(VK_UP) != 0) {
                pointer -= 1;
                if (pointer == -1) {
                    pointer = mainMenu.size();
                }
                break;
            }

            else if (GetAsyncKeyState(VK_DOWN) != 0) {
                pointer += 1;
                if (pointer == mainMenu.size()) {
                    pointer = 0;
                }
                break;
            }

            else if (GetAsyncKeyState(VK_ESCAPE) != 0) {
                ClearScreen();
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (1 + rand() % 15));
                TypeWriter("\tExiting Now...\n", 20);
                exit(0);
            }

            else if (GetAsyncKeyState(VK_SPACE) != 0) {
                switch (pointer) {
                case 0: //Search License PLate
                {
                    while(true) {
                        cout << "Sorting...\n";
                        bubbleSorting(dataSetRecords);
                        std::string search;
                        ClearScreen();
                        std::cout << "\t\t\tTesting License PLates = HJY3839, 67526MB, ERJ6208, JGJ3781, HXR7183\n"""
                            """\t\t\tType exit to Quit or back to return to main menu\n";
                        printf("\tLicense Plate Search: ");
                        std::cin >> search;
                        for (int i= 0; i < search.size(); i++) {
                            search[i] = toupper(search[i]);
                        }
                        if (Search(dataSetRecords, search) != -1) {
                            for (int i{ 0 }; i < 1; i++) {
                                std::cout << dataSetRecords[Search(dataSetRecords, search)];
                            }
                        }
                        else if (search == "EXIT") { exit(0);}
                        else if (search == "BACK") { main(); }
                        else {
                            std::cout << search << " is not in the dataSet :(\n";
                        }
                        Sleep(1000);
                        Continue("Press Any Key to Search Again :)");
                        while (_getch() == 0) { 
                            break; }
                    }
                    main();
                    [[fallthrough]];
                }
                case 1: //Average Paid violations
                {
                    while (true) {
                        ClearScreen();
                        cout << "\n\n\tAverage Paid Violations " << setprecision(4)
                            << AveragePaidViolations(dataSetRecords) * 100 << "%"<<endl;
                        Continue("Press BackSpace to continue");
                        while (_getch()) {
                            if (GetAsyncKeyState(VK_BACK) != 0)
                                main();
                        } 
                    } //end main while loop
                    [[fallthrough]];
                } //end case 1
                case 2: //State With the Most Violations
                {
                    while (true) {
                        ClearScreen();
                        cout << "\n\n\tThe state with the most violations is "
                            << mostViolationsState(dataSetRecords) << endl;
                        Continue("Press BackSpace to continue");
                        while (_getch()) {
                            if (GetAsyncKeyState(VK_BACK) != 0)
                                main();
                        }
                    }
                    [[fallthrough]];
                } //end case 2 
                case 3: // PrintRecords
                {
                    ClearScreen();
                    int numberOfRecords{ 0 };
                    std::cout << "\n\tHow many records should be printed?";
                    std::cin >> numberOfRecords;
                            //integer validation
                    while (!std::cin.good()) {
                        printf("\tPlease enter a valid integer!\n");
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max MAXLIMIT(), '\n');
                        cout << "\tHow many records should be printed?";
                        cin >> numberOfRecords; cout << endl;
                    }//end while loop
                            //print records using overloaded opperator
                    printData(dataSetRecords, numberOfRecords);
                    break;
                } //end case 3
                case 4: //Total Number of Unpaid Violations
                {
                    while (true) {
                        ClearScreen();
                        cout << "\n\n\tThe total number of unpaid violations is "
                            << UnpaidViolations(dataSetRecords) << endl;
                        Continue("Press BackSpace to continue");
                        while (_getch()) {
                            if (GetAsyncKeyState(VK_BACK) != 0)
                                main();
                        }
                    }
                    [[fallthrough]];
                } //end case 4
                case 5: //Print Records of Given State
                {
                    while(true) {
                        ClearScreen();
                        string state;
                        int violationCount{0};
                        cout << "\t\tType exit to Quit or back to return to main menu\n";
                        cout << "\t\tPlease enter any abbreviated state [NY, PA]: ";
                        cin >> state;
                        for (int i{ 0 }; i < state.size(); i++) {
                            state[i] = toupper(state[i]);
                        }
                        if (state == "EXIT") {exit(0);} //exit program
                        if (state == "BACK") {main(); } //return to main menu
                        cout << "\n\n";
                        stateSearch(dataSetRecords, state, violationCount); //Count violations for state
                        if (violationCount > 0) {
                            TypeWriter("\t\t\t\tPrinting ", 20);
                            cout << violationCount << " Records For "; TypeWriter(state, 20);
                        }
                        else {
                            TypeWriter("\t\t\t\tThere is no records for ", 20);
                            TypeWriter(state, 20); cout << "\n";
                        }
                        for (int i{ 0 }; i < stateSearch(dataSetRecords, state, violationCount).size(); i++) {
                            cout << stateSearch(dataSetRecords, state, violationCount)[i] << endl;
                        }
                        if (violationCount > 0) {
                            TypeWriter("\t\t\tSuccessfully Printed ", 20);
                            cout << violationCount << " Records For "; TypeWriter(state, 20);
                        }
                        Continue("Press Any Key To Search Again :)");
                        while (_getch()) {
                            break;
                        }
                    }
                     main();
                    [[fallthrough]];
                } //end case 5
                case 6: //[!]Exit[!]
                {
                    ClearScreen();
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (1 + rand() % 15));
                    TypeWriter("\tExiting Now...\n", 20);
                    exit(0);
                    [[fallthrough]];
                } //end case 6
                default:
                    break;
                }//end switch
            } //end return else
        }
    }//end main while loop
}//end userInterface()

                    //Binary Search
int Search(vector<Record>& vector, std::string search) {
    //License plate test ->  HXR7183
    int position = -1;
    int low = 0;
    int high = vector.size() - 1;
    int middle = (low + high) / 2;
    std::vector<std::string> tempVector;
    for (Record rec : vector) {
        tempVector.push_back(rec.getLicensePlate());
    }
    for (int i{ 0 }; i < tempVector.size(); i++) {
        do {
            if (search == tempVector[middle]) {
                position = middle; // update position value if found
            }
            else if (search < tempVector[middle])
                high = middle - 1; // find the new high value        
            else
                low = middle + 1; // find the new low value        
            middle = (low + high) / 2; // find the middle of new search area    
        } while (low <= high && position == -1);
    }
    return position;
} //end Search()

                    //Sort the dataSet for appropriate Searching
void bubbleSorting(vector<Record>& dataSet) {
    bool swapped;
    do {
        swapped = false;
        for (int i{ 0 }; i < dataSet.size() - 1; i++) {
            if (dataSet[i].getLicensePlate() > dataSet[i + 1].getLicensePlate()) {
                swap(dataSet[i], dataSet[i + 1]);
                swapped = true;
            }
        }
    } while (swapped == true);

}//end bubble sorting

                        //Search by inputted State
vector<Record> stateSearch(vector<Record>& vec, string state, int& violationCount) {
    std::vector<Record> tempVector;
    int tempCount{ 0 };
    for (int i{ 0 }; i < vec.size(); i++) {
        if (state == vec[i].getState()) {
            tempVector.push_back(vec[i]);
            tempCount++;
        }
    }
    violationCount = tempCount;
    return tempVector;
}//end stateSearch

                    //Average Paid violations
double AveragePaidViolations(std::vector<Record>& dataSet) {
    vector<double> paidViolations;
    vector<double> tempViolations;
    vector<int> unpaid;
    double total{ 0 };
    for (Record rec : dataSet)
        tempViolations.push_back(stod(rec.getPayments()));
    for (int i{ 0 }; i < tempViolations.size(); i++) {
        if (tempViolations[i] != 0) {
            paidViolations.push_back(tempViolations[i]);
            total++;
        }
    }
    double Average = total / tempViolations.size();
    return Average;
} //end AveragePaidViolations()

            //Total Number of Unpaid Violations
int UnpaidViolations(std::vector<Record>& dataSet) {
    vector<double> tempViolations;
    vector<int> unpaid;
    int total{ 0 };
    for (Record rec : dataSet)
        tempViolations.push_back(stod(rec.getPayments()));
    for (int i{ 0 }; i < tempViolations.size(); i++) {
        if (tempViolations[i] == 0) {
            unpaid.push_back(tempViolations[i]);
            total++;
        }
    }
    return total;
} //end UnpaidViolations()

template<typename T>
void TypeWriter(T& message, int time) {
    std::string typeMessage = message;
    int count = 0;
    while (typeMessage[count] != NULL) {
        std::cout << typeMessage[count];
        Sleep(time);
        count++;
    } //end while loop
} //end TypeWriter()

template<typename T>
void Continue(T string) {
    srand(time(NULL));
    int cursorPos{ 0 };
    std::vector<std::string> message;
    message.push_back(string);
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
    for (int i{ 0 }; i < message.size(); i++) {
        if (i == cursorPos) {
            //Change color and display
            int randomColor = 1 + rand() % 15;
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), randomColor); // change text color to random
            std::cout << "\n\n\t\t\t\t";
            TypeWriter(message[i], 30);
            std::cout << std::endl;
        } //end if
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15); // change text color to normal
    } //end forloop
}//end Continue()

void ClearScreen() {
#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif
    system(CLEAR);
}
