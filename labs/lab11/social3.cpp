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
        bool following[MAX_USERS][MAX_USERS];

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

            bool follow(string usrn1, string usrn2) {
                int m = findID(usrn1), n = findID(usrn2);
                if (m != -1 && n != -1) {
                    following[m][n] = true;
                    return true;
                }
                return false;
            }

            void printDot() {
                cout << "digraph {" << '\n';
                for (int i = 0; i < MAX_USERS; i++) {
                    if (profiles[i].getUsername() != "") {
                        cout << '\t' << "\"@" << profiles[i].getUsername() << "\"" << endl;
                    }
                }
                cout << '\n';
                for (int i = 0; i < MAX_USERS; i++) {
                    for (int j = 0; j < MAX_USERS; j++) {
                        if (profiles[i].getUsername() != "" && profiles[j].getUsername() != "") {
                            if (following[i][j]) {
                                cout << '\t' << "\"@" << profiles[i].getUsername() << "\"";
                                cout << " -> ";
                                cout << "\"@" << profiles[j].getUsername() << "\"" << endl;
                            }
                        }
                    }
                }
                cout << "}";
            }

};

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}