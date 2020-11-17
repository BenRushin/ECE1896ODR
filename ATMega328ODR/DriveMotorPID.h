#ifndef PID_M_H_
#define PID_M_H_
#include <Arduino.h>
#include <Adafruit_MCP23017.h>

#define KP 1
#define KI 0.1
#define KD 0
typedef double (* encoderSpeed)();
class DriveMotorPID{
	public:
		DriveMotorPID(uint8_t pwm_p, uint8_t mcp_p1, uint8_t mcp_p2, bool CW_i_f, encoderSpeed es, Adafruit_MCP23017 mcp_c);
    void init();
		void update();
		void setVelocity(double velocity);
		void setBrakes(bool brake);
	private:
		void setDirection(bool forward);
		encoderSpeed getSpeed;
		Adafruit_MCP23017 mcp;
		bool clock_wise;
		bool CW_is_forward;
		bool braking;
    bool forward_previous;
    bool waited;
		uint8_t pwm_pin;
		uint8_t mcp_pin_c1;
		uint8_t mcp_pin_c2;
		unsigned long previous_time;
		double error;
		double last_error;
		double cumulative_error;
		double set_speed;
		static constexpr double kp=1.8;
		static constexpr double ki=0;//.1;
		static constexpr double kd=0;
};
#endif
