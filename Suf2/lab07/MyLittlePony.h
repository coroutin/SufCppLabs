#include <iostream>
#include <string>
using namespace std;

class MagicCreature {
protected:
    string magic = "Magic";

public:
    MagicCreature() {
        cout << "Create MagicCreature: " << magic << endl;
    }

    virtual ~MagicCreature() {
        cout << "Delete: MagicCreature" << endl;
    }
};

class Horse:virtual public MagicCreature {
protected:
    string body = "Horse body";
    string head = "Horse head";
    string legs = "Horse legs";
    string tail = "Horse tail";

public:
    Horse() {
        cout << "Create Horse:"
             << "\n\tHead: " << head
             << "\n\tBody: " << body
             << "\n\tLegs: " << legs
             << "\n\tTail: " << tail << endl;
    }

    virtual ~Horse() {
        cout << "Delete: Horse" << endl;
    }

    virtual string className() {
        return "Horse";
    }
};

class Pegasus : public Horse {
protected:
    string wings = "Pegasus wings";

public:
    Pegasus() {
        cout << "Create Pegasus:"
             << "\n\tWings: " << wings << endl;
    }

    ~Pegasus() {
        cout << "Delete: Pegasus" << endl;
    }

    string className() override {
        return "Pegasus";
    }
};

class Human:virtual public MagicCreature {
protected:
    string body = "Human body";
    string head = "Human head";
    string hands = "Human hands";
    string legs = "Human legs";

public:
    Human() {
        cout << "Create Human:"
             << "\n\tHead:  " << head
             << "\n\tBody:  " << body
             << "\n\tHands: " << hands
             << "\n\tTail:  " << legs << endl;
    }

    virtual ~Human() {
        cout << "Delete: Human" << endl;
    }

    virtual string className() {
        return "Human";
    }
};

class Centaur : public Human, public Horse {
public:
    Centaur() {
        cout << "Create Centaur:"
             << "\n\tHead:  " << Human::head
             << "\n\tBody:  " << Human::body << " + " << Horse::body
             << "\n\tLegs:  " << Horse::legs       //
             << "\n\tHands: " << Human::hands << endl;
    }

    ~Centaur() {
        cout << "Delete: Centaur" << endl;
    }

    string className() override {
        return "Centaur";
    }
};