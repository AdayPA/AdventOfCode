#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Reindeer {
    string name;
    int speed;
    int flyTime;
    int restTime;
};

int calculateDistanceAfterSeconds(const Reindeer& reindeer, int totalTime) {
    int distance = 0;
    int flyingTimeLeft = reindeer.flyTime;
    int restingTimeLeft = 0;

    for (int t = 1; t <= totalTime; ++t) {
        if (flyingTimeLeft > 0) {
            distance += reindeer.speed;
            flyingTimeLeft--;
            if (flyingTimeLeft == 0) {
                restingTimeLeft = reindeer.restTime;
            }
        } else if (restingTimeLeft > 0) {
            restingTimeLeft--;
            if (restingTimeLeft == 0) {
                flyingTimeLeft = reindeer.flyTime;
            }
        }
    }

    return distance;
}

int calculatePoints(const vector<Reindeer>& reindeers, int totalTime) {
    vector<int> points(reindeers.size(), 0);

    for (int t = 1; t <= totalTime; ++t) {
        int maxDistance = 0;
        for (const auto& reindeer : reindeers) {
            int distance = calculateDistanceAfterSeconds(reindeer, t);
            maxDistance = max(maxDistance, distance);
        }
        for (int i = 0; i < reindeers.size(); ++i) {
            if (calculateDistanceAfterSeconds(reindeers[i], t) == maxDistance) {
                points[i]++;
            }
        }
    }

    return *max_element(points.begin(), points.end());
}

int main() {
    vector<Reindeer> reindeers = {
        {"Dancer", 27, 5, 132},
        {"Cupid", 22, 2, 41},
        {"Rudolph", 11, 5, 48},
        {"Donner", 28, 5, 134},
        {"Dasher", 4, 16, 55},
        {"Blitzen", 14, 3, 38},
        {"Prancer", 3, 21, 40},
        {"Comet", 18, 6, 103},
        {"Vixen", 18, 5, 84}
    };

    const int totalTime = 2503;
    int points = calculatePoints(reindeers, totalTime);

    cout << "El número de puntos acumulados por el reno ganador después de 2503 segundos es: " << points << endl;

    return 0;
}
