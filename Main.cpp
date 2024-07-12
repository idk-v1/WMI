// Example for getting battery charge

#include "WMI.hpp"

int main()
{
	WMI wmi;
	if (wmi.init() && wmi.connect(L"ROOT\\WMI"))
	{
		while (true)
		{
			unsigned int batteryCapacity = wmi.query(
				L"FullChargedCapacity",
				L"BatteryFullChargedCapacity").ulVal;
			unsigned int batteryCharge = wmi.query(
				L"RemainingCapacity",
				L"BatteryStatus").ulVal;
			float percent = batteryCharge * 100.f / batteryCapacity;

			printf("Battery Charge: %d/%d (%.2f%%)\n",
				batteryCharge, batteryCapacity, percent);

			Sleep(1000);
		}

		return 0;
	}
	else
	{
		printf("Failed to connect to WMI\n");
		return 1;
	}
}