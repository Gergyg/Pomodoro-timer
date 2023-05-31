#ifndef GLOBALS_H
#define GLOBALS_H

#include "Logic/authentication.h"
#include "Logic/user.h"
#include "Logic/activity.h"
#include "Logic/pomodorotimer.h"

extern Authentication* auth;
extern User* user;
extern Activity* activity;
extern PomodoroTimer* pomodoro;
extern bool activityChosen;
extern bool pomodoroChosen;
extern bool isLogged;

#endif // GLOBALS_H
