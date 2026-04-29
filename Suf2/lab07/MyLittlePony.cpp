#include "MyLittlePony.h"

#include <vector>

int main() {
    MagicCreature *mc = new Centaur();
    cout << "Class Name: ";
    cout << (dynamic_cast<Centaur*>(mc))->className() << endl;
    delete mc;

    std::vector<Horse*> umavector;
    umavector.push_back(new Horse());
    umavector.push_back(new Pegasus());
    umavector.push_back(new Centaur());
    std::cout << "\nArray:\n";
    for (Horse* e: umavector)
    {
        std::cout << e->className()<<" ";
    }

    for (Horse* uma : umavector) {
        delete uma;
    }

    Horse** umamazing = new Horse*[3];
    umamazing[0] = new Horse();
    umamazing[1] = new Pegasus();
    umamazing[2] = new Centaur();

    for (int uma = 0; uma < 3; uma++) delete umamazing[uma];
    delete[] umamazing;

    return 0;
}
