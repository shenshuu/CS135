/*
Name: Michael Shen 
Course: CSCI 135 
Instructor: Genadiy Maryash 
Lab: 11B
*/

#include <iostream>
#include <string>
#include <vector>
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

struct Post {
    string username;
    string message;
};

class Network {
    private:
        static const int MAX_USERS = 20;
        static const int MAX_POSTS = 100;
        int numUsers;
        int numPosts;
        Profile profiles[MAX_USERS];
        Post posts[MAX_POSTS];
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
            Network(): numUsers(0), numPosts(0) {}

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

            bool writePost(string usrn, string msg) {
                if (findID(usrn) == -1 || numPosts == MAX_POSTS) return false;
                for (int i = 0; i < MAX_POSTS; i++) {
                    if (posts[i].username == "") {
                        posts[i] = Post();
                        posts[i].username = usrn;
                        posts[i].message = msg;
                        break;
                    }
                }
                return true;
            }

            bool currentlyFollowing(vector<int>& users, int id) {
                for (int i = 0; i < users.size(); i++) {
                    if (users[i] == id) return true;
                }
                return false;
            }

            bool printTimeline(string usrn) {
                int user_id = findID(usrn);
                if (user_id == -1) return false;
                vector<int> users;
                for (int i = 0; i < MAX_USERS; i++) {
                    if (following[user_id][i]) {
                        users.push_back(i);
                    }
                }

                for (int i = MAX_POSTS-1; i >= 0; i--) {
                    if (posts[i].username == usrn) {
                        cout << "Displayname (@" << usrn << "): " << posts[i].message << '\n'; 
                    } else if (posts[i].username != "" && currentlyFollowing(users, findID(posts[i].username))) {
                        cout << "Displayname (@" << posts[i].username << "): " << posts[i].message << '\n'; 
                    }
                }
                return true;
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
   
  nw.follow("mario", "luigi");
  nw.follow("luigi", "mario");
  nw.follow("luigi", "yoshi");
  nw.follow("yoshi", "mario");

  // write some posts
  nw.writePost("mario", "It's a-me, Mario!");
  nw.writePost("luigi", "Hey hey!");
  nw.writePost("mario", "Hi Luigi!");
  nw.writePost("yoshi", "Test 1");
  nw.writePost("yoshi", "Test 2");
  nw.writePost("luigi", "I just hope this crazy plan of yours works!");
  nw.writePost("mario", "My crazy plans always work!");
  nw.writePost("yoshi", "Test 3");
  nw.writePost("yoshi", "Test 4");
  nw.writePost("yoshi", "Test 5");

  cout << endl;
  cout << "======= Mario's timeline =======" << endl;
  nw.printTimeline("mario");
  cout << endl;

  cout << "======= Yoshi's timeline =======" << endl;
  nw.printTimeline("yoshi");
  cout << endl;
}