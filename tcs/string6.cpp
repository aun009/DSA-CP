#include <iostream>
#include <sstream>
using namespace std;



int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    string name;

    getline(cin, name);

    // stringstream ss(name);

    // while(ss >> name) {
    // 	cout << name;
    // }

    // cout << endl;

    



    // string sub = name.substr(0,8);

    if(name.find("love") != string::npos) {
    	cout << "found" << endl;
    }

    else {
    	cout << "Not found" << endl;
    }


    // name.erase(2,5);

    cout << name.substr(3,4) << endl;

    cout << name << endl;

    return 0;

}