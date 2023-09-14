#include <bits/stdc++.h>
using namespace std;
class Spacecraft
{
private:
    int x, y, z;
    char direction;

public:
    Spacecraft(int initialX, int initialY, int initialZ, char initialDirection)
    {
        x = initialX;
        y = initialY;
        z = initialZ;
        direction = initialDirection;
    }
    void moveForward()
    {
        switch (direction)
        {
        case 'N':
            y++;
            break;
        case 'S':
            y--;
            break;
        case 'E':
            x++;
            break;
        case 'W':
            x--;
            break;
        case 'U':
            z++;
            break;
        case 'D':
            z--;
            break;
        }
    }

    void moveBackward()
    {
        switch (direction)
        {
        case 'N':
            y--;
            break;
        case 'S':
            y++;
            break;
        case 'E':
            x--;
            break;
        case 'W':
            x++;
            break;
        case 'U':
            z--;
            break;
        case 'D':
            z++;
            break;
        }
    }
    void turnLeft()
    {
        switch (direction)
        {
        case 'N':
            direction = 'W';
            break;
        case 'S':
            direction = 'E';
            break;
        case 'E':
            direction = 'N';
            break;
        case 'W':
            direction = 'S';
            break;
        case 'U':
            direction = 'N';
            break;
        case 'D':
            direction = 'S';
            break;
        }
    }

    void turnRight()
    {
        switch (direction)
        {
        case 'N':
            direction = 'E';
            break;
        case 'S':
            direction = 'W';
            break;
        case 'E':
            direction = 'S';
            break;
        case 'W':
            direction = 'N';
            break;
        case 'U':
            direction = 'S';
            break;
        case 'D':
            direction = 'N';
            break;
        }
    }
    void turnUp()
    {
        switch (direction)
        {
        case 'N':
            direction = 'U';
            break;
        case 'U':
            direction = 'S';
            break;
        case 'S':
            direction = 'D';
            break;
        case 'D':
            direction = 'N';
            break;
        case 'E':
            direction = 'U';
            break;
        case 'W':
            direction = 'D';
            break;
        }
    }
    void turnDown()
    {
        switch (direction)
        {
        case 'N':
            direction = 'D';
            break;
        case 'D':
            direction = 'S';
            break;
        case 'S':
            direction = 'U';
            break;
        case 'U':
            direction = 'N';
            break;
        case 'E':
            direction = 'D';
            break;
        case 'W':
            direction = 'U';
            break;
        }
    }
    void executeCommands(string commands)
    {
        for (int i = 0; i < commands.size(); i++)
        {
            switch (commands[i])
            {
            case 'f':
                moveForward();
                break;
            case 'b':
                moveBackward();
                break;
            case 'l':
                turnLeft();
                break;
            case 'r':
                turnRight();
                break;
            case 'u':
                turnUp();
                break;
            case 'd':
                turnDown();
            default:
                break;
            }
        }
    }

    void
    getPosition(int &xPos, int &yPos, int &zPos) const
    {
        xPos = x;
        yPos = y;
        zPos = z;
    }

    char getDirection() const
    {
        return direction;
    }
};

int main()
{
    int X, Y, Z;
    cout << "Enter the intial positions:" << endl;
    cout << "X:";
    cin >> X;
    cout << "Y:";
    cin >> Y;
    cout << "Z:";
    cin >> Z;
    char Direction = 'N';
    Spacecraft spacecraft(X, Y, Z, Direction);
    string commands;
    cout << "Enter the Commands:";
    cin >> commands;
    cout << endl;
    spacecraft.executeCommands(commands);
    spacecraft.getPosition(X, Y, Z);
    Direction = spacecraft.getDirection();

    cout << "Final Position: (" << X << ", " << Y << ", " << Z << ")" << endl;
    cout << "Final Direction: " << Direction << endl;
    return 0;
}
