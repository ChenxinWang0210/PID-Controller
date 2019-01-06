# CarND-Controls-PID
Self-Driving Car Engineer Nanodegree Program

## Overview

The goal of this project is to implement a PID controller to  safely drive a car in a [simulator](https://github.com/udacity/self-driving-car-sim/releases) provided by Udacity . 
The simulator sends cross-track error, speed, and steering angle to the PID controller via [uWebSockets](https://github.com/uNetworking/uWebSockets), and the PID controller sends the steer and throttle value to the simulator to safely drive the car.

## Project Reflection
* Describe the effect of the P, I, D component of the PID algorithm in the implementation
  1. P Controller
		* Short for Proportional
        * The P Controller tries to steer the car back to the lane center proportionally to the off-center distance (or cross-track error). 
        * 
        
        ![](P_Controller.gif)


  2. I Controller


  3. D Controller


* Discuss how the final hyperparameters (P, I, D coefficients) were chosen