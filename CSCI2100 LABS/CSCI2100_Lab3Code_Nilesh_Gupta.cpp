#include <iostream>
using namespace std;

class TravelLog {
  public:
    /** initialize a new (empty) log.  */
    TravelLog() : totalMiles(0), previousTime(0) {}
    /** Add a new entry to the log.
       *  @param   speed      current speed in miles per hour
       *  @param   clockTime  elapsed time since beginning of trip (in hours)
       */
    void addEntry(int speed, int clockTime) {
      /** Returns the total number of miles traveled.
         *  @return number of miles
         */
        if (previousTime == 0) {
            totalMiles += clockTime * speed;
            //cout << "You travelled: " << speed << " mph for " << clockTime << " hours. Total miles travelled: " << totalMiles << endl;
        } else {
            int timeSpent = clockTime - previousTime;
            totalMiles += timeSpent * speed;
            //cout << "You travelled: " << speed << " mph for " << timeSpent << " hours. Total miles travelled: " << totalMiles << endl;
        }
        previousTime = clockTime;
    }
    int getTotalMiles() const { 
        return totalMiles;
    }
  private:
    //  ??? state information ???
    int totalMiles;
    int previousTime;
};
int main() {
    while (true) {
        int x;
        cin >> x;

        if (x == -1) {
            break;
        }
        
        TravelLog trip;
      
        for (int i = 0; i < x; i++) {
            int speed, time;
            cin >> speed >> time;
            trip.addEntry(speed, time);
        }
        cout << "Total distance for this trip: " << trip.getTotalMiles() << " miles" << endl;
    }
    return 0;
}
