#pragma once
#include "ncurses.h"

class Radio {
private:
    unsigned int volume;
    unsigned int station;

public:
    static constexpr unsigned int MIN_VOLUME  = 0;
    static constexpr unsigned int MAX_VOLUME  = 10;
    static constexpr unsigned int MIN_STATION = 1;
    static constexpr unsigned int MAX_STATION = 10;

    static constexpr const char* STATION_NAMES[] = {
        "Hangover FM",
        "Doshirak FM",
        "Hit 24 : Shit on stream",
        "Alcohol radio 69.6",
        "FM-Trauma",
        "Hellbroadcast 666",
        "Prosranets FM",
        "Toilet.Band FM",
        "FM-Depression",
        "Moonshine FM"
    };

    const char* getStationName() const {
        return STATION_NAMES[station - 1];
    }

    Radio() {
        volume  = 3;
        station = MIN_STATION;
    }

    Radio(Radio const & other) {
        volume  = other.volume;
        station = other.station;
    }

    ~Radio() {}

    unsigned int getVolume()  const { return volume;  }
    unsigned int getStation() const { return station; }

    void setVolume(unsigned int const & volume) {
        if (volume >= MIN_VOLUME && volume <= MAX_VOLUME) {
            this->volume = volume;
        }
    }

    void setStation(unsigned int const & station) {
        if (station >= MIN_STATION && station <= MAX_STATION) {
            this->station = station;
        }
    }
    void incVolume() {
        Radio::setVolume(getVolume() + 1);
    }

    void decVolume() {
        Radio::setVolume(getVolume() - 1);
    }

    void nextStation() {
        if (station == MAX_STATION) {
            setStation(MIN_STATION);
        } else {
            setStation(station + 1);
        }
    }

    void previousStation() {
        if (station == MIN_STATION) {
            setStation(MAX_STATION);
        } else {
            setStation(station - 1);
        }
    }

    Radio& operator++() {
        nextStation();
        return *this;
    }

    Radio operator++(int) {
        Radio temp = *this;
        nextStation();
        return temp;
    }

    Radio& operator--() {
        previousStation();
        return *this;
    }

    Radio operator--(int) {
        Radio temp = *this;
        previousStation();
        return temp;
    }

    Radio& operator=(Radio const & other) {
        if (this != &other) {
            volume  = other.volume;
            station = other.station;
        }
        return *this;
    }
};

void drawVolumeBar(WINDOW* win, int y, int x, unsigned int vol, unsigned int maxVol);
void redraw(WINDOW* win, const Radio& radio);
