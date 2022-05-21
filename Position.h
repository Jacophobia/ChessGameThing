#pragma once

class Position {
private:
    char position;
    bool valid = false;
public:
    Position(): position(0) {}
    Position(int pos);
    Position(int x, int y) {
        set(x, y);
    }
    Position(const Position& rhs)
    {
        position = rhs.position;
    }

    bool isValid() {
        return valid;
    }

    void set(int x, int y) {
        valid = (x >= 1 && x <= 8 && y >= 1 && y <= 8);
        position = (x - 1) + ((y - 1) * 8);
    }

    int getX() {
        return 1 + (position % 8);
    }

    int getY() {
        return 1 + (position / 8);
    }
    bool Position::operator==(const Position & rhs) {
        return position == rhs.position;
    }
    Position& operator=(const Position & rhs)
    {
        position = rhs.position;
        valid = rhs.valid;
        return *this;
    }
};