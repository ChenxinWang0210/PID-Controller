#ifndef PID_H
#define PID_H

#include <vector>

// #include <math.h>

using namespace std;

class PID {
public:
  /*
  * Errors
  */
  double p_error;
  double i_error;
  double d_error;

  /*
  * Coefficients
  */ 
  double Kp;
  double Ki;
  double Kd;
  
  
  
  /*
  * step index
  */
  
  int step_index;
  
  
  /* 
  // Define parameters for twiddle
  bool runTwiddle;
  int NoOfStepsTwiddle;
  double err;
  double best_err;
  bool is_first_attempt;
  bool is_second_attempt;
  double dp_sum;
  std::vector<double> dp;
  std::vector<double> p;
  int p_index;
  
  */
  

  /*
  * Constructor
  */
  PID();

  /*
  * Destructor.
  */
  virtual ~PID();

  /*
  * Initialize PID.
  */
  void Init(double Kp, double Ki, double Kd);
  
  /*
  * PID parameter vector
  */

  /*
  * Update the PID error variables given cross track error.
  */
  void UpdateError(double cte);

  /*
  * Calculate the total PID error.
  */
  double TotalError();
  
};

#endif /* PID_H */
