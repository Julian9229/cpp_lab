#include "smart_app.h"
#include "media_center.h"

using namespace std;

SmartApp::SmartApp(const string& n) : name(n) {
    cout << "[SmartApp] Constructor: " << name << "\n";
}

SmartApp::~SmartApp() {
    cout << "[SmartApp] Destructor: " << name << "\n";
}
