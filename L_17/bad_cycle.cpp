#include "bad_cycle.h"

using namespace std;

BadSmartApp::BadSmartApp(const string& n) : name(n) {
    cout << "[BadSmartApp] Constructor: " << name << "\n";
}

BadSmartApp::~BadSmartApp() {
    cout << "[BadSmartApp] Destructor: " << name << "\n";
}

BadMediaCenter::BadMediaCenter(const string& n) : name(n) {
    cout << "[BadMediaCenter] Constructor: " << name << "\n";
}

BadMediaCenter::~BadMediaCenter() {
    cout << "[BadMediaCenter] Destructor: " << name << "\n";
}
