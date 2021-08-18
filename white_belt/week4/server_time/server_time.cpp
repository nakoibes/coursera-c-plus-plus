//
// Created by nakoibes on 14.08.2021.
//

//
// Created by nakoibes on 14.08.2021.
//


#include<iostream>
#include <numeric>
#include <fstream>
#include <sstream>
#include <set>
#include <vector>
#include <map>

using namespace std;

class TimeServer {
public:
    string GetCurrentTime(){
        try{
            last_fetched_time = AskTimeServer();
            return last_fetched_time;
        }
        catch (system_error &ex)
        {
            return last_fetched_time;
        }
    }
private:
    string last_fetched_time = "00:00:00";
};

int main() {

    return 0;
}