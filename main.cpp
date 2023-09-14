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

    std::cout << "Final Position: (" << X << ", " << Y << ", " << Z << ")\n";

    return 0;
}
