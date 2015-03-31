/**
 * Alarm Clock: A simple clock where it plays a sound
 * after X number of minutes/seconds or at a particular time.
 */

#include <iostream>
#include <string>
#include <cstdlib>

#ifdef __WIN32__
#include <windows.h>
#else
#include <unistd.h>
#endif

void sleep(int seconds) {
	#ifdef __WIN32__
		Sleep(seconds);
	#else
		usleep(static_cast<useconds_t>(seconds)*1000); //or use nanosleep on platforms where it's needed
	#endif
};

class AlarmClock {
private:
	int seconds;
public:
	void enterAlarm() {
        std::string h_str, m_str, s_str;
        int h, m, s;

		std::cout << "Enter hours: ";
		std::getline(std::cin, h_str);
		h = atoi(h_str.c_str());

		std::cout << "Enter minutes: ";
		std::getline(std::cin, m_str);
		m = atoi(m_str.c_str());

		std::cout << "Enter seconds: ";
		std::getline(std::cin, s_str);
		s = atoi(s_str.c_str());

        std::cout << "\n";

        seconds = (h * 3600) + (m * 60) + s;
	};

	void wait() {
		sleep(seconds);
		for (unsigned int repeat = 0; repeat < 5; repeat++) {
			std::cout << '\a'; // beep character
		}
        std::cout << "Timer ended.\n";
	};

	int main() {
		while (true) {
			enterAlarm();
            wait();
		}

		return 0;
	};
};

int main() {
	AlarmClock alarm;
	alarm.main();

	return 0;
};
