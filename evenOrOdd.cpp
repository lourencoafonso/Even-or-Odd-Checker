#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void checkNumbers(string mode){
    if (mode == "list"){
        int numberOfEvens = 0;
        int numberOfOdds = 0;
        while (true){
            cout << "\nEnter numbers separated by spaces: ";
            string input;
            getline(cin, input);
            stringstream ss(input);
            string num;
            vector<string> results;
            bool valid_input = true;
            float val;
            while (ss >> num){
                try {
                    val = stof(num);
                } catch (invalid_argument&) {
                    cout << "\nInvalid input. Please enter numbers only." << endl;
                    valid_input = false;
                    break;
                }
                if (static_cast<int>(val) % 2 == 0){
                    results.push_back("Even");
                } else {
                    results.push_back("Odd");
                }
            }
            if (valid_input){
                for (const string& result : results){
                    if (result == "\nEven"){
                        numberOfEvens++;
                    } else {
                        numberOfOdds++;
                    }
                }
                break;
            }
        }
        cout << "\nNumber of evens: " << numberOfEvens << endl;
        cout << "\nNumber of odds: " << numberOfOdds << endl;
    } else if (mode == "single"){
        while (true){
            cout << "\nEnter a number: ";
            string num;
            getline(cin, num);
            try {
                float val = stof(num);
                if (static_cast<int>(val) % 2 == 0){
                    cout << "\nEven" << endl;
                } else {
                    cout << "\nOdd" << endl;
                }
                break;
            } catch (invalid_argument&) {
                cout << "\nInvalid input. Please enter a number." << endl;
            }
        }
    }
}

int main() {
    while (true) {
        string listOrSingle;
        cout << "\nEnter 'list' to check multiple numbers or 'single' to check one number: ";
        getline(cin, listOrSingle);
        checkNumbers(listOrSingle);

        string again;
        cout << "\nDo you want to check again? (yes/no): ";
        getline(cin, again);
        if (again != "yes" && again != "y") {
            break; // exit loop and program
        }
    }
    return 0;
}
