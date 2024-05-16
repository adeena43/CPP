#include <iostream>
#include <cmath>
#include <cstdlib> 
using namespace std;

class Drone {
protected:
    float latitude, longitude, altitude, speed;
public:
    Drone(float lat, float lon, float alt, float spd) : latitude(lat), longitude(lon), altitude(alt), speed(spd) {}

    float adjustAltitude(float alt) {
        altitude = alt;
        return altitude;
    }

    float setSpeed(float spd) {
        speed = spd;
        return speed;
    }
};

class Flyable {
public:
    virtual void takeoff() = 0;
    virtual void land() = 0;
    virtual void navigateTo(float latitude, float longitude, float altitude) = 0;
};

class Scannable {
public:
    virtual void scanArea(float radius) = 0;
};

class ReconDrone : public Drone, public Flyable, public Scannable {
    float cameraResolution, maxFlightTime;
public:
    ReconDrone(float lat, float lon, float alt, float spd, float camRes, float maxTime)
        : Drone(lat, lon, alt, spd), cameraResolution(camRes), maxFlightTime(maxTime) {}

    void takeoff() override {
        cout << "Taking off..." << endl;
    }

    void land() override {
        cout << "Landing..." << endl;
    }

    void navigateTo(float lat, float lon, float alt) override {
        float deltaX = (lat - longitude) * cos((latitude + lat) / 2);
        float deltaY = lat - latitude;
        float distance = sqrt(deltaX * deltaX + deltaY * deltaY) * 111.0f; 
        float time = distance / speed;

        cout << "Estimated time to destination: " << time << " hours" << endl;

        latitude = lat;
        longitude = lon;
        altitude = alt;
    }

    void scanArea(float radius) override {
      
        int objectsDetected = rand() % 10; 
        cout << "Detected " << objectsDetected << " objects:" << endl;

        for (int i = 0; i < objectsDetected; ++i) {
            float objectLat = latitude + static_cast<float>(rand() % 100) / 1000.0f;
            float objectLon = longitude + static_cast<float>(rand() % 100) / 1000.0f;
            cout << "Object " << i + 1 << " at (" << objectLat << ", " << objectLon << ")" << endl;
        }
    }
};

int main() {
	cout<<"Adina Faraz"<<endl<<"23k-0008"<<endl;
    ReconDrone drone(0, 0, 100, 50, 4, 8);
    drone.takeoff();
    drone.navigateTo(1, 1, 150);
    drone.scanArea(500);
    drone.land();

    return 0;
}
