#include <iostream>
#include "User.h"
#include "Customer.h"
#include "TravelAgent.h"
using namespace std;
#include <vector>
vector<Trip> trips;
vector<Booking> bookings;
vector<User> users;
User* nw = 0;
int num; string password; string name;
int main() {
    setlocale(0, "rus");
    while (1) {
        int a;
        cout << "1.создать аккаунт" << endl;
        cout << "2.войти в акканут" << endl;
        cin >> a;
        switch (a)
        {
        case 0:
            return 0;
        case 1:

            cout << "введите имя:" << endl;
            cin >> name;
            cout << "введите пароль:" << endl;
            cin >> password;
            cout << "номер userа - " << users.size() << endl;
            users.push_back(User(name, password));
            break;
        case 2:
            cout << "номер userа : " << endl; cin >> num;
            if (num < users.size()) {
                cout << "введите пароль: "; cin >> password;
                if (users[num].login(password)) {
                    cout << "SUCCES" << endl;
                    nw = &users[num];
                }
            }
            break;
        }
    }
}