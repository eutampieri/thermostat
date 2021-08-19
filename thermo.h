/*
 * Copyright Eugenio Tampieri 2021
 * This software is released under the MIT License, whose text you can find below.
 */

#ifndef TST_THERMO
#define TST_THERMO
typedef struct thermostat
{
	float current_temperature;
	float current_humidity;
	float target_temperature;
	float target_humidity;
	void *dehumidifier_on;
	void *dehumidifier_off;
	void *heat_on;
	void *heat_off;
	void *ac_on;
	void *ac_off;
} thermostat_t;

thermostat_t tst_init();

void tst_report_temperature(float t);
void tst_report_humidity(float rh);
void tst_set_temperature(float t);
void tst_set_humidity(float rh);
#endif
