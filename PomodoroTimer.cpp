#include "PomodoroTimer.h"
#include <chrono>
#include <thread>

Statistics* Statistics::instance = nullptr;


PomodoroTimer::PomodoroTimer(int workTime, int shortBreakTime, int longBreakTime, int rounds, int roundsForLongBreak, string activity) : 
    workTime(workTime), 
    shortBreakTime(shortBreakTime),
    longBreakTime(longBreakTime),
    rounds(rounds),
    roundsForLongBreak(roundsForLongBreak),
    activity(activity) {}

void PomodoroTimer::setWorkTime(int time){
    workTime = time;
}

void PomodoroTimer::setShortBreakTime(int time){
    shortBreakTime = time;
}

void PomodoroTimer::setLongBreakTime(int time){
    longBreakTime = time;
}

void PomodoroTimer::setRounds(int count){
    rounds = count;
}

void PomodoroTimer::setRoundsForLongBreak(int count){
    roundsForLongBreak = count;
}

int PomodoroTimer::getWorkTime(){
    return workTime;
}

int PomodoroTimer::getShortBreakTime(){
    return shortBreakTime;
}

int PomodoroTimer::getLongBreakTime(){
    return longBreakTime;
}

int PomodoroTimer::getRounds(){
    return rounds;
}

int PomodoroTimer::getRoundsForLongBreak(){
    return roundsForLongBreak;
}

bool ending = false;
void waitForSpace() {
    while (true) {
        if (std::cin.get() == ' ') {
            break;
        }
        if(std::cin.get() == 'z'){
            ending = true;
            break;
        }
    }
}

void timer(int duration) {
    auto start_time = std::chrono::steady_clock::now();
    auto end_time = start_time + std::chrono::seconds(duration);
    while (std::chrono::steady_clock::now() < end_time) {
        ending = false;
        if (std::cin.peek() == ' ') {
            std::cin.ignore();
            auto paused_time = std::chrono::steady_clock::now();
            waitForSpace();
            end_time += std::chrono::steady_clock::now() - paused_time;
            start_time = std::chrono::steady_clock::now();
        }
        if(ending) break;
        auto remaining_time = std::chrono::duration_cast<std::chrono::seconds>(end_time - std::chrono::steady_clock::now()).count();
        std::cout << "\rTime remaining: " << remaining_time << " seconds        ";
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    std::cout << "\nTimer finished!" << std::endl;
}

void PomodoroTimer::startTimer(){
    int completedRounds = 0;

    while(completedRounds < rounds){
        std::cout << "Started work time!\n";
        timer(workTime);
        if(ending) break;
        completedRounds++;
        Statistics::getInstance()->updateCompletedPomodoros(activity);
        Statistics::getInstance()->updateWorkedTime(activity, workTime);

        std::cout << "Started rest time!\n";
        int rTime;
        rTime = completedRounds % roundsForLongBreak == 0 ? longBreakTime : shortBreakTime;
        if(completedRounds % roundsForLongBreak == 0) std::cout << "Long break!\n";
        
        timer(rTime);
        if(ending) break;
        Statistics::getInstance()->updateRestTime(activity, rTime);
    }

}
