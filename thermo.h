/*
 * Copyright Eugenio Tampieri 2021
 * This software is released under the MIT License, whose text you can find below.
 */

typedef struct thermostat {
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

void report_temperature(float t);
void report_humidity(float rh);
void set_temperature(float t);
void set_humidity(float rh);

