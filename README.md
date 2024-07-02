# Rotary Inverted Pendulum (Furuta Pendulum)

This project aims to design and implement a control system for a Furuta Pendulum, also known as a Rotary Pendulum. The control system utilizes the LQR (Linear Quadratic Regulator) technique to control the pendulum's angle and maintain it in an upright position, overcoming disturbances that may affect its stability.

## Project Objectives

The main objectives of this project are as follows:

1. Control theta1 to achieve a zero angle, ensuring the pendulum stands in the upright position.
2. Utilize the LQR technique to design a controller that can regulate the system's output according to the set control requirements.
3. Implement a control strategy to maintain the pendulum's stability in the presence of disturbances.

## System Components

To accomplish the project objectives, the following components are required:

1. Motor with Encoder: At least one motor equipped with an encoder should be used to control theta0, the base rotation angle of the pendulum.
2. Encoder for Theta1: An encoder with at least 360 pulses per revolution should be used to measure the angle theta1, the pendulum arm angle.
3. MATLAB/Simulink: The control system design and implementation should be done using MATLAB/Simulink.
4. Hardware-in-the-Loop (HIL): The control system should be validated using the Hardware-in-the-Loop technique, where the physical system is connected to the Simulink model.

## System Design Considerations

The following considerations should be taken into account during the design and implementation of the control system:

1. Motor and Encoder Setup: Properly configure the motor and encoder to accurately measure and control the angles theta0 and theta1. Ensure that the motor and encoder are connected correctly and provide the necessary feedback for control.
2. LQR Controller Design: Utilize the LQR technique to design a controller that can effectively regulate the system's output. Consider the desired control requirements and tune the LQR controller parameters accordingly.
3. Disturbance Rejection: Implement a control strategy that can handle disturbances affecting the pendulum's stability. The control system should be robust and capable of maintaining the upright position of the pendulum even in the presence of external disturbances.
4. Wiring and Component Placement: Hide the wires as much as possible to ensure a clean and organized setup. Fix all the components securely to minimize any unwanted movement or vibrations during operation.
5. Platform Selection: Choose a suitable platform from the available options provided in Figure 2. The selected platform should be compatible with MATLAB/Simulink for control system development and HIL implementation.

## System Implementation

Follow these steps to implement the control system:

1. Model Development: Build a dynamic model of the Furuta Pendulum in MATLAB/Simulink. Consider the physical properties and dynamics of the pendulum to create an accurate model.
2. LQR Controller Design: Design an LQR controller using MATLAB/Simulink based on the dynamic model. Tune the controller parameters to achieve the desired control objectives.
3. Control System Validation: Validate the control system using the Hardware-in-the-Loop (HIL) technique. Connect the physical system to the Simulink model and verify the controller's performance in real-time.
4. Performance Evaluation: Evaluate the control system's performance by analyzing the pendulum's stability, disturbance rejection capability, and ability to maintain an upright position.
5. Iterative Improvement: If necessary, refine the control system by adjusting the controller parameters or modifying the control strategy. Iterate the design and validation process until the control system meets the desired performance criteria.

## Conclusion

The Furuta Pendulum Control System project aims to design and implement a control strategy for a Rotary Pendulum. By utilizing the LQR technique and HIL methodology, the control system is expected to maintain the pendulum's upright position, regulate its angles, and overcome disturbances. The project documentation will provide a comprehensive overview of the system design, implementation, and validation, along with experimental results and recommendations for future enhancements.
