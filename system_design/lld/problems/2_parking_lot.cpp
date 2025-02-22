#include <bits/stdc++.h>

using namespace std;

// parking lot: multiple levels, each level multiple spots
// each spot: specific vehicle type
// system: assign and release spot
// track spot availability
// multiple entry and exit points for concurrent access

enum VehicleType
{
    CAR,
    BIKE,
    TRUCK
};

class Vehicle
{
private:
    string licensePlate;
    VehicleType type;

public:
    Vehicle(VehicleType vehicleType, string license)
    {
        type = vehicleType;
        licensePlate = license;
    }

    string getLicensePlate()
    {
        return licensePlate;
    }

    VehicleType getType()
    {
        return type;
    }
};

class Car : public Vehicle
{
public:
    Car(string licensePlate) : Vehicle(CAR, licensePlate) {}
};

class Bike : public Vehicle
{
public:
    Bike(string licensePlate) : Vehicle(BIKE, licensePlate) {}
};

class Spot
{
private:
    int id;
    VehicleType vehicleType;
    Vehicle *parkedVehicle;

public:
    Spot(int spot, VehicleType type)
    {
        id = spot;
        vehicleType = type;
        parkedVehicle = nullptr;
    }

    bool isAvailable()
    {
        return parkedVehicle == nullptr;
    }

    bool parkVehicle(Vehicle *vehicle)
    {
        if (!isAvailable())
        {
            return false;
        }

        if (vehicle->getType() != vehicleType)
        {
            return false;
        }

        parkedVehicle = vehicle;

        return true;
    }

    bool unparkVehicle()
    {
        if (isAvailable())
        {
            return false;
        }

        parkedVehicle = nullptr;

        return true;
    }

    VehicleType getVehicleType()
    {
        return vehicleType;
    }

    Vehicle *getParkedVehicle()
    {
        return parkedVehicle;
    }

    int getSpotId()
    {
        return id;
    }
};

class Level
{
private:
    int level;
    vector<Spot *> spots;

public:
    Level(int levelNum, int spotCount)
    {
        level = levelNum;
        spots = vector<Spot *>(spotCount);

        int bikeCount = spotCount / 2;
        int carCount = spotCount - bikeCount;

        for (int i = 1; i <= bikeCount; i++)
        {
            spots[i - 1] = new Spot(i, BIKE);
        }

        for (int i = bikeCount + 1; i <= spotCount; i++)
        {
            spots[i - 1] = new Spot(i, CAR);
        }
    }

    bool parkVehicle(Vehicle *vehicle)
    {
        for (Spot *spot : spots)
        {
            if (spot->parkVehicle(vehicle))
            {
                return true;
            }
        }

        return false;
    }

    bool unparkVehicle(Vehicle *vehicle)
    {
        for (Spot *spot : spots)
        {
            if (spot->getParkedVehicle() == vehicle)
            {
                return spot->unparkVehicle();
            }
        }

        return false;
    }

    int getLevel()
    {
        return level;
    }
};

class ParkingLot
{
private:
    static ParkingLot *instance;
    static mutex mtx;

    vector<Level *> levels;

    ParkingLot()
    {
        levels = vector<Level *>();
    }

    ParkingLot(const ParkingLot &) = delete;
    ParkingLot &operator=(const ParkingLot &) = delete;

public:
    static ParkingLot *getInstance()
    {
        if (instance == nullptr)
        {
            lock_guard<mutex> lock(mtx);
            if (instance == nullptr)
            {
                instance = new ParkingLot();
            }
        }

        return instance;
    }

    void addLevel(int spotCount)
    {
        int levelCount = getLevelCount() + 1;
        levels.push_back(new Level(levelCount, spotCount));
    }

    int getLevelCount()
    {
        return levels.size();
    }

    bool parkVehicle(Vehicle *vehicle)
    {
        for (Level *level : levels)
        {
            if (level->parkVehicle(vehicle))
            {
                return true;
            }
        }

        return false;
    }

    bool unparkVehicle(Vehicle *vehicle)
    {
        for (Level *level : levels)
        {
            if (level->unparkVehicle(vehicle))
            {
                return true;
            }
        }

        return false;
    }
};

ParkingLot *ParkingLot::instance = nullptr;
mutex ParkingLot::mtx;

int main()
{
    ParkingLot *lot = ParkingLot::getInstance();
    lot->addLevel(100);
    lot->addLevel(100);

    Vehicle *car = new Car("ABC");
    Vehicle *bike = new Bike("XYZ");

    cout << lot->parkVehicle(car) << endl;
    cout << lot->parkVehicle(bike) << endl;

    cout << lot->unparkVehicle(car) << endl;
    cout << lot->unparkVehicle(bike) << endl;
}

/*

Design pattern
- Singleton: Only one instance of parking lot can be created

Entities
- VehicleType
- Vehicle
- Spot
- Level
- ParkingLot

Inheritance
- Car is  Vehicle
- Bike is Vehicle

Relations:
- Spot has vehicle type
- Spot has vehicle
- Level has spot
- ParkingLot has level

*/
