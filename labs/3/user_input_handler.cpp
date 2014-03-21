#include "user_input_handler.h"

// Default constructor definitions, initialize error messages.
UserInputHandler::UserInputHandler() {
  invalid_char_ = "Input is not a character. Try again: ";
  char_not_allowed_ = "Input is not a part of the string. Try again: ";
  invalid_int_ = "Input is not an integer. Try again: ";
  low_int_ = "Input is too low. Try again: ";
  high_int_ = "Input is too high. Try again: ";
  invalid_double_ = "Input is not a double. Try again: ";
  invalid_bool_ = "Input is not a T, F, true or false. Please try again: ";
  too_long_string_ = "The string you entered is too long. Try again: ";
  empty_string_ = "Empty string not allowed. Try again: ";
  }

// The following are accessor and mutator function definitions
void UserInputHandler::SetInvalidChar(string invalid_char) {
  invalid_char_ = invalid_char;
}

string UserInputHandler::GetInvalidChar() const {
  return invalid_char_;
}

void UserInputHandler::SetCharNotAllowed(string char_not_allowed) {
  char_not_allowed_ = char_not_allowed;
}

string UserInputHandler::GetCharNotAllowed() const {
  return char_not_allowed_;
}

void UserInputHandler::SetInvalidInt(string invalid_int) {
  invalid_int_ = invalid_int;
}

string UserInputHandler::GetInvalidInt() const {
  return invalid_int_;
}

void UserInputHandler::SetLowInt(string low_int) {
  low_int_ = low_int;
}

string UserInputHandler::GetLowInt() const {
  return low_int_;
}

void UserInputHandler::SetHighInt(string high_int) {
  high_int_ = high_int;
}

string UserInputHandler::GetHighInt() const {
  return high_int_;
}

void UserInputHandler::SetInvalidDouble(string invalid_double) {
  invalid_double_ = invalid_double;
}

string UserInputHandler::GetInvalidDouble() const {
  return invalid_double_;
}

void UserInputHandler::SetInvalidBool(string invalid_bool) {
  invalid_bool_ = invalid_bool;
}

void UserInputHandler::SetTooLongString(string too_long_string) {
  too_long_string_ = too_long_string;
}

string UserInputHandler::GetTooLongString() const {
  return too_long_string_;
}

void UserInputHandler::SetEmptyString(string empty_string) {
  empty_string_ = empty_string;
}

string UserInputHandler::GetEmptyString() const {
  return empty_string_;
}

// Definition for GetBoolean function
bool UserInputHandler::GetBoolean() {
  string user_string_;
  while (true) {
    cin >> user_string_;
    for (unsigned int i = 0; i < user_string_.length(); i++) {
      user_string_[i] = toupper(user_string_[i]);
    }
    if (user_string_ == "T" || user_string_ == "TRUE") {
      return true;
    } else if (user_string_ == "F" || user_string_ == "FALSE") {
      return false;
    } else {
      cout << invalid_bool_;
    }
  }
}

// Definition for GetString function
string UserInputHandler::GetString(int max_length_ , bool empty_string_) {
  string user_string_;
  while (true) {
  getline(cin, user_string_);
  if (!empty_string_ && user_string_ == "") {
    cout << empty_string_;
    continue;
  }
  if (max_length_ >= 0) {
    int user_string_length_= user_string_.length();
    if (user_string_length_ > max_length_) {
      cout << too_long_string_;
      continue;
    }
  }
  cout << user_string_;
  return user_string_;
  }
}

// Definition for GetDouble function
double UserInputHandler::GetDouble() {
  double user_double_;
  while (true) {
    cin >> user_double_;
    if (cin) {
      return user_double_;
    } else {
      cout << invalid_double_;
      cin.clear();
      cin.ignore(1000, '\n');
    }
  }
}

// Definition for GetInteger function
int UserInputHandler::GetInteger(int min_int_, int max_int_) {
  int user_int_;
  bool user_success_ = false;
  while (user_success_ == false) {
    cin >> user_int_;
    if (cin) {
      if (user_int_ < min_int_) {
        cout << low_int_;
        } else if (user_int_ > max_int_) {
        cout << high_int_;
        } else {
        cout << user_int_;
        user_success_ = true;
        return user_int_;
      }
    } else {
      cout << invalid_int_;
      cin.clear();
      cin.ignore(1000, '\n');
    }
  }
  return 0;
}

// Definition for GetSingleCharacter function
char UserInputHandler::GetSingleCharacter(string str_) {
  char one_char_;
  string input_;
  bool input_success_;
  input_success_ = false;
  while (input_success_ == false) {
    getline(cin, input_);
    if (input_.length() > 1 || input_ == "") {
      cout << invalid_char_;
    } else if (str_!= "" && str_.find(input_[0]) == string::npos) {
      cout << invalid_char_;
    } else {
    one_char_ = input_[0];
    cout << one_char_;
    input_success_ = true;
    }
  }
  return one_char_;
}

