/*
 * Copyright Eugenio Tampieri 2021
 * This software is released under the MIT License, whose text you can find below.
 */
#include <inttypes.h>

#ifndef TST_THERMO
#define TST_THERMO

#define TST_ALPHA = 0.25
#define TST_HEATING = 0b00000001
#define TST_COOLING = 0b00000010
#define TST_HUMIDIFYING = 0b00000100
typedef struct thermostat
{
	float current_temperature;
	float current_humidity;
	float target_temperature;
	float target_humidity;
	float avg_cooling_rate;
	float avg_heating_rate;
	float avg_ambient_delta_t_rate;
	float avg_humidifying_rate;
	float avg_dehumidifying_rate;
	uint64_t time_last_temp;
	uint64_t time_last_hum;
	void *dehumidifier_on;
	void *dehumidifier_off;
	void *heat_on;
	void *heat_off;
	void *ac_on;
	void *ac_off;
	uint8_t enabled;
	uint8_t status;
} thermostat_t;

thermostat_t tst_init(void *dehumidifier_on,
					  void *dehumidifier_off,
					  void *heat_on,
					  void *heat_off,
					  void *ac_on,
					  void *ac_off);

void tst_report_temperature(thermostat_t *th, float t);
void tst_report_humidity(thermostat_t *t, float rh);
void tst_set_temperature(thermostat_t *th, float t);
void tst_set_humidity(thermostat_t *t, float rh);
void tst_evaluate(thermostat_t *t);
void tst_enable(thermostat_t *t);
void tst_disable(thermostat_t *t);
#endif
