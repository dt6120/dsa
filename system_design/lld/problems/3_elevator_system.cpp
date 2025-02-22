#include <bits/stdc++.h>

using namespace std;

enum Direction
{
    UP,
    DOWN,
    IDLE
};

class Request
{
private:
    int floor;
    Direction dir;

public:
    Request(int floor, Direction dir) : floor(floor), dir(dir) {}

    int getFloor()
    {
        return floor;
    }

    Direction getDirection()
    {
        return dir;
    }
};

class Elevator
{
private:
    int id;
    int capacity;
    int currentFloor;
    Direction dir;
    Direction currentDirection;
    priority_queue<Request *> upQueue, downQueue;

public:
    Elevator(int id, int capacity) : id(id), capacity(capacity)
    {
        currentFloor = 1;
        currentDirection = UP;
    }

    void addRequest(int floor, Direction dir)
    {
        Request *request = new Request(floor, dir);
        if (dir == UP)
        {
            upQueue.push(request);
        }
        else if (dir == DOWN)
        {
            downQueue.push(request);
        }

        if (dir == IDLE)
        {
            dir = floor > currentFloor ? UP : DOWN;
        }
    }

    void move()
    {
        if (dir == UP && !upQueue.empty())
        {
            currentFloor = upQueue.top()->getFloor();
            upQueue.pop();
        }
        else if (dir == DOWN && !downQueue.empty())
        {
            currentFloor = downQueue.top()->getFloor();
            downQueue.pop();
        }

        if (upQueue.empty() && downQueue.empty())
        {
            dir = IDLE;
        }
    }

    int getCurrentFloor()
    {
        return currentFloor;
    }
};

class ElevatorSystem
{
private:
    vector<Elevator *> elevators;

public:
    ElevatorSystem(int num)
    {
        while (num > 0)
        {
            elevators.push_back(new Elevator(num, 10));
            num--;
        }
    }

    void addRequest(int floor, Direction dir) {}

    void move()
    {
        for (auto elevator : elevators)
        {
            elevator->move();
        }
    }

    void getStatus() {}
};

int main() {}