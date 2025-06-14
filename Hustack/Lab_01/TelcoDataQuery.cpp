#include <iostream>
#include <map>
using namespace std;

bool isValidPhoneNumber(string phoneNumber) {
    if (phoneNumber.length() != 10) {
        return false;
    }
    for (int i = 0; i < phoneNumber.length(); i++) {
        if (phoneNumber[i] < '0' || phoneNumber[i] > '9') {
            return false;
        }
    }
    return true;
}

/* bool isValidDate (string date) {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    return true;
}

bool isValidTime(string time) {
    if (time.length() != 8 || time[2] != ':' || time[5] != ':') {
        return false;
    }
    return true;
} */

int convertToSeconds(string time) {
        int hh = stoi(time.substr(0, 2));
        int mm = stoi(time.substr(3, 2));
        int ss = stoi(time.substr(6, 2));
        return hh*3600 + mm*60 + ss;
    return 0;
}


int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string token;
    int totalNumberOfCalls = 0;
    int countIncorrectNumber = 0;
    map<string, int> countCallsFrom;
    map<string, int> countTimeCallFrom;

    do {
        cin >> token;
        if (token == "#") {
            break;
        }
        string from_Number, to_Number, date, from_Time, end_Time;
        cin >> from_Number >> to_Number >> date >> from_Time >> end_Time;
        
        if (!isValidPhoneNumber(from_Number) || !isValidPhoneNumber(to_Number)) {
            countIncorrectNumber++;
        }

        /* if (!isValidDate(date)) {
            cout << "invalid date!" << endl;
        }
        if (!isValidTime(from_Time) || !isValidTime(end_Time)) {
            cout << "invalid time!" << endl;
        } */

        totalNumberOfCalls++;
        countCallsFrom[from_Number]++;
        int duration = convertToSeconds(end_Time) - convertToSeconds(from_Time);
        countTimeCallFrom[from_Number] += duration;

    } while(true);


    do {
        cin >> token;
        if (token == "#") {
            break;
        }
        if (token == "?check_phone_number") {
            cout << (countIncorrectNumber > 0 ? 0 : 1) << endl; //done
        }

        if (token == "?number_calls_from") {
            string phoneNumber;
            cin >> phoneNumber;
            cout << countCallsFrom[phoneNumber] << endl; //done
        }

        if (token == "?number_total_calls") {
            cout << totalNumberOfCalls << endl; //done
        }
        if (token == "?count_time_calls_from") {
            string phoneNumber;
            cin >> phoneNumber;
            cout << countTimeCallFrom[phoneNumber] << endl; //done
        }

    } while(true);

    return 0; 

}