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
        cout << "1.������� �������" << endl;
        cout << "2.����� � �������" << endl;
        cin >> a;
        switch (a)
        {
        case 0:
            return 0;
        case 1:

            cout << "������� ���:" << endl;
            cin >> name;
            cout << "������� ������:" << endl;
            cin >> password;
            cout << "����� user� - " << users.size() << endl;
            users.push_back(User(name, password));
            break;
        case 2:
            cout << "����� user� : " << endl; cin >> num;
            if (num < users.size()) {
                cout << "������� ������: "; cin >> password;
                if (users[num].login(password)) {
                    cout << "SUCCES" << endl;
                    nw = &users[num];
                }
            }
            break;
        }
    }
}