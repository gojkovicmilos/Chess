#ifndef UTIL_H_INCLUDED
#define UTIL_H_INCLUDED

#include <cmath>

using namespace std;

enum MoveStates {idleState, leftState, rightState, upState, downState, leftUpState, rightUpState, leftDownState, rigthDownState, stopState, moveToPointState, jumpState, followState};
constexpr double pi = atan(1)*4;

#endif // UTIL_H_INCLUDED
