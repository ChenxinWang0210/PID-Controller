# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

## Overview

The goal of this project is to implement a PID controller to  safely drive a car in a [simulator](https://github.com/udacity/self-driving-car-sim/releases) provided by Udacity . 
The simulator sends cross-track error, speed, and steering angle to the PID controller via [uWebSockets](https://github.com/uNetworking/uWebSockets), and the PID controller sends the steer and throttle value to the simulator to safely drive the car.

## Project Reflection
* Describe the effect of the P, I, D component of the PID algorithm in the implementation
  1. P Controller
		* Short for Proportional
        * The P Controller tries to steer the car back to the lane center proportionally to the off-center distance (or cross-track error)
        * The car may overshoot the lane center under only P control, as shown below
        
        ![](P_Controller.gif)


  2. I Controller
       * Short for Intergal 
       * Combat a possible bias that prevents the car from reaching the lane center.  However, bias is not an issue for the current case. The I coefficient is close or equal to zero.

  3. D Controller
       * Short for Differential
       * Combat the P controller's tendency to overshoot the lane center. A proper D coefficient makes the car move toward the lane center smoothly.


* Discuss how the final hyperparameters (P, I, D coefficients) were chosen

I first tried the PID parameters (0.2,0.004,3.0), which I took from the [Udacity classroom](https://classroom.udacity.com/nanodegrees/nd013/parts/30260907-68c1-4f24-b793-89c0c2a0ad32/modules/3e2b027e-1822-4638-a58a-def1e64258a8/lessons/48c5e9c4-f72b-4c7c-8375-ea4eda220e39/concepts/d9a5a2bc-2884-4806-a0d4-b7926bf229be). The car safely drove around the  track. Then I used these parameters to initialize twiddle. However, it took long time for the twiddle algorithm to converge. I gave up twiddle and started to tune the parameter manually. 

I tuned the P coefficient from 0.1 to 0.3, while holding the I and D coefficients as constants. For a low P coefficient, the car got off the track at curves. For a high P coefficient, the car oscillated around the lane center. I chose the P coefficient as 0.2.   I also manually tuned the I coefficient from 0 to 0.004, while holding the P and D coefficients as constants.  Because bias was not an issue, I did not try high I coefficient.  The low I coefficient had very little effects on the car's performance.  I chose the I coefficient as 0.002.  I also manually tuned the D coefficient from 2.0 to 4.0, while holding the P and I coefficients as constants. The car went through the whole track safely with each of the D coefficient. I then increased the D coefficient to 50.0. The car kept to the lane center, but moved slowly. When I decreased the D coefficient to 0, the car oscillated off the track.  I eventually chose the D coefficient as 3.5. 

I related the throttle value to the steer value. When the steer value (absolute value) is high, the throttle value is low. It helps steering at curves.  Here is the implementation.

```
throttle_value = (1-fabs(steer_value))*0.25 +0.1;
```

Here is a video of car driving around the track (not whole track) for the parameters (0.2,0.002,3.5).

![](PID_Video.gif)


