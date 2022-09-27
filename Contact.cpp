#include <iostream>

using std::cout;
using std::endl;

class ContactParent {
    public:
        virtual bool shouldSwitch (char* id) = 0;
};

class SwitchBoard: public ContactParent {
    bool shouldSwitch() {
        return false;
    }
};

class Contact
{
    public:

    Contact *next;
    Contact *connectedRight;
    Contact *connectedLeft;

    char* id;
    char value;

    ContactParent *parent;
    
    Contact * sendRight();
};

Contact * Contact::sendRight()
{
    connectedRight = connectedRight->sendRight();

    cout << id << ' ' << value << endl;

    if (parent->shouldSwitch(id))
    {
        return next;
    }
    else
    {
        return connectedRight;
    }
};

