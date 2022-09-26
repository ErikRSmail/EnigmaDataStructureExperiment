/*
struct ContactParent {
    bool shouldSwitch (char* id);
}
struct Contact
{
    Contact *next;
    Contact *connectedRight;
    Contact *connectedLeft;

    char* id;
    char value;

    ContactParent parent;

    Contact sendRight()
    {
        this->connectedRight = this->connectedRight.send();

        std::cout << this->id << ' ' << this->value << std::endl;

        if (this->should_switch())
        {
            return this->next;
        }
        else
        {
            return this->connectedRight;
        }
    }
};
*/