#include <iostream>

int main() {
    int les = 0;
    int timeLes = 0;
    int timePer = 0;
    std::cin >> les >> timeLes >> timePer;
    if ((2 <= les)&&(les <= 1000))
    {if ((1 <= timeLes)&&(timeLes <= 1000)) {
        if ((1 <= timeLes)&&(timePer <= 30)) {
            int timeAll = (les * timeLes) + 30 + ((les-2)*timePer);
            printf("%d", timeAll);

        }
    }
    }
}