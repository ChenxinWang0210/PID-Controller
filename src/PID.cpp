#include "PID.h"

using namespace std;

/*
* TODO: Complete the PID class.
*/

PID::PID() {}

PID::~PID() {}

void PID::Init(double Kp, double Ki, double Kd) {
  this->Kp =Kp;
  this->Ki =Ki;
  this->Kd =Kd;
  
  i_error = 0.0 ;
  
  /* Initialize parameters for twiddle
  p = {Kp,Ki,Kd};
  p_index = 0;
  dp = {0.25, 0.001, 0.75};
  */
  
  
  
  
}

void PID::UpdateError(double cte) {
  
  double prev_cte = p_error;
  
  p_error = cte;
  
  d_error = cte - prev_cte;
  
  i_error +=cte;
  
  
}

double PID::TotalError() {
  
  return -Kp * p_error - Kd * d_error-Ki * i_error;
  
}

