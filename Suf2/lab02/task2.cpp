class Radio {
private:
    unsigned int volume;
    unsigned int station;

public:
    static const unsigned int MIN_VOLUME  = 0;
    static const unsigned int MAX_VOLUME  = 10;
    static const unsigned int MIN_STATION = 1;
    static const unsigned int MAX_STATION = 10;

    Radio() {
        volume  = 3;
        station = MIN_STATION;
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
};