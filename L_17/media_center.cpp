#include "media_center.h"
#include "smart_app.h"

using namespace std;

MediaCenter::MediaCenter(const string& n) : name(n) {
    cout << "[MediaCenter] Constructor: " << name << "\n";
}

MediaCenter::~MediaCenter() {
    cout << "[MediaCenter] Destructor: " << name << "\n";
}
