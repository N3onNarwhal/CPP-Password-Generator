using namespace std;
#include <iostream>
#include <string>
#include <string.h>
#include <stdexcept>
#include <cstdlib>
#include <random>
#include "password.h"

int main(){
    
    int input = 1;
    srand(time(0));
    
    // while the user wants to generate passwords (selects menu option 1)
    while (input == 1){
        input = 0;
        while (input == 0){
            try{
                print_menu();
                cin >> input;
                if (cin.fail()){
                    throw std::runtime_error("Input is not an integer.");
                }
                if (input != 1 && input != 2){
                    cout << "Not included in menu." << endl;
                    input = 0;
                }
            } catch (const std::runtime_error& e){
                cout << e.what() << endl;
                cin.clear(); cin.ignore();
            }
        }
        if (input == 2){
            break;
        }

        // determine which characters the user wants included in their password
        bool include_upper = false; bool include_lower = false;
        bool include_digits = false; bool include_specials = false;
        string upper = "invalid"; string lower = "invalid";
        string digit_characters = "invalid"; string special_characters = "invalid";

        cout << "Please enter 'Yes' or 'No' to the following values: " << endl;
        while (upper == "invalid")
        {
            cout << "Include uppercase letters? : ";
            cin >> upper;
            if (upper != "Yes" && upper != "No"){
                upper = "invalid";
                cout << "Please enter 'Yes' or 'No'." << endl;
            }
            if (upper == "Yes"){
                include_upper = true;
            }
        }
        while (lower == "invalid")
        {
            cout << "Include lowercase letters? : ";
            cin >> lower;
            if (lower != "Yes" && lower != "No"){
                lower = "invalid";
                cout << "Please enter 'Yes' or 'No'." << endl;
            }
            if (lower == "Yes"){
                include_lower = true;
            }
        }
        while (digit_characters == "invalid")
        {
            cout << "Include digits? : ";
            cin >> digit_characters;
            if (digit_characters != "Yes" && digit_characters != "No"){
                digit_characters = "invalid";
                cout << "Please enter 'Yes' or 'No'." << endl;
            }
            if (digit_characters == "Yes"){
                include_digits = true;
            }
        }
        while (special_characters == "invalid")
        {
            cout << "Include special characters? : ";
            cin >> special_characters;
            if (special_characters != "Yes" && special_characters != "No"){
                special_characters = "invalid";
                cout << "Please enter 'Yes' or 'No'." << endl;
            }
            if (special_characters == "Yes"){
                include_specials = true;
            }
        }

        int pass_length = 0;
        while (pass_length == 0){
            try{
                cout << "How many characters? Input should be between 8 and 20: ";
                cin >> pass_length;
                if (cin.fail()){
                    throw std::runtime_error("Input is not an integer.");
                }
                if (pass_length < 8 || pass_length > 20){
                    cout << "Not included in menu." << endl;
                    pass_length = 0;
                }
            } catch (const std::runtime_error& e){
                cout << e.what() << endl;
                cin.clear(); cin.ignore();
            }
        }

        string generated = generate_Password(include_upper, include_lower, include_digits, include_specials, pass_length);
        cout << "Password generated: " << generated << endl;
    }

    return 0;
}