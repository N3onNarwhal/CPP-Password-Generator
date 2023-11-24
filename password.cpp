using namespace std;
#include <iostream>
#include <string>
#include <string.h>
#include <stdexcept>
#include <cstdlib>
#include <random>
#include "password.h"

void print_menu(){
    cout << "Please select an option:" << endl;
    cout << "   1. Generate password" << endl;
    cout << "   2. Quit" << endl;
}

string generate_Password(bool uppers, bool lowers, bool incl_digits, bool incl_specials, int pass_length){
    string uppercase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowercase = "abcdefghijklmnopqrstuvwxyz";
    string digits = "012345679";
    string special = "~`!@#$%^&*()-_=+[{}]/:;',.<>?";
    string rand_choices = "";
    string final_password = "";

    // based on user input, add characters to character choices string
    if (uppers){
        rand_choices += uppercase;
    }
    if (lowers){
        rand_choices += lowercase;
    }
    if (incl_digits){
        rand_choices += digits;
    }
    if (incl_specials){
        rand_choices += special;
    }

    // choose random characters and add them to the final string
    for (int i = 0; i < pass_length; i++)
    {
        int pos = (rand() % (rand_choices.size() -1));
        final_password += rand_choices.substr(pos, 1);
    }

    return final_password;
}