/*
Name: Michael Shen 
Course: CSCI 135 
Instructor: Genadiy Maryash 
Lab: 11B
*/

#include <iostream>
#include <string>
using namespace std;

class Profile {
    private:
        string username;
        string displayname;

    public:
        Profile(string usrn, string dspn):
            username(usrn), displayname(dspn) {}

        Profile():
            username(""), displayname("") {}

        string getUsername() {
            return username;
        }

        string getFullName() {
            return displayname + " (@" + username + ")";
        }

        void setDisplayName(string dspn) {
            displayname = dspn;
        }
};

class Network {
    private:
        static const int MAX_USERS = 20;
        int numUsers;
        Profile profiles[MAX_USERS];

        int findID(string usrn) {
            for (int i = 0; i < MAX_USERS; i++) {
                if (profiles[i].getUsername() == usrn) {
                    return i;
                }
            }
            return -1;
        }

        public:
            Network(): numUsers(0) {}

            bool addUser(string usrn, string dspn) {
                if (findID(usrn) != -1) {
                    return false;
                }
                for (int i = 0; i < MAX_USERS; i++) {
                    if (profiles[i].getUsername() == "") {
                        profiles[i] = Profile(usrn, dspn);
                        numUsers++;
                        break;
                    } 
                }
                return true;
            }

};

int main() {
  Network nw;
  cout << nw.addUser("mario", "Mario") << endl;     // true (1)
  cout << nw.addUser("luigi", "Luigi") << endl;     // true (1)

  cout << nw.addUser("mario", "Mario2") << endl;    // false (0)
  cout << nw.addUser("mario 2", "Mario2") << endl;  // false (0)
  cout << nw.addUser("mario-2", "Mario2") << endl;  // false (0)

  for(int i = 2; i < 20; i++)
      cout << nw.addUser("mario" + to_string(i), 
                 "Mario" + to_string(i)) << endl;   // true (1)

  cout << nw.addUser("yoshi", "Yoshi") << endl;     // false (0)
}